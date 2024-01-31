#include "main.h"

/**
 * print_char - prints a character
 * @args: list of arguments
 * @buffer: buffer to write to
 * @flags: flags for the format
 * @length_modifier: length modifier for the format
 * (not used in this function)
 * @field_width: minimum number of characters to output
 * @precision: maximum number of characters to be printed
 * from the string
 * Return: number of characters printed
*/

int print_char(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision)
{
char c;
int count;
int plus_flag;
int space_flag;
int zero_flag;
int minus_flag;
int hash_flag;

(void)length_modifier;
(void)precision;

parse_flags_and_set(flags, &plus_flag, &space_flag,
		&zero_flag, &minus_flag, &hash_flag);

c = va_arg(args, int);
count = 0;

buffer[count++] = c;

handle_field_width(&count, buffer, field_width, minus_flag, zero_flag);

return (count);
}
