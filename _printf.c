#include "main.h"

/**
 * print_buffer - Flushes the buffer and prints its contents
 * @buffer: The buffer storing characters to be printed
 * @buff_ind: Index to track the buffer length
 */
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    va_list args;
    va_start(args, format);

    int printed_chars = 0;
    char output_buffer[BUFF_SIZE];
    int buff_index = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            output_buffer[buff_index++] = format[i];
            if (buff_index == BUFF_SIZE)
                print_buffer(output_buffer, &buff_index);
            printed_chars++;
        }
        else
        {
            print_buffer(output_buffer, &buff_index);
            i++;
            if (format[i] == '\0')
                return (-1); // Incomplete format specifier

            int flags = get_flags(format, &i);
            int width = get_width(format, &i, args);
            int precision = get_precision(format, &i, args);
            int size = get_size(format, &i);
            i++; // Move past the format specifier character

            int printed = handle_print(format, &i, args, output_buffer,
                                       flags, width, precision, size);
            if (printed == -1)
                return (-1); // Error in printing
            printed_chars += printed;
        }
    }

    print_buffer(output_buffer, &buff_index);
    va_end(args);

    return (printed_chars);
}

/**
 * print_buffer - Flushes the buffer and prints its contents
 * @buffer: The buffer storing characters to be printed
 * @buff_ind: Index to track the buffer length
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, buffer, *buff_ind);

    *buff_ind = 0;
}
