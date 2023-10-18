#include "main.h"

 /**
 * printf_funct_char - Function that prints a character.
 * @types: List of arguments.
 * @buffer: Buffer array to handle printing.
 * @flags: Calculate active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int printf_funct_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	int chars_written = 0;

	if (width > 1)
	{
		if (!(flags & F_MINUS))
		{
			for (int i = 1; i < width; i++)
			{
				buffer[chars_written++] = ' ';
			}
		}
		buffer[chars_written++] = c;
		if (flags & F_MINUS)
		{
			for (int i = 1; i < width; i++)
			{
				buffer[chars_written++] = ' ';
			}
		}
	} else
	{
		buffer[chars_written++] = c;
	}

	return (chars_written);
}
