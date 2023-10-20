#include "main.h"

/**
 * print_int - prints a signed decimal integer
 * @args: variable argument list
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int k;
    int count = 0;
    char *s;

    /* Get the integer from the argument list */
    k = va_arg(args, int);

    /* Convert the integer to a string */
    s = convert(k, 10, 0);

    /* Check if the string is NULL */
    if (s == NULL)
        return (-1);

    /* Loop through the string and write each character */
    while (*s)
    {
        write(1, s, 1);
        s++;
        count++;
    }

    /* Return the number of characters printed */
    return (count);
}
