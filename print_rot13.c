#include "main.h"

/**
 * print_rot13 - prints a string in rot13
 * @list: va_list of arguments
 * @format: format struct
 * @count: pointer to count of characters printed
 */
void print_rot13(va_list list, format_t format, void *count)
{
	char *str = va_arg(list, char *);
	int x = 0;

	UNUSED(format);

	if (str == NULL)
		return;

	while (str[x])
	{
		if ((str[x] >= 'a' && str[x] <= 'm') || (str[x] >= 'A' && str[x] <= 'M'))
			_putchar(str[x] + 13, count);
		else if ((str[x] >= 'n' && str[x] <= 'z') ||
			(str[x] >= 'N' && str[x] <= 'Z'))
			_putchar(str[x] - 13, count);
		else
			_putchar(str[x], count);
		x++;
	}
}
