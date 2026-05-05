*This project has been created as part of the 42 curriculum by leoaguia.*

<div align="center">
  <img src="https://via.placeholder.com/1000x300/000000/FFFFFF/?text=CPP+Module+00" width="100%" />
</div>

## ⚒ Creator

<div align="left">
  <a href="https://github.com/larocquel">
    <img src="https://avatars.githubusercontent.com/larocquel?size=100" width="100">
  </a>
  <br><br>
  <b><a href="https://github.com/larocquel">Leonardo La Rocque</a></b>
</div>

## ⤷ Content

1. [Description](#description)
2. [Instructions](#instructions)
3. [Resources](#resources)
4. [Skeleton](#skeleton)
5. [Concepts](#concepts)
6. [Applications](#applications)
7. [Special Thanks](#special-thanks)

## <a id="description"></a>🖳 Description

**CPP Module 00** is the first step into Object-Oriented Programming (OOP) within the 42 curriculum. Designed strictly around the **C++98 standard**, this project marks the transition from structural C programming to C++ paradigms.

The goal is to understand foundational C++ concepts such as namespaces, classes, member functions, I/O streams, and encapsulation. The project is divided into exercises:

- **Ex00 (Megaphone):** A simple program to understand standard standard I/O and string manipulation by converting arguments to uppercase.
- **Ex01 (My Awesome PhoneBook):** A fully functional CLI phonebook that stores up to 8 contacts. It demonstrates class design, strict private encapsulation, circular data replacement, and robust terminal input handling using `std::cin` and `std::getline`.

## <a id="instructions"></a>⬇ Instructions

`Prerequisites`

* c++ compiler (GCC or Clang)
* Make

`Running Megaphone (Ex00)`

1. **Navigate to the directory and compile:**
```bash
cd ex00/
make
```

2. **Launch:**
```bash
./megaphone "shhhhh... I think the students are asleep..."
```
> Expected output: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

`Running PhoneBook (Ex01)`

1. **Navigate to the directory and compile:**
```bash
cd ../ex01/
make
```

2. **Launch the interactive loop:**
```bash
./phonebook
```

3. **Available Commands:**
* `ADD`: Add a new contact to the phonebook.
* `SEARCH`: Display a formatted list of contacts and select an index for more details.
* `EXIT`: Quit the program (contacts are lost forever).

4. **Clean up:**
```bash
make fclean
```

## <a id="resources"></a>🕮 Resources

### References

* **cplusplus.com:** Essential documentation for `<string>`, `<iostream>`, and `<iomanip>`.

### AI Usage Disclosure

This project utilized Artificial Intelligence tools (specifically Gemini) to support the development process in the following capacities:

* **Mentorship & Logic Validation:** Acting as a mentor to clarify the `std::endl` vs `\n` buffer management, validate strict C++98 compliance, and ensure flawless EOF (`Ctrl+D`) handling.
* **Documentation & Design:** Generating visual concepts, and checking code encapsulation standards.

## <a id="skeleton"></a>☠ Skeleton

Here is an overview of my architecture for Ex01. I strictly followed OOP principles, cleanly separating declarations (`.hpp`) from implementations (`.cpp`).

```bash
├── ex00
│   ├── Makefile
│   └── megaphone.cpp
├── ex01
│   ├── Contact.cpp     # Setters and Getters implementation
│   ├── Contact.hpp     # Contact class definition
│   ├── Main.cpp        # Entry point and read/eval loop
│   ├── Makefile        # Compilation rules
│   ├── PhoneBook.cpp   # ADD, SEARCH logic and data formatting
│   └── PhoneBook.hpp   # PhoneBook class definition and static array
└── README.md
```

## <a id="concepts"></a>🗝 Concepts

* ### Namespaces
A `namespace` is a declarative region that provides a scope to identifiers, preventing name collisions. In this project, `using namespace std;` is strictly forbidden to build the habit of avoiding global scope pollution, requiring explicit calls like `std::cout` and `std::string`.

* ### Classes and Encapsulation
The core of OOP. The `Contact` class encapsulates user data by making attributes strictly `private`. External entities cannot modify the data directly; they must use `public` methods (Getters and Setters). This protects the integrity of the object.

* ### I/O Streams & Buffer Management
Transitioning from `printf`/`scanf` to C++ Streams (`std::cin`, `std::cout`). Handling `std::getline` properly is critical to prevent infinite loops when the Standard Input stream is closed (e.g., encountering an `EOF` via `Ctrl+D`).

* ### Input Output Manipulation (iomanip)
Using `<iomanip>` tools like `std::setw(10)`, `std::right`, and `std::left` to strictly format terminal output into standardized, highly readable tables without manual string padding.

## <a id="applications"></a>🗺 Applications

These foundational C++ concepts are heavily applied in real-world scenarios:

* **Secure Architecture:** `Encapsulation` is the backbone of securing data in software. A banking application uses private attributes to ensure a user's account balance cannot be arbitrarily changed without passing through rigorous validation methods.
* **CLI Applications:** Robust error handling and stream management (`EOF` and buffer clearing) are essential for building reliable Command Line Interfaces used in system administration and DevOps tools.
* **Legacy Systems:** Mastering the **C++98 standard** builds the capability to maintain, debug, and upgrade critical legacy codebases in industries like aerospace, finance, and telecommunications.

## <a id="special-thanks"></a>♡ Special Thanks

A special shoutout to:

* <a href="https://github.com/thaisliira"><img align="left" src="https://avatars.githubusercontent.com/thaisliira?size=100" width="50"></a>
**[Thaís Lira](https://github.com/thaisliira)**
For providing a place that I can call home and the contagious passion she shows when discussing code.

<br clear="left"/>

* <a href="https://github.com/larocqueg"><img align="left" src="https://avatars.githubusercontent.com/larocqueg?size=100" width="50"></a>
**[Gabriel La Rocque](https://github.com/larocqueg)**
For his relentless patience and guidance in architecting solid code structures and helping me debug C++ logic effectively.

<br clear="left"/>
