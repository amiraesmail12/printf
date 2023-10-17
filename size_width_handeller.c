#include "main.h"
/**
 * get_width - calculate the width to be printed.
 * @format: formated string
 * @args: list of arguments ot be printed.
 * list: list of args
 *
 * Return: the width.
 */
int get_width(const char *format, int *ind, va_list list)
{
int curr_ind;
int width;
for (curr_ind = *ind + 1; format[curr_ind] != '\0'; curr_ind++)
{
	if (is_digit(format[curr_ind]))
	{
		width *= 10;
		width += format[curr_ind] - '0';
	}
	else if (format[curr_ind] == '*')
	{
		curr_ind++;
		width = va_arg(list, int);
		break;
	}
	else
		break;
}
*ind = curr_ind - 1;
return (width);

}




/**
 * get_size - calculate the size
 * @format: A pointer to a formatted string
 * in which the arguments will be printed.
 * @ind: A pointer to the current index in the format string.
 *
 * Return: size
 */
int get_size(const char *format, int *ind)
{
int curr_ind = *ind + 1;
int size = 0;
if (format[curr_ind] == 'l')
	size = LONG_SIZE;
else if (format[curr_ind] == 'h')
	size = SHORT_SIZE;

if (size == 0)
	*ind = curr_ind - 1;
else 
	*ind = curr_ind;


return (size);
}





/*** Collaborators: Amira & Salma ***/
