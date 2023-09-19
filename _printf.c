#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...);
int print_character(char c);
int print_string(const char *str);
int print_percent(void);

/**
 * main - entry point
 * Return: zero for success
 */

int main(void)
{
	_printf("Hello, %c World! %s %%%c\n", 'C', "This is a test", 'R');
	return (0);
}

/**
 * _printf - Custom printf function
 * @format: argument passed
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	int output_print = 0;
	va_list args_list;


	if (format == NULL)
		return (-1);
	va_start(args_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			printed_chars += print_character(*format);

			output_print += write_char(*format);

		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				char c = va_arg(args, int);

				printed_chars += print_character(c);
			}
			else if (*format == 's')
			{
				const char *str = va_arg(args, const char *);

				printed_chars += print_string(str);
			}
			else if (*format == '%')
			{
				printed_chars += print_percent();

			if (*format == '%')
			{
				output_print += write_char('%');
			}
			else if (*format == 'c')
			{
				char c = va_arg(args_list, int);

				output_print += write_char(c);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args_list, char *);

				output_print += write_string(str);

			}
		}
		format++;
	}



	va_end(args);
	return (printed_chars);
}

/**
 * print_character - prints a character
 * @c: character argument
 * Return: 1
 */

int print_character(char c)
{
	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @str: string
 * Return: success
 */

int print_string(const char *str)
{
	int printed_chars = 0;

	while (*str)
	{
		_putchar(*str);
		str++;
		printed_chars++;
	}
	return (printed_chars);
}

/**
 * print_percent - prints a percent
 * Return: 1
 */

int print_percent(void)
{
	_putchar('%');
	return (1);
}



	va_end(args_list);
	return (output_print);
}

