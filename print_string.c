#include "main.h"
#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @s: string to get length of
 * Return: length of string
 */
int _strlen(const char *s)
{
	int x;

	for (x = 0; s[x]; x++)
		;

	return (x);
}

/**
 * print_string - prints a string
 * @list: va_list of arguments
 * @format: format struct
 * @count: pointer to count of characters printed
 * Return: void
 */
void print_string(va_list list, format_t format, void *count)
{
	char *str = va_arg(list, char *);

	UNUSED(format);

	if (str == NULL)
	{
		fprintf(stdout, "(null)");
		*(int *)count += 6;
	}
	else
	{
		int written = write(STDOUT_FILENO, str, _strlen(str));

		if (written == -1)
		{
		}
		else
		{
			*(int *)count += written;
		}
	}
}
