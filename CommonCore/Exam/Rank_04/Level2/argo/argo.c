#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct json {
    enum {
        MAP,
        INTEGER,
        STRING
    } type;
    union {
        struct {
            struct pair *data;
            size_t      size;
        } map;
        int integer;
        char    *string;
    };
} json;

typedef struct pair {
    char    *key;
    json    value;
} pair;

// 1. Protótipos das nossas funções auxiliares e principais
void free_json(json j);
int argo(json *dst, FILE *stream);
int parse_string(json *dst, FILE *stream);
int parse_integer(json *dst, FILE *stream);
int parse_map(json *dst, FILE *stream);

int peek(FILE *stream)
{
    int c = getc(stream);
    ungetc(c, stream);
    return c;
}

void unexpected(FILE *stream)
{
    if (peek(stream) != EOF)
        printf("unexpected token '%c'\n", peek(stream));
    else
        printf("unexpected end of input\n");
}

int accept(FILE *stream, char c)
{
    if (peek(stream) == c)
    {
        (void)getc(stream);
        return 1;
    }
    return 0;
}

int expect(FILE *stream, char c)
{
    if (accept(stream, c))
        return 1;
    unexpected(stream);
    return 0;
}

void free_json(json j)
{
    switch (j.type)
    {
        case MAP:
            for (size_t i = 0; i < j.map.size; i++)
            {
                free(j.map.data[i].key);
                free_json(j.map.data[i].value);
            }
            free(j.map.data);
            break;
        case STRING:
            free(j.string);
            break;
        default:
            break;
    }
}

void serialize(json j)
{
    switch (j.type)
    {
        case INTEGER:
            printf("%d", j.integer);
            break;
        case STRING:
            putchar('"');
            for (int i = 0; j.string[i]; i++)
            {
                if (j.string[i] == '\\' || j.string[i] == '"')
                    putchar('\\');
                putchar(j.string[i]);
            }
            putchar('"');
            break;
        case MAP:
            putchar('{');
            for (size_t i = 0; i < j.map.size; i++)
            {
                if (i != 0)
                    putchar(',');
                serialize((json){.type = STRING, .string = j.map.data[i].key});
                putchar(':');
                serialize(j.map.data[i].value);
            }
            putchar('}');
            break;
    }
}

int parse_integer(json *dst, FILE *stream)
{
    // 1. Definir o tipo do nó
    dst->type = INTEGER;

    // 2. Extrair o numero do stream usando %d (CORRIGIDO)
    if (fscanf(stream, "%d", &dst->integer) != 1)
    {
        unexpected(stream);
        return (-1);
    }

    // 3. Sucesso (CORRIGIDO)
    return (1);
}

int parse_string(json *dst, FILE *stream)
{
    int c;
    size_t len = 0;

    // 1. Inicializacao do dst com tipo STRING e malloc para string vazia
    dst->type = STRING;
    dst->string = malloc(1);
    if (!dst->string)
        return (-1);

    dst->string[0] = '\0';

    // 2. String no JSON comeca obrigatoriamente com aspas "
    if (!expect(stream, '"'))
    {
        free(dst->string);
        return (-1);
    }

    // 3. Loop infinito char a char
    while (1)
    {
        // 4. Pegar o char do stream
        c = getc(stream);

        // 5. Se o arquivo acabar antes de fechar as aspas
        if (c == EOF)
        {
            free(dst->string);
            unexpected(stream);
            return (-1);
        }

        // 6. Se tiver outra aspa dupla ", a string acabou com sucesso
        if (c == '"')
            break;

        // 7. Regra do Escape - lidar APENAS com \\ e \"
        if (c == '\\')
        {
            c = getc(stream);
            if (c != '"' && c != '\\')
            {
                free(dst->string);
                ungetc(c, stream); // Devolve o char invalido para o unexpected ler
                unexpected(stream);
                return (-1);
            }
        }

        // 8. Aumentamos a string dinamicamente (+2: um para o novo char, outro para o \0)
        char *tmp = realloc(dst->string, len + 2);
        if (!tmp)
        {
            free(dst->string);
            return (-1);
        }
        dst->string = tmp;
        dst->string[len] = (char)c;
        len++;
        dst->string[len] = '\0';
    }
    return (1);
}

int parse_map(json *dst, FILE *stream)
{
    // 1. Inicializa a estrutura do mapa como vazia
    dst->type = MAP;
    dst->map.size = 0;
    dst->map.data = NULL;

    // 2. Mapa sempre comeca com { em JSON
    if (!expect(stream, '{'))
        return (-1);

    // 3. Verifica se e um mapa vazio '{}'
    if (accept(stream, '}'))
        return (1);

    // 4. Loop infinito para ler pares chave:valor
    while (1)
    {
        // 5. Parse da chave: no JSON, a chave é sempre uma STRING
        json key_obj;
        if (parse_string(&key_obj, stream) != 1)
            return (-1);

        // 6. Guardamos o ponteiro da string da chave
        char *key_str = key_obj.string;

        // 7. Após a chave, deve ter os dois pontos ':'
        if (!expect(stream, ':'))
        {
            free(key_str);
            return (-1);
        }

        // 8. Recursao: o valor pode ser mapa, string ou numero. Chamamos o argo()
        json value_obj;
        if (argo(&value_obj, stream) != 1)
        {
            free(key_str);
            return (-1);
        }

        // 9. Alocamos espaco para o nosso array de dados com realloc (CORRIGIDO)
        struct pair *tmp = realloc(dst->map.data, (dst->map.size + 1) * sizeof(struct pair));
        if (!tmp)
        {
            free(key_str);
            free_json(value_obj);
            return (-1);
        }

        // 10. Salva os dados e incrementa o tamanho do mapa
        dst->map.data = tmp;
        dst->map.data[dst->map.size].key = key_str;
        dst->map.data[dst->map.size].value = value_obj;
        dst->map.size++;

        // 11. Depois do valor, pode vir uma ',' (novo par) ou '}' (fim do mapa)
        if (accept(stream, ','))
            continue;
        else if (accept(stream, '}'))
            break;
        else
        {
            unexpected(stream);
            return (-1);
        }
    }
    return (1);
}

int argo(json *dst, FILE *stream)
{
    // 1. Espiar com peek
    int c = peek(stream);

    // 2. O arquivo chegou ao fim?
    if (c == EOF)
    {
        unexpected(stream);
        return (-1);
    }

    // Caso 1: Map (Começa com {)
    if (c == '{')
        return (parse_map(dst, stream));

    // Caso 2: String (Começa com ")
    if (c == '"')
        return (parse_string(dst, stream)); // (CORRIGIDO)

    // Caso 3: Digito (Pode ser numero negativo)
    if (c == '-' || isdigit(c))
        return (parse_integer(dst, stream)); // (CORRIGIDO)

    // Caso 4: Erro (Espaços ou tokens inválidos)
    unexpected(stream);
    return (-1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    char *filename = argv[1];
    FILE *stream = fopen(filename, "r");
    json file;
    if (argo(&file, stream) != 1)
    {
        free_json(file);
        return 1;
    }
    serialize(file);
    printf("\n");
    return 0; // Boa prática na main
}