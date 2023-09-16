
---

# ALX Software Engineering Programme: Printf Project

<<<<<<< HEAD
Compilation
Your code will be compiled this way:
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
As a consequence, be careful not to push any c file containing a main function in the root directory of your project (you could have a test folder containing all your tests files including main functions)
Our main files will include your main header file (main.h): #include main.h
You might want to look at the gcc flag -Wno-format when testing with your _printf and the standard printf. 


Example of test file that you could use:
alex@ubuntu:~/c/printf$ cat main.c 
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
Let's try to printf a simple sentence.
Length:[39, 39]
Unknown:[??|r?A???]
Percent:[%]
String:[I am a string !]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]

=======
## Overview

This project introduces a program designed for formatted output conversion in the C programming language. Developed as an integral component of the low-level programming and algorithm track at ALX Software Engineering Programme, this program emulates the behavior of the C standard library function, `printf`.

## Dependencies

The `_printf` function was meticulously crafted and tested on an Ubuntu 20.04.1 LTS machine, utilizing `gcc` version 9.4.0.

## Usage

To seamlessly employ the `_printf` function, provided that the dependencies mentioned above have been installed, follow these steps:

1. Compile all `.c` files in the repository.
2. Include the `main.h` header file in your C program.
3. Create your program's `main` function.

Example `main.c`:

```
#include "main.h"

int main(void)
{
    _printf("Hello, World!");

    return (0);
}
```

To compile the program:

```
 $ gcc *.c -o a.out
```

To execute your program:

```
$ ./a.out
```

Example Output:

```
Hello, World!
```

## Description

The `_printf` function generates output directed to the standard output stream based on a `format` string. This format string dictates how subsequent arguments are transformed for output.

**Prototype:** `int _printf(const char *format, ...);`

### Return Value

Upon successful execution, `_printf` returns the count of characters printed, excluding the null byte used to terminate output to strings. In the case of an output error, the function returns `-1`.

### Format of the Argument String

The `format` string is a sequence of characters that may include zero or more directives. Characters not preceded by `%` are copied as is to the output stream. Conversion specifications are introduced by `%` and are followed by a conversion specifier. Between `%` and the conversion specifier, there may be (in order) zero or more flags, an optional minimum field width, an optional precision, and an optional length modifier. Arguments must correspond to the conversion specifier and are processed in the order they appear.

#### Conversion Specifiers

The conversion specifier, starting with `%`, determines the type of conversion to perform. The `_printf` function supports the following conversion specifiers:

- `%d`, `%i`: Format an `int` argument as a signed decimal or integer.

Example:

```
int main(void)
{
    _printf("%d\n", 7);
}
```

Output:

```
7
```

- `%b`: Format an `unsigned int` argument as an unsigned decimal.

Example:

```
int main(void)
{
    _printf("%b\n", 7);
}
```

Output:

```
111
```

- `%o`, `%u`, `%x`, `%X`: Format an `unsigned int` argument as octal (`%o`), decimal (`%u`), or hexadecimal (`%x` or `%X`) representations without sign. For `%x`, lowercase letters `abcdef` are used, while `%X` employs uppercase `ABCDEF`.

Example:

```
int main(void)
{
    _printf("%o\n", 77);
}
```

Output:

```
115
```

- `%c`: Format an `int` argument as an `unsigned char`.

Example:

```
int main(void)
{
    _printf("%c\n", 48);
}
```

Output:

```
0
```

- `%s`: Format a `const char *` argument as a string.

Example:

```
int main(void)
{
    _printf("%s\n", "Hello, World!");
}
```

Output:

```
Hello, World!
```

- `%r`: Similar to `%s`, but reverses the string.

Example:

```
int main(void)
{
    _printf("%r\n", "Hello, World");
}
```

Output:

```
dlroW ,olleH
```

- `%R`: Format a `const char *` argument as ROT13 encoded.

Example:

```
int main(void)
{
    _printf("%R\n", "Hello, World");
}
```

Output:

```
Uryyb, Jbeyq
```

- `%p`: Format a pointer argument to output its memory address in hexadecimal format, preceded by `0x`.
>>>>>>> 9b106d13c9cb56bacd4ae0934c234b2b3754bd24

Example:

```
int main(void)
{
    char *str = "Hello, World";
    _printf("%p\n", (void *)str);
}
```

Output:

```
0x561a6d7bab5d
```

- `%%`: Outputs the character `%`. No argument is transformed.

Example:

```
int main(void)
{
    _printf("%%\n");
}
```

Output:

```
%
```

#### Flags

The following flags can be applied:

- `+`: Forces a plus or minus sign (`+` or `-`) to precede the result for positive numbers. By default, only negative numbers are prefixed with `-`.

- `(space)`: Inserts a blank space before the value if no sign is present.

- `#`: With `o`, `x`, or `X` specifiers, it prefixes the value with `0`, `0x`, or `0X`, respectively, for non-zero values. With `e`, `E`, or `f` specifiers, it ensures that the output contains a decimal point even if no digits follow. For `g` or `G`, it behaves like `e` or `E`, but it does not remove trailing zeros.

## Authors

- [NAJD ALEID](https://github.com/NAJDAL)
- [Loay Awadalla](https://github.com/)


## Acknowledgements

This `_printf` function emulates the functionality of the C standard library function `printf`. This README is inspired by the Linux man page for [printf(3)](https://linux.die.net/man/3/printf).

This project is part of the curriculum for the ALX Software Engineering Programme, a fully-funded scholarship programme with the mission to create 2 million job opportunities in Africa by 2030. For more information, visit [ALX Africa](https://www.alxafrica.com/).

---

This revised README provides a more polished and professional presentation of the `printf` project, making it easier for users and developers to understand and utilize the `_printf` function. If you have any further questions or require additional assistance, please feel free to ask.
