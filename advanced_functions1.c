#include "main.h"
/************************* PRINT BINARY *************************/

/**
 * print_binary - the unsigned int argument is converted to binary
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: binary conversion of the number.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int counter;
/*Unused parameters*/
UNUSED(buffer);
UNUSED(width);
UNUSED(flags);
UNUSED(size);
UNUSED(precision);

n = va_arg(types, unsigned int);
m = 2147483648;
a[0] = n / m;

for (i = 1; i < 32; i++)
{
	m /= 2;
	a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, counter = 0; i < 32; i++)
{
	sum += a[i];
	if (sum || i == 31)
	{
		char z = '0' + a[i];

		write(1, &z, 1);
		counter++;
	}
}
return (counter);
}






/************************* PRINT UNSIGNED NUMBER *************************/

/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size
 *
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);

num = convert_size_unsgnd(num, size);

if (num == 0)
{
	buffer[i--] = '0';
}
buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
	buffer[i--] = (num % 10) + '0';
	num /= 10;
}

i++;

return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}




/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size
 *
 * Return: Number in hexadecimal
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
	flags, 'x', width, precision, size));
}



/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size
 *
 * Return: Number in upper Hexadecimal
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}




/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specification
 *
 * Return: Number prints hexa lower || upper
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);
num = convert_size_unsgnd(num, size);

if (num == 0)
	buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
	buffer[i--] = map_to[num % 16];
	num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
	buffer[i--] = flag_ch;
	buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/*Colaporators: Amira & Samar*/
