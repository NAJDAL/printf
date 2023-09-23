#include "main.h"

/**
 * printUnsigned - Print an unsigned number
 * @args: List of arguments
 * @buffer: Buffer to handle printing
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int printUnsigned(va_list args, char buffer[],
    int flags, int width, int precision, int size)
{
    int index = BUFF_SIZE - 2;
    unsigned long int num = va_arg(args, unsigned long int);

    num = convertSizeUnsigned(num, size);

    if (num == 0)
        buffer[index--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[index--] = (num % 10) + '0';
        num /= 10;
    }

    index++;

    return (writeUnsigned(0, index, buffer, flags, width, precision, size));
}

/**
 * printOctal - Print an unsigned number in octal notation
 * @args: List of arguments
 * @buffer: Buffer to handle printing
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int printOctal(va_list args, char buffer[],
    int flags, int width, int precision, int size)
{
    int index = BUFF_SIZE - 2;
    unsigned long int num = va_arg(args, unsigned long int);
    unsigned long int initNum = num;

    UNUSED(width);

    num = convertSizeUnsigned(num, size);

    if (num == 0)
        buffer[index--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[index--] = (num % 8) + '0';
        num /= 8;
    }

    if (flags & F_HASH && initNum != 0)
        buffer[index--] = '0';

    index++;

    return (writeUnsigned(0, index, buffer, flags, width, precision, size));
}

/**
 * printHexadecimal - Print an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer to handle printing
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int printHexadecimal(va_list args, char buffer[],
    int flags, int width, int precision, int size)
{
    return (printHex(args, "0123456789abcdef", buffer,
        flags, 'x', width, precision, size));
}

/**
 * printHexadecimalUpper - Print an unsigned number in upper hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer to handle printing
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int printHexadecimalUpper(va_list args, char buffer[],
    int flags, int width, int precision, int size)
{
    return (printHex(args, "0123456789ABCDEF", buffer,
        flags, 'X', width, precision, size));
}

/**
 * printHex - Print a hexadecimal number in lower or upper case
 * @args: List of arguments
 * @mapTo: Array of values to map the number to
 * @buffer: Buffer to handle printing
 * @flags: Active flags
 * @flagChar: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int printHex(va_list args, char mapTo[], char buffer[],
    int flags, char flagChar, int width, int precision, int size)
{
    int index = BUFF_SIZE - 2;
    unsigned long int num = va_arg(args, unsigned long int);
    unsigned long int initNum = num;

    UNUSED(width);

    num = convertSizeUnsigned(num, size);

    if (num == 0)
        buffer[index--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[index--] = mapTo[num % 16];
        num /= 16;
    }

    if (flags & F_HASH && initNum != 0)
    {
        buffer[index--] = flagChar;
        buffer[index--] = '0';
    }

    index++;

    return (writeUnsigned(0, index, buffer, flags, width, precision, size));
}
