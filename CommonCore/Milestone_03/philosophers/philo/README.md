*This project has been created as part of the 42 curriculum by leoaguia.*

---

<div align="center">
  <img src="https://github.com/larocquel/42_Philosophers/raw/cbb5399b2043ce8829a912a2cd51e5b4fb77cb75/img/philosophers_banner.png" width="100%" />
</div>

> "I never thought philosophy would be so deadly."

---

## ⚒ Creator

<div align="center">
  <a href="https://github.com/larocquel">
    <img src="https://avatars.githubusercontent.com/larocquel?size=100" width="100">
  </a>
  <br><br>
  <b><a href="https://github.com/larocquel">Leonardo La Rocque</a></b>
</div>

---

## ⤷ Content

1. [Description](#description)
2. [Instructions](#instructions)
3. [Resources](#resources)
4. [Skeleton](#skeleton)
5. [Concepts](#concepts)
6. [Applications](#applications)
7. [Special Thanks](#special-thanks)

---

## <a id="description"></a>🖳 Description

**Philosophers** is a simulation of the classic Dining Philosophers problem, originally formulated by **Edsger Dijkstra**. This project is a major milestone in the 42 curriculum, serving as a deep dive into `multithreading`, `concurrency`, and `resource sharing` in `C`.

The goal was to create a robust simulation that prevents philosophers from starving to death while ensuring the program is completely free of data races and deadlocks. It required managing:

- `Thread creation` and synchronization using `pthread_create` and `pthread_join`.
- Protecting shared resources (forks) using `mutexes`.
- Implementing precise `micro-sleep` routines to track time accurately.
- Developing algorithms to prevent `deadlocks` and `starvation`.

---
<div align="center">
  <img src="https://github.com/larocquel/42_Philosophers/raw/21ee55e0211a4ab792caebb0ad56cbbd7acd808c/img/philosophers.gif" alt="Demo" width="1000" height="500"/>
</div>

---

## <a id="instructions"></a>⬇ Instructions

`Prerequisites`

* GCC or Clang
* Make
* Pthread library

`Running the Simulation`

1. **Clone the repository:**

```bash
git clone git@github.com:larocquel/42_Philosophers.git

```

```bash
cd philo/

```

2. **Compile:**

```bash
make

```

3. **Launch:**

```bash
./philo [nb_of_philos] [time_to_die] [time_to_eat] [time_to_sleep] [times_each_philo_must_eat(optional)]

```

> `Example: ./philo 5 1000 200 200`
> `Time unit: ms`

4. **Clean up:**

```bash
make fclean

```

5. **Extra rules:**

```bash
make clean
make re

```

6. **Sanitizer & Leak Check (Extreme Validation):**

`Memory Leaks`

```bash
setarch $(uname -m) -R valgrind --leak-check=full ./philo 5 800 200 200 7

```

`Data Races (requires compiling with -fsanitize=thread)`

```bash
./philo 5 800 200 200

```

---

## <a id="resources"></a>🕮 Resources

### References

* **Linux Man Pages:** Deep dive into `gettimeofday()`, `usleep()`, and `pthread_mutex_init()`.
* **Tanenbaum, A. S., & Bos, H. (2023).** *Modern Operating Systems* (5th ed., pp. 115-119). Pearson.

### AI Usage Disclosure

This project utilized Artificial Intelligence tools (specifically Gemini) to support the development process in the following capacities:

* **Mentorship & Logic Validation:** Acting as a mentor to explain the mathematical logic behind starvation and to identify C operator precedence traps.
* **Documentation & Design:** Generating visual concepts, formatting this `README.md`, and structuring the repository to industry standards.

---

## <a id="skeleton"></a>☠ Skeleton

Here is an overview of my architecture. I strictly followed industry standards for C projects to keep the codebase modular and maintainable.

```bash
philo/
├── inc/                # Header files (.h)
│   └── philo.h         # Main header with structs and prototypes
├── src/
│   ├── main.c          # Entry point and argument parsing
│   ├── init.c          # Initialization of structs, threads, and mutexes
│   ├── philo.c         # The core thread routine and monitor (death checker)
│   ├── actions.c       # Eating, sleeping, and the dynamic thinking algorithm
│   └── utils.c         # Time fetching, custom usleep, and safe printing
├── Makefile            # Compilation rules (creates obj/ directory)
└── README.md           # Here we are!

```

---

## <a id="concepts"></a>🗝 Concepts

* ### Thread



A `thread` is the smallest unit of execution within a process, acting like a single "worker" inside a shared office. In this project, each philosopher is assigned their own thread, allowing them to perform actions like eating, sleeping, or thinking independently and simultaneously.

* ### Multithreading and Concurrency



`Multithreading` in C is the art of running multiple threads in parallel to achieve `concurrency`, where several tasks make progress at the same time. The primary challenge is that these threads share the same memory space, meaning they must compete for `shared resources` (the forks).

* ### Mutexes (Mutual Exclusion)



A `Mutex` acts as a digital "lock" that ensures only one thread can access a specific resource at a time. Think of it as a bathroom key: if a philosopher wants to use a fork, they must first "lock" its mutex; if the key is already taken, they must wait until it is returned.

* ### Deadlocks and Starvation



A `Deadlock` occurs when a circular wait freezes the system—for example, if every philosopher picks up their right fork and waits forever for the left one to be free.

`Starvation`, on the other hand, is when a philosopher never gets to eat because their neighbors are constantly using the forks. This project uses resource hierarchy (even/odd picking) and dynamic timing to ensure the "traffic" at the table never jams and every philosopher gets a turn to eat.

---

## <a id="applications"></a>🗺 Applications

While the Dining Philosophers is a theoretical analogy, these concepts form the absolute backbone of modern software engineering:

* **Banking Systems:** Rely strictly on `mutexes` to ensure simultaneous transactions don't overwrite the same account balance, preventing catastrophic data corruption.
* **Web Servers & Databases:** Heavily use `multithreading` and `concurrency` to handle thousands of user requests at the exact same time without freezing the application.
* **Operating Systems & Game Engines:** Actively prevent `deadlocks` and `starvation` to efficiently manage CPU, GPU, and memory resources, ensuring your computer remains responsive and crash-free.

---

## <a id="special-thanks"></a>♡ Special Thanks

This project was a massive mental workout, and the community made it possible. A special shoutout to:

* <a href="https://github.com/larocqueg"><img align="left" src="https://avatars.githubusercontent.com/larocqueg?size=100" width="50"></a>
**[Gabriel La Rocque](https://github.com/larocqueg)**
For his relentless patience and constant availability during our most mind-bending debugging sessions. His brilliant insights into solving complex `desynchronization` issues and his masterful guidance in architecting the `shared` and `unique data` structures were absolutely vital.

<br clear="left"/>

* <a href="https://github.com/matiasfreitas"><img align="left" src="https://avatars.githubusercontent.com/matiasfreitas?size=100" width="50"></a>
**[Matias Freitas](https://github.com/matiasfreitas)**
For providing excellent `introductory concepts`, the contagious `passion` he shows when discussing code, and all the invaluable teachings and mentorship provided throughout this journey so far.

<br clear="left"/>
