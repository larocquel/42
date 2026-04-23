#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node	*parse_add(char **s);

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

// 3 casos
node	*parse_number(char **s)
{
	node	*n = NULL;
	node	temp;

	// Caso 1: Parenteses
	if (accept(s, '('))
	{
		// 1. Começa a preencher o valor dentro da expressao
		n = parse_add(s);
		if (!n)
			return (NULL);

		// 2. Tem que fechar
		if (!expect(s, ')'))
		{
			destroy_tree(n);
			return (NULL);
		}

		// 3. Sucesso
		return (n);
	}

	// Caso 2: Digito
	if (isdigit(**s))
	{
		// 1. Node temporario
		temp.type = VAL;
		temp.val = **s - '0';
		temp.l = NULL;
		temp.r = NULL;

		// 2. Consumir o digit
		(*s)++;

		// 3. n recebe temp
		n = new_node(temp);

		// 4. Sucesso
		return (n);
	}

	// Caso 3: Erro char inesperado
	unexpected(**s);
	return (NULL);
}

node	*parse_multi(char **s)
{
	node	*left;
	node	*right;
	node	temp;
	node	*new_left;

	// 1. Preencher o primeiro valor - ESQUERDA
	left = parse_number(s);
	if (!left)
		return (NULL);

	// 2. Enquanto houver * multiplicar
	while (accept(s, '*'))
	{
		// 3. Prox valor - DIREITA
		right = parse_number(s);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}

		// 4. Node temporario
		temp.type = MULTI;
		temp.l = left;
		temp.r = right;

		// 5. Escudo new_left contra falha do calloc do new_node
		new_left = new_node(temp);

		if (!new_left)
		{
			destroy_tree(left);
			destroy_tree(right);
			return (NULL);
		}

		// 6. left recebe new_left
		left = new_left;
	}

	// 7. Sucesso
	return (left);
}

node	*parse_add(char **s)
{
	node	*left;
	node	*right;
	node	temp;
	node	*new_left;

	// 1. Preencher o primeiro valor - ESQUERDA
	left = parse_multi(s);
	if (!left)
		return (NULL);

	// 2. Enquanto houver + somar
	while (accept(s, '+'))
	{
		// 3. Prox valor - DIREITA
		right = parse_multi(s);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}

		// 4. Node temporario
		temp.type = ADD;
		temp.l = left;
		temp.r = right;

		// 5. Escudo new_left contra falha do calloc do new_node
		new_left = new_node(temp);

		if (!new_left)
		{
			destroy_tree(left);
			destroy_tree(right);
			return (NULL);
		}

		// 6. left recebe new_left
		left = new_left;
	}

	// 7. Sucesso
	return (left);
}

node    *parse_expr(char *s)
{
	// 1. Começar a engrenagem pelo parse add passar o endereço, tudo isso ao node ret
	node	*ret = parse_add(&s);
	if (!ret)
		return (NULL);

	// 2. Adicionar o inesperado para checar se ha algum char dps de ter construido a AST
    if (*s)
    {
		unexpected(*s);
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
	return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
	return (0);
}
