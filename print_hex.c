#include "main.h"

/**
 * print_hex - prints a hex number
 * @args: list of arguments
 * @buffer: buffer to write to
 * @flags: flags for the format
 * @uppercase: 1 if uppercase, 0 if lowercase
 * @length_modifier: length modifier for the format
 * @field_width: minimum number of characters to output
 * @precision: minimum number of digits to output
 * Return: number of characters printed
 */

int print_hex(va_list args, char *buffer,
		char *flags, int uppercase,
		char length_modifier, int field_width, int precision)
{
unsigned long num;
char num_buffer[33];
char *str;
int count;
int j;
int num_length;
int plus_flag;
int space_flag;
int zero_flag;
int minus_flag;
int hash_flag;

parse_flags_and_set(flags, &plus_flag, &space_flag,
		&zero_flag, &minus_flag, &hash_flag);

num = extract_number(args, length_modifier);
itoa_hex(num, num_buffer, uppercase);
str = num_buffer;
count = 0;
num_length = _str_len(str);

handle_precision(&num_length, num_buffer, precision);

if (hash_flag && num != 0)
{
buffer[count++] = '0';
buffer[count++] = uppercase ? 'X' : 'x';
}

for (j = 0; j < num_length; j++)
{
buffer[count + j] = num_buffer[j];
}

count += num_length;

handle_field_width(&count, buffer, field_width, minus_flag, zero_flag);

return (count);
}

/**
 * print_hex_lower - prints a hex number in lowercase
 * @args: list of arguments
 * @buffer: buffer to write to
 * @flags: flags for the format
 * @length_modifier: length modifier for the format
 * @field_width: minimum number of characters to output
 * @precision: minimum number of digits to output
 * Return: number of characters printed
 */
int print_hex_lower(va_list args,
		char *buffer, char *flags,
		char length_modifier, int field_width, int precision)
{
int count;

(void)length_modifier;
count = print_hex(args, buffer, flags, 0,
		length_modifier, field_width, precision);
return (count);
}

/**
 * print_hex_upper - prints a hex number in uppercase
 * @args: list of arguments
 * @buffer: buffer to write to
 * @flags: flags for the format
 * @length_modifier: length modifier for the format
 * @field_width: minimum number of characters to output
 * @precision: minimum number of digits to output
 * Return: number of characters printed
 */
int print_hex_upper(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision)
{
int count;

(void)length_modifier;

count = print_hex(args, buffer, flags, 1,
		length_modifier, field_width, precision);
return (count);

}
