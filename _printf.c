#include "main.h"


/**
 * _printf - like printf
 * @format: string
 * Return: int
*/

int _printf(const char *format, ...)
{
	int i;
	int precision;
	int printed = 0;
	int printed_chars = 0;
	int buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			precision = get_precision(format, &i, list);
			i++;
			printed = handl_print(format, &i, list, buffer, precision);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
