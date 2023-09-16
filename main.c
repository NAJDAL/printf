#include "main.h"

int main(void)
{
    /* Task 0: Basic Printf */
    _printf("Character: [%c]\n", 'A');
    _printf("String: [%s]\n", "Hello, World!");
    _printf("Percent: [%%]\n");

    /* Task 1: Handling d and i */
    _printf("Integer (d): [%d]\n", 12345);
    _printf("Integer (i): [%i]\n", -9876);

    /* Task 2: Custom Conversion Specifier b */
    _printf("Binary (b): [%b]\n", 98);

    /* Task 3: Handling u, o, x, and X */
    _printf("Unsigned (u): [%u]\n", 4294967295);
    _printf("Octal (o): [%o]\n", 255);
    _printf("Hexadecimal (x): [%x]\n", 255);
    _printf("Hexadecimal (X): [%X]\n", 255);

    /* Task 4: Using a Local Buffer */
    /* This task doesn't require specific test cases; you can continue testing other features. */

    /* Task 5: Custom Conversion Specifier S */
    _printf("Custom String (S): [%S]\n", "Hello\tWorld\x07!");

    /* Task 6: Handling p Conversion Specifier */
    int var = 42;
    _printf("Pointer (p): [%p]\n", &var);

    /* Task 7: Flag Characters +, space, and # */
    _printf("Positive with + flag: [%+d]\n", 123);
    _printf("Positive with space flag: [% d]\n", 456);
    _printf("Hash flag with x: [%#x]\n", 15);

    /* Task 8: Length Modifiers l and h */
    long long_var = 123456789012345;
    short short_var = 32767;
    _printf("Long (l): [%ld]\n", long_var);
    _printf("Short (h): [%hd]\n", short_var);

    /* Task 9: Field Width */
    _printf("Field width: [%10s]\n", "Hello");
    _printf("Field width with 0: [%010d]\n", 42);

    /* Task 10: Precision */
    _printf("Precision: [%.3f]\n", 3.14159265359);

    /* Task 11: Flag Character 0 */
    _printf("0 flag: [%010d]\n", 42);

    /* Task 12: Flag Character - */
    _printf("- flag: [%-10s]\n", "World");

    /* Task 13: Custom Conversion Specifier %r (reversed string) */
    _printf("Reversed String (r): [%r]\n", "abcdef");

    /* Task 14: Custom Conversion Specifier %R (ROT13-encoded string) */
    _printf("ROT13 String (R): [%R]\n", "Hello, World!");

    /* Task 15: All Options Combined */
    /* This task combines all the features, so you can create a comprehensive test case here. */

    return (0);
}
