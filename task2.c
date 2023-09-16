#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints formatted output to stdout.
 * @format: A format string containing directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *str_arg;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past the '%'
            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    str_arg = va_arg(args, char *);
                    if (str_arg == NULL)
                        str_arg = "(null)";
                    count += printf("%s", str_arg);
                    break;
                case 'd':
                case 'i':
                    count += printf("%d", va_arg(args, int));
                    break;
                case 'b':
                    count += print_binary(va_arg(args, unsigned int));
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}

/**
 * print_binary - Prints an unsigned int in binary representation.
 * @n: The unsigned int to print in binary.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int n)
{
    int count = 0;
    if (n > 1)
        count += print_binary(n / 2);
    count += putchar('0' + (n % 2));
    return count;
}
