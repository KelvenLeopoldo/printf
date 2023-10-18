#include "main.h"

/**
 * printf_funct_int - Print an integer.
 * @types: List of arguments.
 * @buffer: Buffer array for printing.
 * @flags: Calculate active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int printf_funct_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	long int n = va_arg(types, long int);
	int chars_written = 0, num_digits = 0;

	if (n < 0)
		buffer[chars_written++] = '-';
		n = -n;
	if (n == 0)
	{
		num_digits = 1;
	} else
	{
		long int temp = n;

		while (temp > 0)
		{
			temp /= 10;
			num_digits++;
		}
	}

	if (precision > num_digits)
		for (int i = 0; i < precision - num_digits; i++)
			buffer[chars_written++] = '0';

	for (char num_buffer[20]; num_digits-- > 0;)
		num_buffer[num_digits] = '0' + (n % 10);
		buffer[chars_written++] = num_buffer[num_digits];
		n /= 10;

	if (width > chars_written)
		for (int i = 0; i < width - chars_written; i++)
			buffer[chars_written++] = ' ';

	return (chars_written);
}
