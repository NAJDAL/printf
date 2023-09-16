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

            // Flags
            int flag_plus = 0;
            int flag_space = 0;
            int flag_hash = 0;

            // Length modifiers
            int length_l = 0;
            int length_h = 0;

            // Field width
            int field_width = 0;

            // Precision
            int precision = -1; // Default value, -1 means no precision specified

            // Handle flags
            while (*format == '+' || *format == ' ' || *format == '#')
            {
                if (*format == '+')
                    flag_plus = 1;
                else if (*format == ' ')
                    flag_space = 1;
                else if (*format == '#')
                    flag_hash = 1;
                format++;
            }

            // Handle field width
            if (*format >= '0' && *format <= '9')
            {
                while (*format >= '0' && *format <= '9')
                {
                    field_width = field_width * 10 + (*format - '0');
                    format++;
                }
            }

            // Handle precision
            if (*format == '.')
            {
                format++; // Move past the '.'
                precision = 0;

                while (*format >= '0' && *format <= '9')
                {
                    precision = precision * 10 + (*format - '0');
                    format++;
                }
            }

            // Handle length modifiers
            while (*format == 'l' || *format == 'h')
            {
                if (*format == 'l')
                    length_l++;
                else if (*format == 'h')
                    length_h++;
                format++;
            }

            switch (*format)
            {
                case 'c':
                    buffer[buffer_index++] = va_arg(args, int);
                    break;
                case 's':
                    str_arg = va_arg(args, char *);
                    if (str_arg == NULL)
                        str_arg = "(null)";

                    if (precision != -1)
                    {
                        int i;
                        for (i = 0; i < precision && str_arg[i]; i++)
                        {
                            if (buffer_index < BUFFER_SIZE - 1)
                                buffer[buffer_index++] = str_arg[i];
                            else
                            {
                                write(1, buffer, buffer_index);
                                buffer_index = 0;
                            }
                        }
                        str_arg += i;
                    }

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
                    if (flag_plus && va_arg(args, int) >= 0)
                        buffer[buffer_index++] = '+';
                    else if (flag_space && va_arg(args, int) >= 0)
                        buffer[buffer_index++] = ' ';
                    if (length_l == 2)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%ld", va_arg(args, long));
                    else if (length_l == 1)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%lld", va_arg(args, long long));
                    else if (length_h == 1)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%hd", (short)va_arg(args, int));
                    else if (length_h == 2)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%hhd", (char)va_arg(args, int));
                    else
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%d", va_arg(args, int));
                    break;
                case 'x':
                    if (flag_hash)
                    {
                        buffer[buffer_index++] = '0';
                        buffer[buffer_index++] = 'x';
                    }
                    if (length_l == 2)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%lx", va_arg(args, unsigned long));
                    else if (length_l == 1)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%llx", va_arg(args, unsigned long long));
                    else if (length_h == 1)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%hx", (unsigned short)va_arg(args, unsigned int));
                    else if (length_h == 2)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%hhx", (unsigned char)va_arg(args, unsigned int));
                    else
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%x", va_arg(args, unsigned int));
                    break;
                case 'X':
                    if (flag_hash)
                    {
                        buffer[buffer_index++] = '0';
                        buffer[buffer_index++] = 'X';
                    }
                    if (length_l == 2)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%lX", va_arg(args, unsigned long));
                    else if (length_l == 1)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%llX", va_arg(args, unsigned long long));
                    else if (length_h == 1)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%hX", (unsigned short)va_arg(args, unsigned int));
                    else if (length_h == 2)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%hhX", (unsigned char)va_arg(args, unsigned int));
                    else
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%X", va_arg(args, unsigned int));
                    break;
                case 'u':
                    if (length_l == 2)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%lu", va_arg(args, unsigned long));
                    else if (length_l == 1)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%llu", va_arg(args, unsigned long long));
                    else if (length_h == 1)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%hu", (unsigned short)va_arg(args, unsigned int));
                    else if (length_h == 2)
                        buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%h
