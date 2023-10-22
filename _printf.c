#include "_printf.h"

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int j = 0;
    int count = 0;

    /* Initialize the argument list */
    va_start(args, format);

    /* Loop through the format string */
    while (format && format[i])
    {
        /* If not a format specifier, write the character */
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            count++;
            i++;
            continue;
        }

        /* If a format specifier, find the matching function */
        i++;
        j = 0;
        while (formats[j].specifier)
        {
            if (format[i] == formats[j].specifier[0])
            {
                /* Call the conversion function and update the count */
                count += formats[j].f(args);
                break;
            }
            j++;
        }
        i++;
    }

    /* Clean up the argument list */
    va_end(args);

    /* Return the number of characters printed */
    return (count);
}
