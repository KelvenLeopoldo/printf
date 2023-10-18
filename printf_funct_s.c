#include "main.h"

/**
 * printf_funct_string - Print a string.
 * @types: List of arguments.
 * @buffer: Buffer array for printing.
 * @flags: Calculate active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int printf_funct_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int chars_written = 0;

	if (str == NULL)
		str = "(null)";

	int str_length = 0;

	while (str[str_length] != '\0')
		str_length++;

	if (precision < 0 || precision > str_length)
		precision = str_length;

	if (width > precision && !(flags & F_MINUS))
	{
		for (int i = 0; i < width - precision; i++)
			buffer[chars_written++] = ' ';
	}

	for (int i = 0; i < precision; i++)
		buffer[chars_written++] = str[i];

	if (width > precision && (flags & F_MINUS))
	{
		for (int i = 0; i < width - precision; i++)
			buffer[chars_written++] = ' ';
	}

	return (chars_written);
}
