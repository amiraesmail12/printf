#include "main.h"
/**
 * write_number - fun
 * @is_negative: List
 * @ind: c
 * @buffer: buffer
 * @precision: precision specifier
 * Return: int.
 */
int write_number(int is_negative, int ind, char buffer[], int precision)
{
        int length = BUFF_SIZE - ind - 1;
        char extra_c = 0;

        (void)(precision);
        if (is_negative)
                extra_c = '-';
        if (extra_c)
                buffer[--ind] = extra_c;
        return (write(1, &buffer[ind], length));
}
