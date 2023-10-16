#include "main.h"

/**
 * print_char - fun
 * @types: list
 * @buffer: buffer
 * @precision: int
 * Return: int
 */
int print_char(va_list types, char buffer[], int precision)
{
	char c = va_arg(types, int);

	return (handle_char(c, buffer, precision));
}
/**
 * handle_char - fun
 * @c: char
 * @buffer: buffer
 * @precision: int
 * Return: int
*/
int handle_char(char c, char buffer[], int precision)
{
	int i = 0;

	(void)(precision);
	buffer[i++] = c;
	buffer[i] = '\0';
	return (write(1, &buffer[0], 1));
}
/**
 * print_string - fun
 * @types: list
 * @buffer: buffer
 * @precision: int
 * Return:int
 */
int print_string(va_list types, char buffer[], int precision)
{
	int length = 0;
	char *str = va_arg(types, char *);

	(void)(buffer);
	(void)(precision);
	(void)(types);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;
	return (write(1, str, length));
}
/**
 * print_percent - fun
 * @types: list
 * @buffer: buffer
 * @precision: int
 * Return:in
*/
int print_percent(va_list types, char *buffer, int precision)
{
	(void)(types);
	(void)(precision);
	(void)(buffer);
	return (write(1, "%%", 1));
}
/**
 * print_int - fun
 * @types: lidt
 * @buffer: buffer
 * @precision: P
 * Return: int
 */
int print_int(va_list types, char buffer[], int precision)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;


	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, precision));
}
