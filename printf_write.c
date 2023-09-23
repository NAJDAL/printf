#include "main.h"

/************************* WRITE HANDLE *************************/

/**
 * writeChar - Write a single character
 * @c: The character to be written
 * @buffer: Buffer array to handle print
 * @flags: Flag that calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters written
 */
int writeChar(char c, char buffer[], int flags, int width, int precision, int size)
{
    int index = 0;
    char paddingChar = ' ';

    UNUSED(precision);
    UNUSED(size);

    if (flags & F_ZERO)
        paddingChar = '0';

    buffer[index++] = c;
    buffer[index] = '\0';

    if (width > 1)
    {
        buffer[BUFF_SIZE - 1] = '\0';
        for (index = 0; index < width - 1; index++)
            buffer[BUFF_SIZE - index - 2] = paddingChar;

        if (flags & F_MINUS)
            return write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - index - 1], width - 1);
        else
            return write(1, &buffer[BUFF_SIZE - index - 1], width - 1) + write(1, &buffer[0], 1);
    }

    return write(1, &buffer[0], 1);
}

/************************* WRITE NUMBER *************************/

/**
 * writeNumber - Write a number
 * @isNegative: Flag indicating if the number is negative
 * @index: Index at which the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @flags: Flags specifier
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters written
 */
int writeNumber(int isNegative, int index, char buffer[], int flags, int width, int precision, int size)
{
    int length = BUFF_SIZE - index - 1;
    char paddingChar = ' ';
    char extraChar = 0;

    UNUSED(size);

    if (flags & F_ZERO && !(flags & F_MINUS))
        paddingChar = '0';

    if (isNegative)
        extraChar = '-';
    else if (flags & F_PLUS)
        extraChar = '+';
    else if (flags & F_SPACE)
        extraChar = ' ';

    return writeNum(index, buffer, flags, width, precision, length, paddingChar, extraChar);
}

/**
 * writeNum - Write a number using a buffer
 * @index: Index at which the number starts in the buffer
 * @buffer: Buffer
 * @flags: Flags specifier
 * @width: Width specifier
 * @precision: Precision specifier
 * @length: Number length
 * @paddingChar: Padding character
 * @extraChar: Extra character
 *
 * Return: Number of characters written
 */
int writeNum(int index, char buffer[], int flags, int width, int precision, int length, char paddingChar, char extraChar)
{
    int paddStart = 1;
    int i;

    if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
        return 0; /* printf(".0d", 0)  no characters are printed */
    
    if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
    {
        buffer[index] = paddingChar = ' '; /* width is displayed with padding ' ' */
    }
    
    if (precision > 0 && precision < length)
    {
        paddingChar = ' ';
    }
    
    while (precision > length)
    {
        buffer[--index] = '0';
        length++;
    }

    if (extraChar != 0)
    {
        length++;
    }

    if (width > length)
    {
        for (i = 1; i < width - length + 1; i++)
        {
            buffer[i] = paddingChar;
        }
        buffer[i] = '\0';

        if (flags & F_MINUS && paddingChar == ' ')
        {
            if (extraChar)
            {
                buffer[--index] = extraChar;
            }
            return write(1, &buffer[index], length) + write(1, &buffer[1], i - 1);
        }
        else if (!(flags & F_MINUS) && paddingChar == ' ')
        {
            if (extraChar)
            {
                buffer[--index] = extraChar;
            }
            return write(1, &buffer[1], i - 1) + write(1, &buffer[index], length);
        }
        else if (!(flags & F_MINUS) && paddingChar == '0')
        {
            if (extraChar)
            {
                buffer[--paddStart] = extraChar;
            }
            return write(1, &buffer[paddStart], i - paddStart) +
                write(1, &buffer[index], length - (1 - paddStart));
        }
    }

    if (extraChar)
    {
        buffer[--index] = extraChar;
    }
    return write(1, &buffer[index], length);
}

/**
 * writeUnsigned - Write an unsigned number
 * @isNegative: Flag indicating if the number is negative
 * @index: Index at which the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @flags: Flags specifier
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters written
 */
int writeUnsigned(int isNegative, int index, char buffer[], int flags, int width, int precision, int size)
{
    int length = BUFF_SIZE - index - 1;
    char paddingChar = ' ';

    UNUSED(isNegative);
    UNUSED(size);

    if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
        return 0; /* printf(".0d", 0)  no characters are printed */

    if (precision > 0 && precision < length)
        paddingChar = ' ';

    if (flags & F_ZERO && !(flags & F_MINUS))
        paddingChar = '0';

    if (width > length)
    {
        for (int i = 0; i < width - length; i++)
            buffer[i] = paddingChar;

        buffer[width - length] = '\0';

        if (flags & F_MINUS)
        {
            return write(1, &buffer[index], length) + write(1, buffer, width - length);
        }
        else
        {
            return write(1, buffer, width - length) + write(1, &buffer[index], length);
        }
    }

    return write(1, &buffer[index], length);
}

/**
 * writePointer - Write a memory address
 * @buffer: Buffer array to handle print
 * @index: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Padding character
 * @extraChar: Extra character
 * @paddStart: Index at which padding should start
 *
 * Return: Number of characters written
 */
int writePointer(char buffer[], int index, int length, int width, int flags, char paddingChar, char extraChar, int paddStart)
{
    int i;

    if (width > length)
    {
        for (i = 3; i < width - length + 3; i++)
            buffer[i] = paddingChar;
        
        buffer[i] = '\0';

        if (flags & F_MINUS && paddingChar == ' ')
        {
            buffer[--index] = 'x';
            buffer[--index] = '0';

            if (extraChar)
                buffer[--index] = extraChar;

            return write(1, &buffer[index], length) + write(1, &buffer[3], i - 3);
        }
        else if (!(flags & F_MINUS) && paddingChar == ' ')
        {
            buffer[--index] = 'x';
            buffer[--index] = '0';

            if (extraChar)
                buffer[--index] = extraChar;

            return write(1, &buffer[3], i - 3) + write(1, &buffer[index], length);
        }
        else if (!(flags & F_MINUS) && paddingChar == '0')
        {
            if (extraChar)
                buffer[--paddStart] = extraChar;

            buffer[1] = '0';
            buffer[2] = 'x';

            return write(1, &buffer[paddStart], i - paddStart) +
                write(1, &buffer[index], length - (1 - paddStart) - 2);
        }
    }

    buffer[--index] = 'x';
    buffer[--index] = '0';

    if (extraChar)
        buffer[--index] = extraChar;

    return write(1, &buffer[index], BUFF_SIZE - index - 1);
}
