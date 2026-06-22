*This project has been created as part of the 42 curriculum by leoaguia and davmendo.*

---

<div align="center">
  <img src="https://github.com/larocquel/42_Minishell/raw/8b3675abd4a1d697e092bb5e8cfa6b3f18516db0/img/minishell_banner.png" width="100%" />
</div>

> "Creating a shell is the closest you can get to talking directly to the Kernel."

---

## ⚒ Builders

* <a href="https://github.com/larocquel"><img align="left" src="https://avatars.githubusercontent.com/larocquel?size=100" width="50"></a>
**[Leonardo La Rocque](https://github.com/larocquel)**
<br><br/>

* <a href="https://github.com/davmendo"><img align="left" src="https://avatars.githubusercontent.com/davmendo?size=100" width="50"></a>
**[David Mendonça](https://github.com/davmendo)**
<br><br/>

---

## ⤷ Content

1. [Preview](#preview)
2. [Description](#description)
3. [Instructions](#instructions)
4. [Resources](#resources)
5. [Skeleton](#skeleton)
6. [Concepts](#concepts)
7. [Special Thanks](#special-thanks)

---

## <a id="preview"></a>📽 Preview
<div align="center">
  <img src="https://github.com/larocquel/42_Minishell/raw/4a4ee57c95f877e1749bc15b33e949bed37880f6/img/minishell_demo.gif" alt="Demo" width="1000" />
</div>

---

## <a id="description"></a>🖳 Description

**Minishell** is essentially a mini-recreation of the Unix command-line interpreter (Bash). This project is one of the most complex and rewarding milestones in the 42 curriculum. It requires a deep understanding of `processes`, `file descriptors`, `signals`, and `memory management` in `C`.

Our goal was to create a robust shell that handles:

- `Parsing` and `expanding` inputs.
- Managing `pipes` (`|`) and `redirections` (`<`, `>`, `<<`, `>>`).
- `Executing` `binaries` and `builtins`.
- Handling `signals` behaving exactly like `Bash`.

---

## <a id="instructions"></a>⬇ Instructions

### Prerequisites

* GCC or Clang
* Make
* Readline library (usually pre-installed on Unix systems)

### Running the Shell

1. **Clone the repository:**

```bash
git clone git@github.com:larocquel/42_Minishell.git

```

2. **Compile:**

```bash
make

```

3. **Launch:**

```bash
./minishell

```

4. **Clean up:**

```bash
make fclean

```

5. **Extra rules**

```bash
make clean
make re

```

6. **Leak check**

```bash
valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell

```

---

## <a id="resources"></a>🕮 Resources

### References
These are the texts and documentation that guided us through the architecture of Minishell:

* **GNU Bash Reference Manual:** Our primary source of truth for replicating exact shell behaviors.
* **Linux Man Pages:** Essential for mastering system calls, particularly `fork()`, `execve()`, `pipe()`, `dup2()`, `waitpid()`, and signal handling with `sigaction()`.
* **Stephen Brennan's "Write a Shell in C":** A foundational article that helped clarify the basic Read-Eval-Print Loop (REPL) structure.
* **Advanced Programming in the UNIX Environment (APUE):** Critical for deep-diving into process groups and terminal control.
* **Let's build a super simple shell in C** https://www.youtube.com/watch?v=yTR00r8vBH8&t=1128s

### AI Usage Disclosure
This project utilized Artificial Intelligence tools (specifically Gemini) to support the development process in the following non-coding capacities:

* **Documentation & Design:** Generating the pixel-art banners, creating the visual diagrams for data structures (Linked List vs. BST), and structuring this `README.md` to ensure clarity and professional formatting.
* *Note: The core logic, algorithms, and Norminette-compliant C code were implemented entirely by the authors without AI code generation.*

---

## <a id="skeleton"></a>☠ Skeleton

Here is an overview of our architecture. We aimed for modularity to keep the codebase clean and maintainable.

```bash
minishell/
├── libft/              # Our custom C library (extended)
├── include/            # Header files (.h)
│   └── minishell.h     # Main header with structs and prototypes
├── src/
│   ├── 00_main/        # Entry point, loop & cleanup
│   ├── 01_parsing/     # Lexer, Tokenizer & Parser logic
│   ├── 02_exec/        # Executor, Pipes & Forking logic
│   ├── 03_builtins/    # cd, echo, env, exit, export, pwd, unset
│   ├── 04_redirect/    # Heredoc & FD duplications
│   ├── 05_env/         # Environment variable management (Linked List)
│   └── 06_signals/     # Sigaction handlers (Interactive vs Child)
├── Makefile            # Compilation rules
└── README.md           # This beauty

```

---

## <a id="concepts"></a>🗝 Concepts

<table width="100%">
  <tr>
    <th width="50%">Linked List (Our Choice)</th>
    <th width="50%">Binary Tree (Discarded)</th>
  </tr>
  <tr>
    <td>
      <img src="https://github.com/larocquel/42_Minishell/raw/600c268c06b5b3884988aa797029e24a4a289e34/img/linked_list.png" width="100%" />
    </td>
    <td>
      <img src="https://github.com/larocquel/42_Minishell/raw/600c268c06b5b3884988aa797029e24a4a289e34/img/binary_tree.png" width="100%" />
    </td>
  </tr>
</table>

### 1. Data Structures: Linked List vs. Binary Tree
One of the critical design decisions in Minishell was how to store and manage **Environment Variables**.

* **The Dilemma:** We initially considered using a **Binary Search Tree (BST)** to optimize variable retrieval to $O(\log n)$.
* **The Decision:** We opted for a **Linked List**.
* **The Reasoning:** While a BST offers faster search times, the number of environment variables in a shell session is typically small (rarely exceeding a few dozen). The complexity overhead of implementing and balancing a tree (e.g., Red-Black Tree) would not yield a perceptible performance benefit over a simple linear scan $O(n)$ in this context.
    * **Benefit:** Linked Lists made it significantly easier to implement builtins like `export` and `unset`, and to convert the list back to a `char **envp` array for `execve`.

### 2. The Process Workflow: Fork, Pipe & Execve
The heart of Minishell relies on the interaction between three system calls that allow us to manipulate the Kernel.

* **`fork()` - The Cloning:**
    To run a command without crashing the shell, we must create a child process. `fork()` duplicates the current process. The child inherits the memory and file descriptors of the parent, allowing the shell to stay alive while the command runs in the parallel copy.

* **`pipe()` - The Plumbing:**
    This allows communication between processes. When you run `ls | grep a`, a pipe is created. We manipulate the file descriptors using `dup2()` so that the **Standard Output (STDOUT)** of `ls` becomes the **Standard Input (STDIN)** of `grep`.

* **`execve()` - The Transformation:**
    This is the point of no return. Once the child process is set up (pipes connected, signals handled), `execve()` is called. It replaces the current process memory with the new binary (e.g., `/bin/ls`). If successful, the child process ceases to be a copy of the shell and becomes the new program.

---

## <a id="special-thanks"></a>♡ Special Thanks

This project was a beast, and we couldn't have tamed it without the help of the 42 Porto community.
A special shoutout to:

* <a href="https://github.com/Daniela-Padilha"><img align="left" src="https://avatars.githubusercontent.com/Daniela-Padilha?size=100" width="50"></a>
**[Daniela Padilha](https://github.com/Daniela-Padilha)**
For providing `support` of great importance; her `advice` and `guidance` were of immense value throughout this journey.
<br clear="left"/>

* <a href="https://github.com/izzytoot"><img align="left" src="https://avatars.githubusercontent.com/izzytoot?size=100" width="50"></a>
**[Isabel Tootil](https://github.com/izzytoot)**
For sharing her incredibly rigorous and well-organized `test documentation`, which pushed our `Minishell` to the limit and ensured its robustness.
<br clear="left"/>

* <a href="https://github.com/therappha"><img align="left" src="https://avatars.githubusercontent.com/therappha?size=100" width="50"></a>
**[Rafael Ferreira](https://github.com/therappha)**
For the critical insight on `memory management—specifically`, ensuring `child processes` perform a full cleanup before exiting to prevent `inherited leaks`.
<br clear="left"/>

* <a href="https://github.com/jvieira96"><img align="left" src="https://avatars.githubusercontent.com/jvieira96?size=100" width="50"></a>
**[João Vieira](https://github.com/jvieira96)**
For unlocking the initial mindset to kickstart the project, specifically by introducing the `readline` library and demonstrating the power of `structs` and `enums` for organization.
<br clear="left"/>

* <a href="https://github.com/larocqueg"><img align="left" src="https://avatars.githubusercontent.com/larocqueg?size=100" width="50"></a>
**[Gabriel La Rocque](https://github.com/larocqueg)**
For the game-changing suggestion to implement `Environment Variables` using `Linked Lists` instead of a complex `Binary Tree` structure. Simplicity is key!
<br clear="left"/>
