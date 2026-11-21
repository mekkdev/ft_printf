# ft_printf

`ft_printf` is a 1337/42 Common Core project that recreates the essential behavior of the C standard `printf` function.

The project focuses on variadic functions, format-string parsing, type conversion, hexadecimal representation, pointer handling, and static-library construction.

## Objective

Implement the following function:

```c
int	ft_printf(const char *format, ...);
```

The function writes formatted output to standard output and returns the number of characters written.

As required by the subject, this implementation does not reproduce `printf`'s internal buffer management.

## Mandatory conversions

| Conversion | Description |
| --- | --- |
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal notation, prefixed with `0x`. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints a signed integer in base 10. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned hexadecimal integer using lowercase letters. |
| `%X` | Prints an unsigned hexadecimal integer using uppercase letters. |
| `%%` | Prints a literal percent sign. |

## Project requirements

- The output library must be named `libftprintf.a`.
- The library must be created with `ar`, not `libtool`.
- The project must compile with `-Wall -Wextra -Werror`.
- The Makefile must provide `all`, `clean`, `fclean`, and `re` rules.
- The implementation must not crash unexpectedly or leak allocated memory.
- No global variables are allowed.
- `libft` may be used when its source and Makefile are included according to the subject rules.

### Allowed functions

The mandatory implementation is limited to:

```text
malloc  free  write
va_start  va_arg  va_copy  va_end
```

Functions implemented in `libft` may also be used when allowed by the project configuration.

## Build

Compile the static library from the project root:

```sh
make
```

Other available commands:

```sh
make clean   # Remove object files
make fclean  # Remove object files and libftprintf.a
make re      # Rebuild everything
```

## Usage

Include the project header and link the generated library:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello, %s! Number: %d\n", "1337", 42);
	return (0);
}
```

Example compilation command:

```sh
cc main.c -I. -L. -lftprintf -o example
./example
```

## Bonus

The bonus part extends the formatter with:

- The `-`, `0`, and `.` flags.
- The `#` flag for `%x` and `%X`.
- The space and `+` flags.
- Minimum field width for all conversions.
- Combinations of the supported flags.

Bonus support should be kept separate from the mandatory implementation and included through a `bonus` Makefile rule when applicable.

## Suggested tests

Compare `ft_printf` with the system `printf` using:

- Empty strings and `NULL` strings.
- `0`, negative values, and `INT_MIN`.
- `0` and `NULL` pointers.
- Lowercase and uppercase hexadecimal output.
- Several conversions in one format string.
- Multiple calls and mixed argument types.
- Return values and write-error behavior.

Always check the project with the 42 Norm and a memory-leak checker before submission.

## Reference

This README follows the 1337/42 `ft_printf` subject. See the [English subject PDF](https://github.com/f0rkr/42_subjects/blob/master/ft_printf.en.pdf) for the complete official specification.
