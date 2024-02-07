#include "main.h"


/**
 * print_rot13 - prints a string in rot13
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
int print_rot13(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision)
{
char *str;
int count;
char c;
int plus_flag, space_flag, zero_flag, minus_flag, hash_flag;

(void)length_modifier;
parse_flags_and_set(flags, &plus_flag, &space_flag,
		&zero_flag, &minus_flag, &hash_flag);

str = va_arg(args, char *);
count = 0;
while (str[count] != '\0' && (precision < 0 || count < precision))
{
c = str[count];
if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
{
buffer[count] = c + 13;
}
else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
{
buffer[count] = c - 13;
}
else
{
buffer[count] = c;
}
count++;
}

handle_field_width(&count, buffer, field_width, minus_flag, zero_flag);

return (count);
}
