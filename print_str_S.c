#include "main.h"

/**
 * print_str_S - prints a string
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
int print_str_S(va_list args, char *buffer,
		char *flags, char length_modifier,
		int field_width, int precision)
{
char *str;
int count;
int plus_flag, space_flag, zero_flag, minus_flag, hash_flag;

(void)length_modifier;
parse_flags_and_set(flags, &plus_flag,
		&space_flag, &zero_flag, &minus_flag, &hash_flag);

str = va_arg(args, char *);
count = 0;
if (str == NULL)
{
str = "(null)";
}

while (*str && (precision < 0 || count < precision))
{
if (*str < 32 || *str >= 127)
{
buffer[count++] = '\\';
buffer[count++] = 'x';
buffer[count++] = "0123456789ABCDEF"[(*str >> 4) & 0xF];
buffer[count++] = "0123456789ABCDEF"[*str & 0xF];
}
else
{
buffer[count++] = *str;
}
str++;
}

handle_field_width(&count, buffer, field_width, minus_flag, zero_flag);

return (count);
}
