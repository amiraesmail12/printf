#include "main.h"
/**
 * get_flag - calculate active flages 
 * based on a formatted string and an index.
 * @format: Formatted string
 * @i: take a parameter.
 *
 * Return: flag
 */
int get_flags(const char *format, int *ind)
{
int i;
int curr_ind;
int flags = 0;

const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};


for (curr_ind = *ind + 1; format[curr_ind] != '\0'; curr_ind++)
{
	for (i = 0; FLAGS_CH[i] != '\0'; i++)
	{
		if (format[curr_ind] == FLAGS_CH[i])
		{
			flags |= FLAGS_ARR[i];
			break;
		}

	}
	if (FLAGS_CH[i] == 0)
			break;
}


*ind = curr_ind - 1;
return (flags);

}
