#include "main.h"

/**
 * get_width_and_precision - Calculates width and precision for printing
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to the current position in the format string.
 * @list: List of arguments.
 * @width: Output parameter to store the width.
 * @precision: Output parameter to store the precision.
 *
 * Return: void (width and precision are returned through output parameters).
 */
void get_width_and_precision(const char *format, int *i, va_list list, int *width, int *precision)
{
    int curr_i = *i;
    *width = 0;
    *precision = -1; 

    
    for (; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            *width *= 10;
            *width += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            *width = va_arg(list, int);
            break;
        }
        else
            break;
    }

    
    if (format[curr_i] == '.')
    {
        curr_i++;
        *precision = 0; 

        /* Parse precision value*/
        for (; format[curr_i] != '\0'; curr_i++)
        {
            if (is_digit(format[curr_i]))
            {
                *precision *= 10;
                *precision += format[curr_i] - '0';
            }
            else if (format[curr_i] == '*')
            {
                curr_i++;
                *precision = va_arg(list, int);
                break;
            }
            else
                break;
        }
    }

    *i = curr_i - 1;
}

