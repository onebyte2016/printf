#include "main.h"

/**
 * print_char - Helper function to write a character
 * @c: argument passed
 * Return: Always 0
 */
int print_char(char c)
{
	putchar(c);
	return (1);
}

/**
 * print_str - Helper function to write a character
 * @str: argument passed
 * Return: Always 0
 */
int print_str(const char *str)
{
	int chars_printed = 0;

	while (*str)
	{
		chars_printed += print_char(*str);
		str++;
	}
	return (chars_printed);
}

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int chars_printed = 0;
	int i;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			char specifier = format[i];

			switch (specifier)
			{
				case 'c':
					chars_printed += print_char(va_arg(args, int));
					break;
				case 's':
					chars_printed += print_str(va_arg(args, const char *));
					break;
				case '%':
					chars_printed += print_char('%');
					break;
				default:
					chars_printed += print_char('%');
					chars_printed += print_char(specifier);
			}
		}
		else
		{
			chars_printed += print_char(format[i]);
		}
	}

	va_end(args);
	return (chars_printed);
}
