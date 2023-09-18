#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to stdout
 * @c: parameter
 * Return: 0
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints a character
 * @args: parameter
 * Return: Always 0
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Prints a string
 * @args: arges
 * Return: Always 0
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}

	return (count);
}

/**
 * print_percent - Prints a percent symbol
 * @args: parameter
 * Return: Always 0
 */
int print_percent(__attribute__((unused)) va_list args)
{
	return (_putchar('%'));
}

/**
 * _printf - Custom printf function
 * @format: parameter
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	va_list args;
	char c;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		c = format[i];
		if (c != '%' || format[i + 1] == '\0')
		{
			printed_chars += _putchar(c);
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				printed_chars += _putchar('%');
			}
			else
			{
				int (*print_func)(va_list) = NULL;

				switch (format[i])
				{
					case 'c':
						print_func = print_char;
						break;
					case 's':
						print_func = print_string;
						break;
					case '%':
						print_func = print_percent;
						break;
				}
				if (print_func != NULL)
				{
					printed_chars += print_func(args);
				}
				else
				{
					printed_chars += _putchar('%');
					printed_chars += _putchar(format[i]);
				}
			}
		}
	}

	va_end(args);
	return (printed_chars);
}
