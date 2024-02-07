#include "main.h"


/**
 * print_octal - prints an octal
 * @args: list of arguments
 * @buffer: buffer to write to
 * @flags: flags for the format
 * @length_modifier: length modifier for the format
 * @field_width: minimum number of characters to output
 * @precision: maximum number of characters to be printed
 * from the string
 * Return: number of characters printed
*/
int print_octal(va_list args, char *buffer,
		char *flags, char length_modifier,
		int field_width, int precision)
{
unsigned long num;
char num_buffer[33];
char *str;
int count;
int plus_flag;
int space_flag;
int zero_flag;
int minus_flag;
int hash_flag;

parse_flags_and_set(flags, &plus_flag,
		&space_flag, &zero_flag,
		&minus_flag, &hash_flag);

num = extract_number(args, length_modifier);
itoa_octal(num, num_buffer);
str = num_buffer;
count = 0;

if (hash_flag && num != 0)
{
buffer[count++] = '0';
}

while (*str != '\0' || count < precision)
{
buffer[count] = *str;
str++;
count++;
}

handle_field_width(&count, buffer, field_width, minus_flag, zero_flag);

return (count);
}
