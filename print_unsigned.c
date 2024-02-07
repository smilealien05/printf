#include "main.h"

/**
 * print_unsigned - prints an unsigned int
 * @args: the va_list that contains the unsigned int to print
 * @buffer: the buffer to write the unsigned int to
 * @flags: the flags to use for printing the unsigned int
 * @length_modifier: the length modifier for the unsigned int
 * @field_width: the field width for the unsigned int
 * @precision: the precision for the unsigned int
 * Return: the number of bytes written to buffer
*/
int print_unsigned(va_list args, char *buffer,
		char *flags, char length_modifier,
		int field_width, int precision)
{
unsigned long num;
char num_buffer[33];
char *str;
int count;
int num_length;
int plus_flag, space_flag, zero_flag, minus_flag, hash_flag;

parse_flags_and_set(flags, &plus_flag, &space_flag,
		&zero_flag, &minus_flag, &hash_flag);

count = 0;
if (length_modifier == 'l')
{
num = va_arg(args, unsigned long);
}
else if (length_modifier == 'h')
{
num = (unsigned short)va_arg(args, int);
}
else
{
num = va_arg(args, unsigned int);
}
itoa_unsigned_int(num, num_buffer);
str = num_buffer;

num_length = _str_len(str);
handle_precision(&num_length, num_buffer, precision);

while (*str != '\0')
{
buffer[count++] = *str++;
}

handle_field_width(&count, buffer, field_width, minus_flag, zero_flag);

return (count);
}
