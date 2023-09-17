#include "main.h"

/**
 * write_char - Helper function to write a character
 * @c: argument passed
 * Return: Always 0
 */
static int write_char(char c)
{
	return (write(1, &c, 1));
}
/**
 * write_string - Helper function to write a string
 * @str: argument passed
 * Return: Always
 */
static int write_string(char *str)
{
	int len = 0;

	while (*str)
	{
		write_char(*str);
		str++;
		len++;
	}
	return (len);
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
			output_print += write_char(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
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
	va_end(args_list);
	return (output_print);
}
