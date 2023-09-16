#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
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
            int flag_zero = 0;
            int flag_minus = 0;

            // Length modifiers
            int length_l = 0;
            int length_h = 0;

            // Field width
            int field_width = 0;

            // Precision
            int precision = -1; // Default value, -1 means no precision specified

            // Handle flags, including '-'
            while (*format == '+' || *format == ' ' || *format == '#' || *format == '0' || *format == '-')
            {
                if (*format == '+')
                    flag_plus = 1;
                else if (*format == ' ')
                    flag_space = 1;
                else if (*format == '#')
                    flag_hash = 1;
                else if (*format == '0')
                    flag_zero = 1;
                else if (*format == '-')
                    flag_minus = 1;
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

            // Handle custom conversion specifier '%r' for reversed string
            if (*format == 'r')
            {
                str_arg = va_arg(args, char *);
                if (str_arg == NULL)
                    str_arg = "(null)";

                int str_length = 0;
                while (str_arg[str_length])
                    str_length++;

                if (!flag_minus)
                {
                    // Padding with spaces or zeros before the reversed string
                    while (field_width > str_length)
                    {
                        if (flag_zero)
                            buffer[buffer_index++] = '0';
                        else
                            buffer[buffer_index++] = ' ';
                        field_width--;
                    }
                }

                // Printing the reversed string
                for (int i = str_length - 1; i >= 0; i--)
                {
                    buffer[buffer_index++] = str_arg[i];
                }

                if (flag_minus)
                {
                    // Padding with spaces after the reversed string
                    while (field_width > str_length)
                    {
                        buffer[buffer_index++] = ' ';
                        field_width--;
                    }
                }

                continue; // Skip to the next format character
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
                    if (flag_zero && precision == -1 && !flag_minus)
                    {
                        int num = va_arg(args, int);
                        int num_len = snprintf(NULL, 0, "%d", num);

                        while (field_width >
