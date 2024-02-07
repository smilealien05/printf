#include "main.h"

/**
 * print_int - prints an integer
 * @args: list of arguments
 * @buffer: buffer to write to
 * @flags: flags for the format
 * @length_modifier: length modifier for the format
 * @field_width: minimum number of characters to output
 * @precision: maximum number of characters to be printed
 * from the string
 * Return: number of characters printed
*/
int print_int(va_list args, char *buffer,
		char *flags, char length_modifier,
		int field_width, int precision)
{
long num;
char num_buffer[50];
int count;
int plus_flag;
int space_flag;
int zero_flag;
int minus_flag;
int hash_flag;
int num_length;
int j;

parse_flags_and_set(flags, &plus_flag,
		&space_flag, &zero_flag,
		&minus_flag, &hash_flag);

num = extract_number(args, length_modifier);
count = 0;

handle_plus_space_flags(&count, buffer, num, plus_flag, space_flag);

num_length = _itoa(num, num_buffer);

handle_precision(&num_length, num_buffer, precision);

for (j = 0; j < num_length; j++)
{
buffer[count + j] = num_buffer[j];
}

count += num_length;

handle_field_width(&count, buffer, field_width, minus_flag, zero_flag);

return (count);
}
