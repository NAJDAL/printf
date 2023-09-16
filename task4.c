#include <stdio.h>
#include <stdarg.h>
#include "main.h"

#define BUFFER_SIZE 1024

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
    char buffer[BUFFER_SIZE];
    int buffer_index = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past the '%'
            switch (*format)
            {
                case 'c':
                    buffer[buffer_index++] = va_arg(args, int);
                    break;
                case 's':
                    str_arg = va_arg(args, char *);
                    if (str_arg == NULL)
                        str_arg = "(null)";
                    while (*str_arg)
                    {
                        if (buffer_index < BUFFER_SIZE - 1)
                            buffer[buffer_index++] = *str_arg;
                        else
                        {
                            write(1, buffer, buffer_index);
                            buffer_index = 0;
                        }
                        str_arg++;
                    }
                    break;
                case 'd':
                case 'i':
                    buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%d", va_arg(args, int));
                    break;
                case '%':
                    if (buffer_index < BUFFER_SIZE - 1)
                        buffer[buffer_index++] = '%';
                    else
                    {
                        write(1, buffer, buffer_index);
                        buffer_index = 0;
                    }
                    break;
                default:
                    if (buffer_index < BUFFER_SIZE - 2)
                    {
                        buffer[buffer_index++] = '%';
                        buffer[buffer_index++] = *format;
                    }
                    else
                    {
                        write(1, buffer, buffer_index);
                        buffer_index = 0;
                        buffer[buffer_index++] = '%';
                        buffer[buffer_index++] = *format;
                    }
                    break;
            }
        }
        else
        {
            if (buffer_index < BUFFER_SIZE - 1)
                buffer[buffer_index++] = *format;
            else
            {
                write(1, buffer, buffer_index);
                buffer_index = 0;
                buffer[buffer_index++] = *format;
            }
        }
        format++;
    }

    // Write any remaining data in the buffer
    if (buffer_index > 0)
        write(1, buffer, buffer_index);

    va_end(args);

    return count;
}
