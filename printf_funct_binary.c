#include "main.h"

/**
 * printf_funct_binary - Prints a binary representation of an unsigned integer.
 * @types: List of arguments.
 * @buffer: Buffer array to handle printing.
 * @flags: Calculate active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int printf_funct_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n = va_arg(types, unsigned int);
	int chars_written = 0;

	int binary_digits[32];

	for (int i = 31; i >= 0; i--)
	{
		binary_digits[i] = n & 1;
		n >>= 1;
	}

	int start = 0;

	for (int i = 0; i < 32; i++)
	{
		if (binary_digits[i] || i == 31)
		{
			buffer[chars_written++] = '0' + binary_digits[i];
			start = 1;
		} else if (start)
		{
			buffer[chars_written++] = '0';
		}
	}

	if (chars_written == 0)
	{
		buffer[chars_written++] = '0';
	}

	return (chars_written);
}
