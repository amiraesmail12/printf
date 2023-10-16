#include "main.h"
/**
 * handle_print - func
 * @fmt: string
 * @ind: index
 * @list:list
 * @buffer: buffer
 * @p:int
 * Return: int
*/
int handl_print(const char *fmt, int *ind, va_list list, char buffer[], int p)
{
	int i;
	int len = 0;
	int printed_chars = -1;

	print_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'\02', NULL}
	};
	for (i = 0; (fmt_types[i].specifier) != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].specifier)
			return (fmt_types[i].fun(list, buffer, p));
	if (fmt_types[i].specifier == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			len += write(1, " ", 1);
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (printed_chars);
}
