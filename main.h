#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */

struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_f - struct fmt
 *
 * @fmt: The format.
 * @fm_f: The function associated.
 */
typedef struct fmt fmt_f;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****** FUNCTIONS ******/

/* Funtions to print chars and strings */
int my_print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);

int my_print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);

int my_print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Functions to print numbers */
int my_print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);

int my_print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);

int my_print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);

int my_print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);

int my_print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);

int my_print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);

int my_print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int my_print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funcion to print memory address */
int my_print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int my_get_flags(const char *format, int *i);
int my_get_width(const char *format, int *i, va_list list);
int my_get_precision(const char *format, int *i, va_list list);
int my_get_size(const char *format, int *i);

/*Function to print string in reverse*/
int my_print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int my_print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* width handler */
int my_write_char(char c, char buffer[],
int flags, int width, int precision, int size);

int my_write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);

int my_write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);

int my_write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);

int my_write_unsgnd(int is_negative, int ind,
char buffer[], int flags, int width, int precision, int size);

/****** UTILS ******/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

