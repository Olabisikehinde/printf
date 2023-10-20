#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Structure for format specifier and function pointer */
typedef struct format_s
{
    char *specifier;
    int (*f)(va_list);
} format_t;

/* Array of format specifiers and functions */
format_t formats[] = {
    {"c", print_char},
    {"s", print_string},
    {"d", print_int},
    {"i", print_int},
    {"v", print_vint},
    {"o", print_octal},
    {"t", print_tetra},
    {"X", print_HEX},
    {"p", print_pointers},
    {"S", print_S},
    {"r", print_r},
    {"R", print_R},
    {"C", print_C},
    {"b", print_binary},
    {NULL, NULL}
};

/* Declaration of custom printf function */
int _printf(const char *format, ...);

/* Declaration of conversion functions */
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_uint(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_pointer(va_list args);
int print_S(va_list args);
int print_r(va_list args);
int print_R(va_list args);
int print_C(va_list args);
int print_binary(va_list args);

/* Declaration of helper functions */
char *convert(unsigned int num, int base, int uppercase);
void reverse(char *str);
char *rot13(char *str);

#endif /* MAIN_H */
