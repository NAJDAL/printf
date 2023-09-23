#include "main.h"

/**
 * isCharPrintable - Check if a character is printable
 * @c: The character to check
 *
 * Return: 1 if the character is printable, 0 otherwise
 */
int isCharPrintable(char c)
{
    return (c >= 32 && c < 127);
}

/**
 * appendHexCode - Append ASCII in hexadecimal code to the buffer
 * @buffer: The character buffer
 * @index: The index at which to start appending
 * @asciiCode: The ASCII code
 *
 * Return: Always 3
 */
int appendHexCode(char buffer[], int index, char asciiCode)
{
    const char mapTo[] = "0123456789ABCDEF";

    buffer[index++] = '\\';
    buffer[index++] = 'x';
    buffer[index++] = mapTo[asciiCode / 16];
    buffer[index] = mapTo[asciiCode % 16];

    return 3;
}

/**
 * isCharDigit - Check if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int isCharDigit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * convertNumber - Cast a number to the specified size
 * @num: The number to be casted
 * @size: The size indicating the type to cast to
 *
 * Return: Casted value of num
 */
long int convertNumber(long int num, int size)
{
    if (size == S_LONG)
        return num;
    else if (size == S_SHORT)
        return (short)num;

    return (int)num;
}

/**
 * convertUnsignedNumber - Cast an unsigned number to the specified size
 * @num: The unsigned number to be casted
 * @size: The size indicating the type to cast to
 *
 * Return: Casted value of num
 */
unsigned long int convertUnsignedNumber(unsigned long int num, int size)
{
    if (size == S_LONG)
        return num;
    else if (size == S_SHORT)
        return (unsigned short)num;

    return (unsigned int)num;
}
