#ifndef MAIN_HH
#define MAIN_HH
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define BUFF_SIZE 1024

#define UNUSED(x) (void)(x)



/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


/* SIZES */
#define LONG_SIZE 2
#define SHORT_SIZE 1
/**
 * struct to_print - struct for specifier
 * @specifier: specifier or datatype
 * @fun: pointer to print function
*/
typedef struct to_print
{
	char specifier;
	int (*fun)(va_list, char[], int, int, int, int);
} print_t;

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_index);
int get_precision(const char *format, int *i, va_list list);
int handl_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int p, int size);
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int handle_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char *buffer,
		int flags, int width, int precision, int size);
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);


int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);


/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);


/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);


/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);


/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);


/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);


/* width handler */
int write_num(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
		char buffer[], int flags, int width, int precision, int size);


/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
