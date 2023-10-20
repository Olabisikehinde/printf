#include "_printf.h"

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int j = 0;
    int i = 0;
    int count = 0;

    /* Initialize the argument list */
    va_start(args, format);

    /* Loop through the format string */
    while (format && format[j])
    {
        /* If not a format specifier, write the character */
        if (format[j] != '%')
        {
            write(1, &format[j], 1);
            count++;
            j++;
            continue;
        }

        /* If a format specifier, find the matching function */
        j++;
        i = 0;
        while (formats[j].specifier)
        {
            if (format[j] == formats[i].specifier[0])
            {
                /* Call the conversion function and update the count */
                count += formats[i].f(args);
                break;
            }
            i++;
        }
        j++;
    }

    /* Clean up the argument list */
    va_end(args);

    /* Return the number of characters printed */
    return (count);
}
