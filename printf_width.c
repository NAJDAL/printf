#include "main.h"
#include <stdbool.h>

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to the current position in the format string.
 * @list: List of arguments.
 *
 * Return: Width.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_i = *i;
    int width = 0;
    bool hasWidth = false;

    if (format[curr_i] == '*')
    {
        curr_i++;
        width = va_arg(list, int);
        hasWidth = true;
    }
    else
    {
        while (isdigit(format[curr_i]))
        {
            width = width * 10 + (format[curr_i] - '0');
            curr_i++;
            hasWidth = true;
        }
    }

    *i = curr_i - 1;

    return hasWidth ? width : -1; /* Return -1 if no width was specified */
}
