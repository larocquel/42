*This project has been created as part of the 42 curriculum by leoaguia.*

<div align="center">
  <img src="https://github.com/larocquel/42/raw/e42e8429d0396cc56806b9afeb04d391c90faeec/1-Common_Core/Milestone_04/cpp/02/img/cpp02_banner.png" width="100%" />
</div>

---

<div align="center">

## *Ad-hoc Polymorphism · Operator Overloading · Orthodox Canonical Form*

<br>

[![Score](https://img.shields.io/badge/Score-80%2F100-4CAF50?style=for-the-badge&logo=42&logoColor=white)](.)
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

**Module 02** deepens the transition into the object-oriented paradigm in C++, focusing on three fundamental pillars:

- **Orthodox Canonical Form** — every class must implement four required members: default constructor, copy constructor, copy assignment operator, and destructor.
- **Operator Overloading** — redefining operators (`+`, `-`, `*`, `/`, `>`, `<`, `==`, `++`, `--`, `<<`, …) for custom types.
- **Ad-hoc Polymorphism** — the same operation behaves differently depending on the types of its operands, without inheritance.

The thread running through the whole module is the implementation of a **fixed-point number** type in C++98 — absent from the standard language — culminating in its application to a geometric algorithm (BSP).

---

# <a id="document"></a>Document

<hr/>
<div align = "center">
<em >Documento de estudo produzido como complemento ao módulo</em>
<hr/>
</div>

<p align="center">
  <a href="https://github.com/larocquel/42/blob/3937d5f1305b46460cdfe6bcaa0741f985c4bdcb/1-Common_Core/Milestone_04/cpp/02/img/cpp_module_02.pdf"><img src="https://github.com/larocquel/42/raw/3937d5f1305b46460cdfe6bcaa0741f985c4bdcb/1-Common_Core/Milestone_04/cpp/02/img/cpp_module_02.png" width="60%"/></a>
</p>

</td>
  </tr>
  <tr>
    <td>
<td width="50%" valign="top">

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

---

# <a id="exercises"></a>Exercises

| nº | Exercise | Key Concept |
|---|-----------|----------------|
| [00](#-ex00--my-first-class-in-orthodox-canonical-form) | My First Class in Orthodox Canonical Form | Orthodox Canonical Form |
| [01](#-ex01--towards-a-more-useful-fixed-point-number-class) | Towards a more useful fixed-point number class | Constructors & Insertion (`<<`) |
| [02](#-ex02--now-were-talking) | Now we're talking | Full Operator Overloading |
| [03](#-ex03--bsp) | BSP | Practical Application — Geometry |

---

## ex00 | My First Class in Orthodox Canonical Form

### Concept: Orthodox Canonical Form (OCF)

From this module onwards, **all classes** must implement the four canonical members:

| Member | Responsibility |
|--------|-----------------|
| Default constructor | Initializes the value to `0` |
| Copy constructor | Creates a new object as a copy of another |
| Copy assignment operator (`operator=`) | Copies data between already existing objects |
| Destructor | Frees resources (no memory leaks) |

The `Fixed` class internally stores an `int _value` and a `static const int _fBits = 8` (number of fractional bits). In this exercise, the class only exposes `getRawBits()` and `setRawBits()`.

```bash
cd ex00 && make && ./fixed
```

---

## ex01 | Towards a more useful fixed-point number class

### Concept: Type Conversion & `<<` Operator Overload

The `Fixed` class gains two new constructors and two converters:

| Member | Behaviour |
|--------|--------------|
| `Fixed(const int n)` | Converts integer → fixed-point: `_value = n << 8` |
| `Fixed(const float n)` | Converts float → fixed-point: `_value = roundf(n * 256)` |
| `toInt()` | Converts fixed-point → integer: `_value >> 8` |
| `toFloat()` | Converts fixed-point → float: `(float)_value / 256` |

The `<<` operator is overloaded as a free function to enable `std::cout << fixedObj`.

```bash
cd ex01 && make && ./fixed
```

---

## ex02 | Now we're talking

### Concept: Full Operator Overloading

The `Fixed` class receives the complete set of overloaded operators:

**Comparison Operators** — return `bool`:

```cpp
bool operator>(const Fixed& other) const;
bool operator<(const Fixed& other) const;
bool operator>=(const Fixed& other) const;
bool operator<=(const Fixed& other) const;
bool operator==(const Fixed& other) const;
bool operator!=(const Fixed& other) const;
```

**Arithmetic Operators** — operate on the `float` representation and return a new `Fixed`:

```cpp
Fixed operator+(const Fixed& other) const;
Fixed operator-(const Fixed& other) const;
Fixed operator*(const Fixed& other) const;
Fixed operator/(const Fixed& other) const;
```

**Increment/Decrement Operators** — increase or decrease by the smallest representable ε (1 raw bit):

| Operator | Type | Detail |
|----------|------|---------|
| `++a` | Pre-increment | Increments and returns `*this` by reference |
| `a++` | Post-increment | Saves a copy, increments, returns the copy by value |
| `--a` | Pre-decrement | Decrements and returns `*this` by reference |
| `a--` | Post-decrement | Saves a copy, decrements, returns the copy by value |

> The distinction between pre and post is critical: the post version takes a dummy `int` parameter to differentiate the signatures.

**Static `min` and `max` functions** — two overloads each (for mutable and constant objects):

```cpp
static Fixed&       min(Fixed& a, Fixed& b);
static const Fixed& min(const Fixed& a, const Fixed& b);
static Fixed&       max(Fixed& a, Fixed& b);
static const Fixed& max(const Fixed& a, const Fixed& b);
```

```bash
cd ex02 && make && ./fixed
```

Expected output (constructor/destructor messages omitted):

```
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
```

---

## ex03 | BSP

### Concept: Practical Application — Binary Space Partitioning

The `Point` class (also in OCF) represents a 2D point with `Fixed const x` and `Fixed const y` attributes.

The main function of this exercise:

```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

Determines whether `point` is **strictly inside** triangle `{a, b, c}`. Returns `false` if the point lies on a vertex or an edge.

The algorithm uses the **sign of areas** computed via the cross product for each edge pair — all equal signs means the point is inside.

```bash
cd ex03 && make && ./bsp
```

> This exercise is optional: it is possible to pass the module without completing it.

---

# <a id="structure"></a>Structure

```
├── ex00
│   ├── Fixed.hpp
│   ├── Fixed.cpp
│   ├── main.cpp
│   └── Makefile
├── ex01
│   ├── Fixed.hpp
│   ├── Fixed.cpp
│   ├── main.cpp
│   └── Makefile
├── ex02
│   ├── Fixed.hpp
│   ├── Fixed.cpp
│   ├── main.cpp
│   └── Makefile
└── ex03
    ├── Fixed.hpp
    ├── Fixed.cpp
    ├── Point.hpp
    ├── Point.cpp
    ├── bsp.cpp
    ├── main.cpp
    └── Makefile
```

---

<div align="center">
  <sub>Made with ☕ at <a href="https://www.42porto.com/pt/">42 Porto</a></sub>
</div>
