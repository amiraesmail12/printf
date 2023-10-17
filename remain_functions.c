#include "main.h"

/**
 * print_char - fun
 * @types: list
 * @buffer: buffer
 * @flags: flag
 * @width: width
 * @precision: P
 * @size: size
 * Return: int
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{


	char c = va_arg(types, int);

	return (handle_char(c, buffer, flags, width, precision, size));
}
/**
 * handle_char - fun
 * @c: char
 * @buffer: buffer
 * @flags: flag
 * @width: width
 * @precision: P
 * @size: size
 * Return: int
*/
int handle_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	(void)(precision);
	buffer[i++] = c;
	buffer[i] = '\0';
	return (write(1, &buffer[0], 1));
}
/**
 * print_string - fun
 * @types: list
 * @buffer: buffer
 * @flags: flag
 * @width: width
 * @precision: P
 * @size: size
 * Return:int
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

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
 * @flags: flag
 * @width: width
 * @precision: P
 * @size: size

 * Return:in
*/
int print_percent(va_list types, char *buffer,
		int flags, int width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	(void)(types);
	(void)(precision);
	(void)(buffer);
	return (write(1, "%%", 1));
}
/**
 * print_int - fun
 * @types: lidt
 * @buffer: buffer
 * @flags: flag
 * @width: width
 * @precision: P
 * @size: size
 * Return: int
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

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

	return (write_number(is_negative, i, buffer,
				flags, width, precision, size));
}
