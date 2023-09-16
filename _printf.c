#include "main.h"
/**
 * _printf - function for printing output
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
			write(1, format, 1);
			output_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				output_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args_list, int);

				write(1, &c, 1);
				output_print++;

			}
			else if (*format == 's')
			{
				char *str = va_arg(args_list, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				output_print = str_len;
			}
		}
		format++;
	}
	va_end(args_list);
	return (output_print);
}
