#include "main.h"
#include <stdlib.h>

/**
 * get_flags - gets the flag from the string
 * @s: the string to get the flag from
 * Return: a flag
 */
char *get_flags(const char **s)
{
	char flags[] = {'-', '+', ' ', '#', '0'};
	int x, j = 0;
	char *flag = malloc(sizeof *flag * 6);

	if (flag == NULL)
		return (NULL);

	for (x = 0; x < 5; x++)
		if (in_flags(*(*s), flags))
		{
			flag[j++] = *(*s);
			(*s)++;
		}
	flag[j] = '\0';
	return (flag);
}

/**
 * get_width - gets the width from the string
 * @s: the string to get the width from
 * Return: a width
 */
int get_width(const char **s)
{
	char p[1024];
	int x = 0;

	for (; *(*s) >= '0' && *(*s) <= '9'; (*s)++, x++)
		p[x] = *(*s);
	p[x] = '\0';

	if (x == 0)
		return (-1);

	return (_atoi(p));
}

/**
 * get_precision - gets the precision from the string
 * @s: the string to get the precision from
 * Return: a precision
 */
int get_precision(const char **s)
{
	char p[1024] = "-1";
	int x = 0;
	*(*s) == '.' ? (*s)++ : 0;
	for (; *(*s) >= '0' && *(*s) <= '9'; (*s)++, x++)
		p[x] = *(*s);
	if (x != 0)
		p[x] = '\0';
	return (_atoi(p));
}

/**
 * get_length - gets the length format of the string
 * @s: the string to get the length from
 * Return: a length
 */
int get_length(const char **s)
{
	char length[] = {'h', 'l', 'L'};
	int x;
	char l = -1;

	for (x = 0; x < 3; x++)
		if (*(*s) == length[x])
		{
			l = length[x];
			(*s)++;
			break;
		}
	return (l);
}

/**
 * get_specifier - gets the specifier of the string
 * @s: the string to get the specifier from
 * Return: a specifier
 */
char get_specifier(const char **s)
{
	char *specifiers = "cs%diboxXurRpS";
	int x;
	char specifier = -1;

	for (x = 0; x < 14; x++)
		if (*(*s) == specifiers[x])
		{
			specifier = specifiers[x];
			break;
		}
	return (specifier);
}
