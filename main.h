#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

struct FormatSpecifier {
    char format;
    int (*function)(va_list, char[], int, int, int, int);
};

typedef struct FormatSpecifier FormatSpecifier;

int _printf(const char *format, ...);
int handlePrint(const char *format, int *currentIndex, va_list arguments, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int printChar(va_list arguments, char buffer[], int flags, int width, int precision, int size);
int printString(va_list arguments, char buffer[], int flags, int width, int precision, int size);
int printPercent(va_list arguments, char buffer[], int flags, int width, int precision, int size);

/* Functions to print numbers */
int printInt(va_list arguments, char buffer[], int flags, int width, int precision, int size);
int printBinary(va_list arguments, char buffer[], int flags, int width, int precision, int size);
int printUnsigned(va_list arguments, char buffer[], int flags, int width, int precision, int size);
int printOctal(va_list arguments, char buffer[], int flags, int width, int precision, int size);
int printHexadecimal(va_list arguments, char buffer[], int flags, int width, int precision, int size);
int printHexadecimalUpper(va_list arguments, char buffer[], int flags, int width, int precision, int size);

int printHexadecimal(va_list arguments, char mapTo[], char buffer[], int flags, char flagChar, int width, int precision, int size);

/* Function to print non-printable characters */
int printNonPrintable(va_list arguments, char buffer[], int flags, int width, int precision, int size);

/* Function to print memory address */
int printPointer(va_list arguments, char buffer[], int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int getFlags(const char *format, int *currentIndex);
int getWidth(const char *format, int *currentIndex, va_list arguments);
int getPrecision(const char *format, int *currentIndex, va_list arguments);
int getSize(const char *format, int *currentIndex);

/* Function to print a string in reverse */
int printReverse(va_list arguments, char buffer[], int flags, int width, int precision, int size);

/* Function to print a string in ROT13 */
int printRot13String(va_list arguments, char buffer[], int flags, int width, int precision, int size);

/* Width handler */
int handleWriteChar(char character, char buffer[], int flags, int width, int precision, int size);
int writeNumber(int isNegative, int index, char buffer[], int flags, int width, int precision, int size);
int writeNum(int index, char buffer[], int flags, int width, int precision, int length, char paddingChar, char extraChar);
int writePointer(char buffer[], int index, int length, int width, int flags, char paddingChar, char extraChar, int paddingStart);
int writeUnsigned(int isNegative, int index, char buffer[], int flags, int width, int precision, int size);

/****************** UTILS ******************/
int isPrintable(char character);
int appendHexaCode(char asciiCode, char buffer[], int index);
int isDigit(char character);

long int convertSizeNumber(long int number, int size);
long int convertSizeUnsigned(unsigned long int number, int size);

#endif /* MAIN_H */
