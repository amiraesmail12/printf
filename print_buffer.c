#include "main.h"
/**
 * print_buffer - write
 * @buffer: string
 * @buff_index: index
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
