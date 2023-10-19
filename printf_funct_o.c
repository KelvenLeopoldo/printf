#include "main.h"

/**
 * printf_funct_o - Function that prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printf_funct_o(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned long int num = convert_size_unsgnd(va_arg(types,
				unsigned long int), size);
	char num_buffer[20];
	int i = 19;

	if (num == 0)
		num_buffer[i--] = '0';

	while (num > 0)
	{
		num_buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && num_buffer[i + 1] != '0')
		num_buffer[i--] = '0';

	int num_digits = 19 - i;
	int chars_written = write_unsgnd(0, i + 1, num_buffer, flags,
			width, precision, size);
	return (chars_written);
}
