/**
 * _atoi - converts a string to an integer
 * @str: string to convert
 * Return: integer value of string
 */

int _atoi(const char *str)
{
	int result = 0, sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;

	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');

	return (result * sign);
}
