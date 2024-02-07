#include "main.h"

/**
 * print_reverse - prints a string in reverse
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
int print_reverse(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision)
{
char *str;
int length;
int count;
int i;
int plus_flag, space_flag, zero_flag, minus_flag, hash_flag;

(void)flags;
(void)length_modifier;
(void)precision;

parse_flags_and_set(flags, &plus_flag, &space_flag,
		&zero_flag, &minus_flag, &hash_flag);

str = va_arg(args, char *);
length = _str_len(str);
count = 0;
for (i = 0; i < length; i++)
{
buffer[count++] = str[length - i - 1];
}

handle_field_width(&count, buffer, field_width, minus_flag, zero_flag);

return (count);
}
