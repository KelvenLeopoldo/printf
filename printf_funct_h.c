#include "main.h"

/**
 * print_hexadecimal - Function that prints an unsigned
 * number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
			flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Function that prints an unsigned
 * number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
			flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper case
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Flag character (lower or upper case)
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	unsigned long int num = convert_size_unsgnd(va_arg(types,
				unsigned long int), size);
	unsigned long int init_num = num;

	num = convert_size_unsgnd(num, size);

	int i = BUFF_SIZE - 2;

	if (!num)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
		buffer[i--] = map_to[num % 16], num /= 16;

	if (flags & F_HASH && init_num)
		buffer[i--] = flag_ch, buffer[i--] = '0';

	return (write_unsgnd(0, i + 1, buffer,
				flags, width, precision, size));
}
