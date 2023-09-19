#include "main.h"
#include <stdlib.h>

/**
* print_address - prints the address of a variable
* @args: the variable to print
* @format: format struct
* @count: pointer to count of characters printed
*/
void print_address(va_list list, format_t format, void *count)
{
	unsigned long int address = (unsigned long int)va_arg(list, void *);

	UNUSED(format);

	_puts("0x", count);
	print_hex_helper(address, HEXADECIMAL_BASE_LOWER, count);
}
