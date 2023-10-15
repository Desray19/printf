#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - A custom function that emulates printf
 * @format: The format string used for printing
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (int i = 0; format[i]; i++)
    {
        if (format[i] != '%')
        {
            putchar(format[i);
            printed_chars++;
        }
        else
        {
            i++; // Move past '%'

            if (format[i] == 'd' || format[i] == 'i')
            {
                int num = va_arg(args, int);
                printf("%d", num); // Print the integer
                printed_chars += countDigits(num);
            }
            else
            {
                putchar('%'); // Print '%' for unsupported format specifiers
                printed_chars++;
                if (format[i])
                {
                    putchar(format[i]);
                    printed_chars++;
                }
            }
        }
    }

    va_end(args);
    return (printed_chars);
}

int countDigits(int num)
{
    int count = 0;
    if (num == 0)
        return 1; // Handle the special case of num = 0
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}
