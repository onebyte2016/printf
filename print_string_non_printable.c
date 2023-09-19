#include "main.h"

/**
 * print_string_non_printable - prints a string
 * @args: the string to print
 * @format: format struct
 * @count: pointer to count of characters printed
 * Return: void
 */
void print_string_non_printable(va_list list, format_t format, void *count)
{
	char *str = va_arg(list, char *);
	int x;

	UNUSED(format);

	if (str == NULL)
		str = "(null)";

	for (x = 0; str[x]; x++)
	{
		if (str[x] < 32 || str[x] >= 127)
		{
			_puts("\\x0", count);
			print_hex_helper(str[x], HEXADECIMAL_BASE_UPPER, count);
		}
		else
			_putchar(str[x], count);
	}
}
