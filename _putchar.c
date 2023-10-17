#include "main.h"

/**
 * _putchar - funtion that writes the character c  to stdout
 * @c: Character to print
 *
 * Return: On success 1.
 * On error. -1 is returned. and error is defined appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, -1));
}
