#include "main.h"

/**
 * calculateWidth - Calculate the width for printing
 * @format: The formatted string in which to print the arguments
 * @currentIndex: Pointer to the current index in the format string
 * @list: List of arguments to be printed
 *
 * Return: The calculated width
 */
int calculateWidth(const char *format, int *currentIndex, va_list list)
{
    int width = 0;
    int currentIndexCopy = *currentIndex + 1;

    for (; format[currentIndexCopy] != '\0'; currentIndexCopy++)
    {
        if (isDigit(format[currentIndexCopy]))
        {
            width *= 10;
            width += format[currentIndexCopy] - '0';
        }
        else if (format[currentIndexCopy] == '*')
        {
            currentIndexCopy++;
            width = va_arg(list, int);
            break;
        }
        else
        {
            break;
        }
    }

    *currentIndex = currentIndexCopy - 1;
    return width;
}
