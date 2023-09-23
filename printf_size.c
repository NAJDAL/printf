#include "main.h"

/**
 * determineSize - Determine the size to cast the argument
 * @format: The format string
 * @currentIndex: Pointer to the current index in the format string
 *
 * Return: The calculated size
 */
int determineSize(const char *format, int *currentIndex)
{
    int currentIdx = *currentIndex + 1;
    int size = 0;

    if (format[currentIdx] == 'l')
        size = S_LONG;
    else if (format[currentIdx] == 'h')
        size = S_SHORT;

    if (size == 0)
        *currentIndex = currentIdx - 1;
    else
        *currentIndex = currentIdx;

    return size;
}
