*This project has been created as part of the 42 curriculum by himekkao*

# ft_printf

## Description

ft_printf is a 42 Common Core project that consists of recreating
the standard C printf function.

The goal is to understand variadic functions, format-string parsing,
and type conversions by implementing a function capable of handling
different format specifiers and printing formatted output to
standard output.

The project supports the mandatory conversions: c, s, p, d, i,
u, x, X and %.

## Instructions

### Compilation

Run the following command at the root of the project to compile the library:

```bash
make
```

This generates `libftprintf.a`.

### Usage

Include the header in your source file:

```c
#include "ft_printf.h"
```

Example:

```c
int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "42", 1337);
    return (0);
}
```

### Execution

Compile your program and link it with the library:

```bash
cc main.c libftprintf.a
```

Run the executable:

```bash
./a.out
```

### Makefile Rules

| Command       | Description                          |
| ------------- | ------------------------------------ |
| `make`        | Compile the library.                 |
| `make clean`  | Remove object files.                 |
| `make fclean` | Remove object files and the library. |
| `make re`     | Recompile the project.               |


## Resources

- **ft_printf documentation:** Used to understand the project requirements and mandatory features.
- **YouTube tutorials:** Used to understand variadic functions and how they work in C.
- **Python Tutor:** Used to visualize and follow the execution of code step by step.
- **AI assistance:** Used to ask questions, clarify programming concepts.

### AI Usage

AI was used for:
- Organizing and improving the project documentation.
- Visualizing and understanding programming concepts related to the project.
- Clarifying technical explanations when needed.

## Algorithm and Data Structures

### Algorithm

The implementation processes the format string from left to right, one character at a time.

1. Check whether the format string is NULL. If so, return `-1`.
2. Initialize the argument list, the index, and the character counter.
3. Iterate through the format string until its null terminator is reached.
4. If the current character is not `%`, print it directly using `ft_putchar()`.
5. If `%` is encountered and is followed by another character, pass that character to `handle_format()`.
6. `handle_format()` identifies the conversion specifier and calls the corresponding printing function.
7. Add the number of characters printed to the counter.
8. If a printing function returns `-1`, end the argument list and return `-1`.
9. Once processing is complete, end the argument list and return the total number of characters printed.

### Data Structures and Variables

The implementation uses:

- `va_list`: to access the variable arguments passed to `ft_printf`.
- `const char *format`: to access the format string.
- `int i`: to track the current position in the format string.
- `int counter`: to count the total number of characters printed.
- `int x`: to store the return value of printing functions and check for errors.

### Justification

A sequential parsing approach was chosen because it is simple and sufficient for handling the mandatory conversions.

Separating conversion handling into `handle_format()` keeps the main function organized and delegates each conversion to its corresponding printing function.

This approach avoids unnecessary complexity and makes the implementation easier to read, maintain, and extend.