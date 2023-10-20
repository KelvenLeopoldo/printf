#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned long num_addrs = (unsigned long)va_arg(types, void *);
	int length = 2;

	if (num_addrs == 0)
		return (write(1, "(nil)", 5));

	char map_to[] = "0123456789abcdef";
	int ind = BUFF_SIZE - 2;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	char padd = (flags & F_ZERO && !(flags & F_MINUS)) ? '0' : ' ';
	int padd_start = 1;

	if (flags & F_PLUS || flags & F_SPACE)
	{
		if (flags & F_PLUS)
			length++;
		else if (flags & F_SPACE)
			length++;
	}

	ind++;

	return (write_pointer(buffer, ind, length, width, flags, padd, 0,
				padd_start));
}

/**
 * print_non_printable - Prints ASCII codes in hexadecimal of
 * non-printable characters
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	return (write(1, "(null)", 6));

	int i = 0, offset = 0;

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - Prints a reversed string.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int count = 0;

	if (str == NULL)
	return (write(1, ")Null(", 6));

	while (str[count])
		count++;

	for (int i = count - 1; i >= 0; i--)
		write(1, &str[i], 1);

	return (count);
}

/**
 * print_rot13string - Print a string in ROT13.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_rot13string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int count = 0;

	if (str == NULL)
		str = "(AHYY)";

	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (unsigned int i = 0; str[i]; i++)
	{
		char x = str[i];

		for (unsigned int j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				break;
			}
		}

		write(1, &x, 1);
		count++;
	}

	return (count);
}
