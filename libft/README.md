*This project has been created as part of the 42 curriculum by nelali.*  

# Libft

## Description
Libft is a custom C library developed as part of the 42 curriculum. The purpose of this project is to reimplement a set of standard C library functions in order to better understand how they work internally, improve memory management skills, and build a reusable static library.
This library will be reused in future 42 projects and serves as a foundation for learning low-level programming concepts in C.

---

## Detailed Description of the Library
The library is composed of several groups of functions:

    **Character handling functions** used to check and convert characters (alphabetic, digit, printable characters, and case conversion).
    **String manipulation functions** used to measure, search, copy, and concatenate strings safely.
    **Memory manipulation functions** used to set, copy, move, compare, and search memory areas.
    **Memory allocation helpers** used to allocate and initialize memory.
    **Conversion functions** used to convert strings to integers and integers to strings.
    **String creation and transformation utilities** that allocate and return new strings.
    **File descriptor output functions** used to write characters, strings, and numbers to a given file descriptor.
    **Bonus linked list utilities** implementing and manipulating singly linked lists (creation, insertion, iteration, deletion, and mapping). 

All functions are written in C, compiled into a static library (libft.a), and follow the Libft subject requirements and 42 Norm (Norminette).

---

## Instructions
### Compilation 
To compile the library, run:

```bash
make
```
This will generate the static library:
libft.a

### Cleaning
Remove object files:

```bash
make clean 
```

Remove object files and the library:

```bash
make fclean
```

Recompile the library from scratch:

```bash
make re
```

### Usage
Include the header file in your source code:

```bash
#include "libft.h"
```

Compile your program with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft
```

### Resources
References:
1) 42 Libft subject PDF
2) Manual pages (man malloc, man free, man write, man memset, man memcpy, man memmove, man strlcpy, man strlcat, man atoi)
3) C standard library documentation
Use of AI:
1) Review implementations for memory safety and common mistakes.
2) Provide main programs to test the functions.
All final implementations were reviewed and adjusted to comply strictly with the Libft subject requirements.

### Author 
Login: nelali 
Campus: 42 Irbid
