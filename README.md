# ALX Software Engineering Programme: Printf Project

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

- [NAJD ALEID](https://github.com/NAJDAL/printf)
- [Loay Awadalla](https://github.com/)


## Acknowledgements

This `_printf` function emulates the functionality of the C standard library function `printf`. This README is inspired by the Linux man page for [printf(3)](https://linux.die.net/man/3/printf).

This project is part of the curriculum for the ALX Software Engineering Programme, a fully-funded scholarship programme with the mission to create 2 million job opportunities in Africa by 2030. For more information, visit [ALX Africa](https://www.alxafrica.com/).

---

This revised README provides a more polished and professional presentation of the `printf` project, making it easier for users and developers to understand and utilize the `_printf` function. If you have any further questions or require additional assistance, please feel free to ask.
