#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _printf(const char *format, ...);
int printf_funct_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int printf_funct_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int printf_funct_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int printf_funct_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int printf_funct_string(va_list types, char buffer[], int flags, int width, int precision, int size);

#endif
