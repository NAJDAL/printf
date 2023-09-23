#include "main.h"

/**
 * get_flags - Extracts and calculates active flags from the format string
 * @format: The format string
 * @currentIndex: Pointer to the current index in the format string
 * Return: Combined flags
 */
int get_flags(const char *format, int *currentIndex)
{
    int flags = 0;
    const char validFlags[] = "-+0# ";
    const int flagValues[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};
    int i, j;

    while (format[*currentIndex] != '\0')
    {
        for (i = 0; validFlags[i] != '\0'; i++)
        {
            if (format[*currentIndex] == validFlags[i])
            {
                flags |= flagValues[i];
                break;
            }
        }

        if (validFlags[i] == '\0')
            break;

        (*currentIndex)++;
    }

    (*currentIndex)--;  /* Adjust the index*/
    return flags;
}
