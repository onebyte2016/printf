#include "main.h"
#include <stdio.h>

/**
 * print_reverse - prints a string in reverse
 * @args: the string to print
 * @format: format struct
 * @count: pointer to count of characters printed
 * Return: void
*/
void print_reverse(va_list list, format_t format, void *count)
{
	char *str = va_arg(list, char *);
	int x = 0;

	UNUSED(format);

	if (str == NULL)
		return ;

	while (str[x])
		x++;
	while (x--)
		_putchar(str[x], count);
}
