#include <stdio.h>
#include <stdarg.h>

/**
 * custom_printf - handles custom specifier %r
 *
 * return: zero
 */

int custom_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{

			_putchar(*format);
		}	
		else
		{
			format++;
			if (*format == 'r')
			{
				printf("Replacement for %r");
			}
		}
		
		format++;
	}
	va_end(args);
	return 0;
}

