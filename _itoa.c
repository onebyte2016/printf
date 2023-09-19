#include <stdlib.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * @str: string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *dup;
	int x, len = _strlen(str);

	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	for (x = 0; x < len; x++)
		dup[x] = str[x];
	dup[len] = '\0';
	return (dup);
}

/**
 * reverse_string - reverses a string
 * @str: string to reverse
 * Return: pointer to the reversed string
 */
char *reverse_string(char *str)
{
	int start = 0, end = _strlen(str) - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}

	return (str);
}

/**
 * _itoa - converts an integer to a string
 * @value: integer to convert
 * @base: base to convert to
 * Return: pointer to the converted string
 */
char *_itoa(ssize_t value, char *base)
{
	/*ssize_t quotient = ABS(value), x = 0;*/
	ssize_t quotient = value, x = 0;

	int base_len = _strlen(base);
	char *result = malloc(get_number_length(value) + 1);

	if (base_len < 2 || base_len > 16 || result == NULL)
		return (NULL);

	do {
		result[x++] = base[quotient % base_len];
		quotient /= base_len;
	} while (quotient);

	if (value < 0 && base_len == 10)
		result[x++] = '-';

	result[x] = '\0';
	return (reverse_string(result));
}

/**
 * _utoa - converts an unsigned integer to a string
 * @value: integer to convert
 * @base: base to convert to
 * Return: pointer to the converted string
 */
char *_utoa(size_t value, char *base)
{
	/*ssize_t quotient = ABS(value), x = 0;*/
	size_t quotient = value, x = 0;

	int base_len = _strlen(base);
	char *result = malloc(get_number_length(value) + 1);

	if (result == NULL)
		return (NULL);

	if (base_len < 2 || base_len > 16)
		return (NULL);

	do {
		result[x++] = base[quotient % base_len];
		quotient /= base_len;
	} while (quotient);

	result[x] = '\0';
	return (reverse_string(result));
}
