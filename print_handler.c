#include "main.h"
/**
 * handle_print - func
 * @fmt: string
 * @ind: index
 * @list:list
 * @buffer: buffer
 * @flags: flag
 * @width: width
 * @p:int
 * @size: size
 * Return: int
*/
int handl_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int p, int size)
{
	int i;
	int len = 0;
	int printed_chars = -1;

	print_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\022', NULL}

	};
	for (i = 0; (fmt_types[i].specifier) != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].specifier)
			return (fmt_types[i].fun(list, buffer, flags, width, p, size));
	if (fmt_types[i].specifier == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (printed_chars);
}
