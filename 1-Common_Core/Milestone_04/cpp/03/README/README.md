*This project has been created as part of the 42 curriculum by leoaguia.*

<div align="center">
  <img src="https://github.com/larocquel/42/raw/6ad1608a3c2d213df0641d113b54ad196f894ef6/1-Common_Core/Milestone_04/cpp/03/img/cpp03_banner.png" width="100%" />
</div>

---

<div align="center">

## *Inheritance · Subtyping · Virtual Inheritance*

<br>

[![Score](https://img.shields.io/badge/Score-100%2F100-4CAF50?style=for-the-badge&logo=42&logoColor=white)](.)
[![Language](https://img.shields.io/badge/C%2B%2B-98-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](.)
[![School](https://img.shields.io/badge/42-Porto-000000?style=for-the-badge&logo=42&logoColor=white)](.)

</div>

---

## Creator

<div align="center">
  <a href="https://github.com/larocquel">
    <img src="https://avatars.githubusercontent.com/larocquel?size=100" width="100">
  </a>
  <br><br>
  <b><a href="https://github.com/larocquel">Leonardo La Rocque</a></b>
</div>

## Content

1. [About](#about)
2. [Document](#document)
3. [Compilation](#compilation)
4. [Exercises](#exercises)
5. [Structure](#structure)

---

# <a id="about"></a>About

**Module 03** deepens the transition into the object-oriented paradigm in C++, focusing on the mechanisms of class derivation:

- **Inheritance (`public`)** — creating new classes (Derived) that inherit properties and behaviors from existing classes (Base).
- **Access Modifiers (`protected`)** — exposing class members to derived classes while keeping them hidden from the outside world.
- **Method Overriding** — redefining inherited behaviors in derived classes to specialize functionality.
- **Multiple Inheritance & The Diamond Problem** — exploring the complexities of inheriting from multiple paths and resolving ambiguity using **Virtual Inheritance**.

The thread running through the whole module is the construction of an army of robots (`ClapTrap` and its variants), culminating in a monstrous hybrid robot (`DiamondTrap`).

---

# <a id="document"></a>Document

<hr/>
<div align = "center">
<em >Documeatation CLICK ON THE IMAGE TO ACCESS</em>
<hr/>
</div>

<p align="center">
  <a href="https://github.com/larocquel/42/blob/6ad1608a3c2d213df0641d113b54ad196f894ef6/1-Common_Core/Milestone_04/cpp/03/img/guiacpp03.pdf"><img src="https://github.com/larocquel/42/raw/6ad1608a3c2d213df0641d113b54ad196f894ef6/1-Common_Core/Milestone_04/cpp/03/img/guiacpp03.png" width="60%"/></a>
</p>

</td>
  </tr>
  <tr>
    <td>
<td width="70%" valign="top">

---

# <a id="compilation"></a>Compilation

All exercises follow 42 norms and include a ready-to-use `Makefile`.

```bash
make        # Compiles and generates the executable
make clean  # Removes object files (.o)
make fclean # Removes everything (including the executable)
make re     # Full recompilation (fclean + make)

```

Mandatory flags: `-Wall -Wextra -Werror -std=c++98`
*(Exercise 03 adds `-Wshadow` to the flags).*

---

# Exercises

| nº | Exercise | Key Concept |
| --- | --- | --- |
| [00](https://www.google.com/search?q=%23-ex00--aaaaand-open) | Aaaaand... OPEN! | Base Class Creation (OCF) |
| [01](https://www.google.com/search?q=%23-ex01--serena-my-love) | Serena, my love! | Simple Inheritance & Overriding |
| [02](https://www.google.com/search?q=%23-ex02--repetitive-work) | Repetitive work | Constructor/Destructor Chaining |
| [03](https://www.google.com/search?q=%23-ex03--now-its-weird) | Now it's weird! | Multiple Inheritance & Diamond Problem |

---

## ex00 | Aaaaand... OPEN!

### Concept: Base Class Creation (OCF)

Implementation of the base class `ClapTrap` following the Orthodox Canonical Form. It introduces the fundamental attributes that all future robots will share:

* `Name` (passed to the constructor)
* `Hit points` (10)
* `Energy points` (10)
* `Attack damage` (0)

It also includes basic actions like `attack()`, `takeDamage()`, and `beRepaired()`, which consume energy points and affect hit points.

```bash
cd ex00 && make && ./claptrap

```

---

## ex01 | Serena, my love!

### Concept: Simple Inheritance & Method Overriding

Creation of the `ScavTrap` class, which inherits from `ClapTrap`.
Key learning points:

* Using the `protected` access modifier in the base class so derived classes can access attributes.
* Changing default attribute values upon construction (100 HP, 50 Energy, 20 Damage).
* **Overriding** the `attack()` method with a different message.
* Implementing an exclusive ability: `guardGate()`.
* Observing the correct order of Constructor/Destructor chaining (Base constructed first, Derived destroyed first).

```bash
cd ex01 && make && ./scavtrap

```

---

## ex02 | Repetitive work

### Concept: Constructor/Destructor Chaining

Creation of the `FragTrap` class, which also inherits from `ClapTrap`.
Similar to `ex01`, but with different default stats (100 HP, 100 Energy, 30 Damage) and its own exclusive ability: `highFivesGuys()`. It reinforces the concept of proper inheritance structuring and memory management through destructors.

```bash
cd ex02 && make && ./fragtrap

```

---

## ex03 | Now it's weird!

### Concept: Multiple Inheritance & Diamond Problem

Creation of the `DiamondTrap` class, a monster that inherits from both `ScavTrap` AND `FragTrap`.

This exercise introduces the infamous **Diamond Problem** in C++: since both parents inherit from `ClapTrap`, a standard multiple inheritance would result in two independent instances of `ClapTrap` in memory, causing ambiguity.

**The Solution:**
Both `ScavTrap` and `FragTrap` must use **Virtual Inheritance** (`virtual public ClapTrap`) so that `DiamondTrap` shares a single, unified `ClapTrap` subobject.

Special characteristics:

* It borrows stats dynamically: Hit Points (from FragTrap), Energy Points (from ScavTrap), Attack Damage (from FragTrap), and `attack()` method (from ScavTrap).
* Introduces **Name Shadowing**: The `DiamondTrap` has its own `_name` attribute, which shadows the `ClapTrap::_name`. It implements the `whoAmI()` method to demonstrate accessing both the local and the base class shadowed variable.

```bash
cd ex03 && make && ./diamondtrap

```

> This exercise is optional: it is possible to pass the module without completing it.

---

# Structure

```
├── ex00
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   ├── main.cpp
│   └── Makefile
├── ex01
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   ├── ScavTrap.hpp
│   ├── ScavTrap.cpp
│   ├── main.cpp
│   └── Makefile
├── ex02
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   ├── FragTrap.hpp
│   ├── FragTrap.cpp
│   ├── main.cpp
│   └── Makefile
└── ex03
    ├── ClapTrap.hpp
    ├── ClapTrap.cpp
    ├── ScavTrap.hpp
    ├── ScavTrap.cpp
    ├── FragTrap.hpp
    ├── FragTrap.cpp
    ├── DiamondTrap.hpp
    ├── DiamondTrap.cpp
    ├── main.cpp
    └── Makefile

```
