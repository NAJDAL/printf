#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * printPointer - Prints the value of a pointer variable
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int printPointer(va_list args, char buffer[],
    int flags, int width, int precision, int size)
{
    char extraChar = 0, paddingChar = ' ';
    int index = BUFF_SIZE - 2, length = 2, paddingStart = 1; /* length=2, for '0x' */
    unsigned long numAddresses;
    char hexMapping[] = "0123456789abcdef";
    void *address = va_arg(args, void *);

    UNUSED(width);
    UNUSED(size);

    if (address == NULL)
        return write(1, "(nil)", 5);

    buffer[BUFF_SIZE - 1] = '\0';
    UNUSED(precision);

    numAddresses = (unsigned long)address;

    while (numAddresses > 0)
    {
        buffer[index--] = hexMapping[numAddresses % 16];
        numAddresses /= 16;
        length++;
    }

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        paddingChar = '0';

    if (flags & F_PLUS)
    {
        extraChar = '+';
        length++;
    }
    else if (flags & F_SPACE)
    {
        extraChar = ' ';
        length++;
    }

    index++;

    return writePointer(buffer, index, length,
        width, flags, paddingChar, extraChar, paddingStart);
}

/************************* PRINT NON-PRINTABLE *************************/
/**
 * printNonPrintable - Prints ASCII codes in hexadecimal of non-printable characters
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int printNonPrintable(va_list args, char buffer[],
    int flags, int width, int precision, int size)
{
    int i = 0, offset = 0;
    char *str = va_arg(args, char *);

    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        return write(1, "(null)", 6);

    while (str[i] != '\0')
    {
        if (isPrintable(str[i]))
            buffer[i + offset] = str[i];
        else
            offset += appendHexadecimalCode(str[i], buffer, i + offset);

        i++;
    }

    buffer[i + offset] = '\0';

    return write(1, buffer, i + offset);
}

/************************* PRINT REVERSE *************************/
/**
 * printReverse - Prints a string in reverse order.
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int printReverse(va_list args, char buffer[],
    int flags, int width, int precision, int size)
{
    char *str;
    int i, count = 0;

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(size);

    str = va_arg(args, char *);

    if (str == NULL)
    {
        UNUSED(precision);
        str = ")Null(";
    }

    for (i = 0; str[i]; i++)
        ;

    for (i = i - 1; i >= 0; i--)
    {
        char ch = str[i];
        write(1, &ch, 1);
        count++;
    }

    return count;
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
 * printRot13String - Prints a string in ROT13 encoding.
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int printRot13String(va_list args, char buffer[],
    int flags, int width, int precision, int size)
{
    char x;
    char *str;
    unsigned int i, j;
    int count = 0;
    char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(args, char *);

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        str = "(AHYY)";

    for (i = 0; str[i]; i++)
    {
        for (j = 0; input[j]; j++)
        {
            if (input[j] == str[i])
            {
                x = output[j];
                write(1, &x, 1);
                count++;
                break;
            }
        }
        if (!input[j])
        {
            x = str[i];
            write(1, &x, 1);
            count++;
        }
    }

    return count;
}
