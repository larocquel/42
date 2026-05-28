*This project has been created as part of the 42 curriculum by leoaguia.*

<div align="center">
  <img src="https://github.com/larocquel/42/raw/394fa0989ebb0e1dccc37d129e0863130e7707de/1-Common_Core/Milestone_04/cpp/01/img/cpp01_banner.png" width="100%" />
</div>

---

<div align="center">

## *Gestão de Memória · Referências · File Streams · Ponteiros para Membros*

<br>

[![Score](https://img.shields.io/badge/Score-100%2F100-4CAF50?style=for-the-badge&logo=42&logoColor=white)](.)
[![Language](https://img.shields.io/badge/C%2B%2B-98-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](.)
[![School](https://img.shields.io/badge/42-Porto-000000?style=for-the-badge&logo=42&logoColor=white)](.)

</div>

---

## ⚒ Criador

<div align="center">
  <a href="https://github.com/larocquel">
    <img src="https://avatars.githubusercontent.com/larocquel?size=100" width="100">
  </a>
  <br><br>
  <b><a href="https://github.com/larocquel">Leonardo La Rocque</a></b>
</div>

## ⤷ Conteúdo

1. [Sobre](#sobre)
2. [Documentação](#documentação) 
3. [Compilação](#compilação)
4. [Exercícios](#exercícios)
5. [Estrutura](#estrutura)

# <a id="sobre"></a>Sobre

O **Módulo 01** marca a transição do C clássico para o paradigma orientado a objetos em C++. O foco central é a **gestão consciente de memória**: perceber quando e porquê usar a stack ou a heap, e quais as consequências de cada escolha. A isto somam-se três ferramentas fundamentais da linguagem:
- **Referências**
- **File streams**
- **Ponteiros para funções membro**

---

# <a id="documentação"></a>Documentação
<hr/>
<div align = "center">
<em >Dois documentos de estudo produzidos como complemento ao módulo</em>
<hr/>
</div>

<p align="center">
  <a href="https://github.com/larocquel/42/blob/394fa0989ebb0e1dccc37d129e0863130e7707de/1-Common_Core/Milestone_04/cpp/01/Cpp01_CompleteManual.pdf"><img src="https://github.com/larocquel/42/raw/3c33eac50f9ec491ef9e46b73ba8ff5f50f33f85/1-Common_Core/Milestone_04/cpp/01/img/guia_definitivo.png" width="40%"/></a>
  <a href="https://github.com/larocquel/42/blob/394fa0989ebb0e1dccc37d129e0863130e7707de/1-Common_Core/Milestone_04/cpp/01/Cpp01_CheatSheet.pdf"><img src="https://github.com/larocquel/42/raw/3c33eac50f9ec491ef9e46b73ba8ff5f50f33f85/1-Common_Core/Milestone_04/cpp/01/img/cheet_sheet.png" width="40%"/></a>
</p>

</td>
  </tr>
  <tr>
    <td>
<td width="50%" valign="top">

---

# <a id="compilação"></a>Compilação

Todos os exercícios seguem as normas da 42 e incluem um `Makefile` pronto a usar.

```bash
make        # Compila e gera o executável
make clean  # Remove ficheiros objeto (.o)
make fclean # Remove tudo (executável incluído)
make re     # Recompilação total (fclean + make)
```

---

# <a id="exercícios"></a>Exercícios

| nº | Exercício | Conceito-chave |
|---|-----------|----------------|
| [00](#-ex00--braiiiiiiinnnzzzz) | BraiiiiiiinnnzzzZ | Stack vs. Heap |
| [01](#-ex01--moar-brainz) | Moar brainz! | Arrays Dinâmicos |
| [02](#-ex02--hi-this-is-brain) | HI THIS IS BRAIN | Ponteiros vs. Referências |
| [03](#-ex03--unnecessary-violence) | Unnecessary violence | Composição de Classes |
| [04](#-ex04--sed-is-for-losers) | Sed is for losers | File Streams & Strings |
| [05](#-ex05--harl-20) | Harl 2.0 | Ponteiros para Membros |
| [06](#-ex06--harl-filter) | Harl Filter | `switch` & Fall-Through |

---


## ex00 | BraiiiiiiinnnzzzZ

### Conceito: Stack vs. Heap

A memória **stack** é alocada e destruída automaticamente quando a função sai de escopo — rápida, mas efémera. A memória **heap**, alocada com `new`, persiste até ser explicitamente libertada com `delete`. Não libertar memória na heap causa *memory leaks*.

```bash
cd ex00 && make && ./zombie
```

---

## ex01 | Moar brainz!

### Conceito: Arrays Dinâmicos na Heap

Como alocar um vetor contíguo de objetos com `new[]` e qual o operador correto para os destruir: `delete[]`. A distinção entre `delete` e `delete[]` é crítica — usar o errado causa comportamento indefinido.

```bash
cd ex01 && make && ./horde
```

---

## ex02 | HI THIS IS BRAIN

### Conceito: Ponteiros `*` vs. Referências `&`

Uma referência é um **alias permanente** para uma variável existente — não é uma variável independente, não pode ser nula, e não pode mudar o que referencia após a inicialização. Um ponteiro é uma variável separada que guarda um endereço e pode ser reatribuído ou ser `NULL`.

```bash
cd ex02 && make && ./brain
```

---

## ex03 | Unnecessary violence

### Conceito: Composição de Classes — Ponteiro ou Referência como Atributo?

A escolha depende da lógica de negócio:

| Usar **Referência** quando… | Usar **Ponteiro** quando… |
|---|---|
| O atributo é obrigatório e nunca muda | O atributo é opcional (pode ser `NULL`) |
| A relação é existencial | A relação pode ser reatribuída |

```bash
cd ex03 && make && ./violence
```

---

## ex04 | Sed is for losers

### Conceito: File Streams `<fstream>` e Manipulação de Strings

Lê um ficheiro com `std::ifstream`, substitui todas as ocorrências de `s1` por `s2` usando `.find()`, `.erase()` e `.insert()`, e escreve o resultado num novo ficheiro `<filename>.replace` com `std::ofstream`. A lógica inclui proteção contra loops infinitos quando `s2` contém `s1`.

```bash
cd ex04 && make
./losers <ficheiro> <s1> <s2>

# Exemplo:
./losers input.txt "olá" "adeus"
```

---

## ex05 | Harl 2.0

### Conceito: Ponteiros para Funções Membro

Elimina cascatas de `if/else if` com uma **dispatch table**: um array de ponteiros para métodos da classe com a sintaxe `void (Harl::*ptr[])(void)`. O método correto é invocado dinamicamente através de `(this->*ptr[i])()`, tornando o código extensível e livre de condicionais.

```bash
cd ex05 && make
./harlAKAkaren <LEVEL>

# Exemplo:
./harlAKAkaren DEBUG
```

Níveis disponíveis: `DEBUG` · `INFO` · `WARNING` · `ERROR`

---

## ex06 | Harl Filter

### Conceito: `switch` e *Fall-Through* intencional

Como `switch` em C++98 não aceita `std::string`, o nível é mapeado para um inteiro. O truque central é a omissão deliberada de `break` — o **fall-through** — que executa em cascata todos os níveis a partir do selecionado. O comentário `/* fall through */` é necessário para satisfazer o compilador rigoroso.

```bash
cd ex06 && make
./harlFilter <LEVEL>

# Exemplo (imprime WARNING, ERROR e tudo abaixo):
./harlFilter WARNING
```

Níveis disponíveis: `DEBUG` · `INFO` · `WARNING` · `ERROR`

---

# <a id="estrutura"></a>Estrutura

```
├── ex00
│   ├── main.cpp
│   ├── Makefile
│   ├── newZombie.cpp
│   ├── randomChump.cpp
│   ├── Zombie.cpp
│   └── Zombie.hpp
├── ex01
│   ├── main.cpp
│   ├── Makefile
│   ├── Zombie.cpp
│   ├── zombieHorde.cpp
│   └── Zombie.hpp
├── ex02
│   ├── main.cpp
│   └── Makefile
├── ex03
│   ├── HumanA.cpp
│   ├── HumanA.hpp
│   ├── HumanB.cpp
│   ├── HumanB.hpp
│   ├── main.cpp
│   ├── Makefile
│   ├── Weapon.cpp
│   └── Weapon.hpp
├── ex04
│   ├── main.cpp
│   ├── Makefile
│   ├── SedLoser.cpp
│   └── SedLoser.hpp
├── ex05
│   ├── Harl.cpp
│   ├── Harl.hpp
│   ├── main.cpp
│   └── Makefile
└── ex06
    ├── Harl.cpp
    ├── Harl.hpp
    ├── main.cpp
    └── Makefile
```

---

<div align="center">
  <sub>Feito com ☕ na <a href="https://www.42porto.com/pt/">42 Porto</a></sub>
</div>
