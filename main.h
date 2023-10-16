#ifndef MAIN_HH
#define MAIN_HH
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define BUFF_SIZE 1024


/**
 * struct to_print - struct for specifier
 * @specifier: specifier or datatype
 * @fun: pointer to print function
*/
typedef struct to_print
{
	char specifier;
	int (*fun)(va_list, char[], int);
} print_t;

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_index);
int get_precision(const char *format, int *i, va_list list);
int handl_print(const char *fmt, int *ind, va_list list, char buffer[], int p);
int print_int(va_list types, char buffer[], int precision);
int print_char(va_list types, char buffer[], int precision);
int handle_char(char c, char buffer[], int precision);
int print_string(va_list types, char buffer[], int precision);
int print_percent(va_list types, char *buffer, int precision);
int write_number(int is_negative, int ind, char buffer[], int precision);

#endif
