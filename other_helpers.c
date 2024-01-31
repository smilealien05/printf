#include "main.h"

/**
 * parse_flags_ - parses flags for a format
 * @flags: flags string
 * @plus_flag: pointer to plus flag
 * @space_flag: pointer to space flag
 * @zero_flag: pointer to zero flag
 * @minus_flag: pointer to minus flag
 * @hash_flag: pointer to hash flag
 * Return: void
*/
void parse_flags_(char *flags, int *plus_flag, int *space_flag,
		int *zero_flag, int *minus_flag, int *hash_flag)
{
int i;

for (i = 0; flags[i]; i++)
{
if (flags[i] == '+')
*plus_flag = 1;
else if (flags[i] == ' ')
*space_flag = 1;
else if (flags[i] == '0')
*zero_flag = 1;
else if (flags[i] == '-')
*minus_flag = 1;
else if (flags[i] == '#')
*hash_flag = 1;
}
}

/**
 * handle_plus_space_flags - handles plus and space flags
 * @count: pointer to count
 * @buffer: buffer to write to
 * @num: number to print
 * @plus_flag: plus flag
 * @space_flag: space flag
 * Return: void
*/
void handle_plus_space_flags(int *count, char *buffer,
		long num, int plus_flag, int space_flag)
{
if (plus_flag && num >= 0)
{
buffer[(*count)++] = '+';
}
else if (space_flag && num >= 0)
{
buffer[(*count)++] = ' ';
}
}

/**
 * handle_field_width - handles field width
 * @count: pointer to count
 * @buffer: buffer to write to
 * @field_width: field width
 * @minus_flag: minus flag
 * @zero_flag: zero flag
 * Return: void
*/
void handle_field_width(int *count, char *buffer, int field_width,
		int minus_flag, int zero_flag)
{
char fill_char;
int j;

fill_char = minus_flag ? ' ' : (zero_flag ? '0' : ' ');

while (*count < field_width)
{
if (minus_flag)
{
buffer[(*count)++] = fill_char;
}
else
{
for (j = *count; j > 0; j--)
{
buffer[j] = buffer[j - 1];
}
buffer[0] = fill_char;
(*count)++;
}
}
}

/**
 * handle_precision - handles precision
 * @num_length: pointer to num length
 * @num_buffer: number buffer
 * @precision: precision
 * Return: void
*/
void handle_precision(int *num_length, char *num_buffer, int precision)
{
int padding;
int i;

if (precision > *num_length)
{
padding = precision - *num_length;

for (i = *num_length; i >= 0; i--)
{
num_buffer[i + padding] = num_buffer[i];
}

for (i = 0; i < padding; i++)
{
num_buffer[i] = '0';
}
*num_length = precision;
}
}
