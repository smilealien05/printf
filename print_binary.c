#include "main.h"

/**
 * convert_to_binary - converts a number to binary
 * @num: number to convert
 * @num_buffer: buffer to write to
 * @i: pointer to index of buffer
 * Return: void
*/
void convert_to_binary(unsigned int num, char *num_buffer, int *i)
{
while (num)
{
num_buffer[(*i)--] = (num & 1) + '0';
num >>= 1;
}
(*i)++;
}

/**
 * print_binary - prints a binary number
 * @args: list of arguments
 * @buffer: buffer to write to
 * @flags: flags for the format
 * @length_modifier: length modifier for the format
 * (not used in this function)
 * @field_width: minimum number of characters to output
 * @precision: maximum number of characters to be printed
 * Return: number of characters printed
*/

int print_binary(va_list args, char *buffer, char *flags,
		char length_modifier,
		int field_width, int precision)
{
unsigned int num;
char num_buffer[33];
int i;
int count;
int plus_flag;
int space_flag;
int zero_flag;
int minus_flag;
int hash_flag;
int num_length;
int j;

(void)length_modifier;

parse_flags_and_set(flags, &plus_flag, &space_flag,
		&zero_flag, &minus_flag, &hash_flag);

num = va_arg(args, unsigned int);
i = 31;
count = 0;

if (num == 0)
{
buffer[0] = '0';
return (1);
}
convert_to_binary(num, num_buffer, &i);
num_length = 32 - i;
handle_precision(&num_length, num_buffer + i, precision);
for (j = 0; j < num_length; j++)
{
buffer[count + j] = num_buffer[i + j];
}
count += num_length;
handle_field_width(&count, buffer, field_width,
		minus_flag, zero_flag);

return (count);
}
