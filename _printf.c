#include "main.h"

void my_print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFFER_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFFER_SIZE)
my_print_buffer(buffer, &buff_ind);
/* write(1, &format[i], 1);*/
printed_chars++;
}

else
{
my_print_buffer(buffer, &buff_ind);
flags = my_get_flags(format, &i);
width = my_get_width(format, &i, list);
precision = my_get_precision(format, &i, list);
size = my_get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer, flags, width,
precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
my_print_buffer(buffer, &buff_ind);

va_end(list);
return (printed_chars);
}

/**
 * my_print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void my_print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
}

