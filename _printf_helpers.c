#include "main.h"

/**
 * parse_field_width - parses field width from format string
 * @format: format string
 * Return: field width
 */
int parse_field_width(const char **format)
{
int field_width;

field_width = 0;
while (**format >= '0' && **format <= '9')
{
field_width = field_width * 10 + (**format - '0');
(*format)++;
}
return (field_width);
}

/**
 * parse_precision - parses precision from format string
 * @format: format string
 * Return: precision
 */
int parse_precision(const char **format)
{
int precision;

precision = -1;

if (**format == '.')
{
(*format)++;
precision = 0;
while (**format >= '0' && **format <= '9')
{
precision = precision * 10 + (**format - '0');
(*format)++;
}
}

return (precision);
}
/**
 * parse_flags - parses flags from format string
 * @format: format string
 * @flags: array to store flags
 * @flag_index: pointer to index of flags array
 * Return: void
 */
void parse_flags(const char **format, char *flags, int *flag_index)
{
while (**format == '0' || **format == '-')
{
flags[(*flag_index)++] = *(*format)++;
}

while (**format == '+' || **format == ' ' || **format == '#')
{
flags[(*flag_index)++] = *(*format)++;
}
}
/**
 * parse_format - parses a format string
 * @format: format string
 * @flags: array to store flags
 * @length_modifier: pointer to length modifier
 * @field_width: pointer to field width
 * @precision: pointer to precision
 * Return: void
*/
void parse_format(const char **format, char *flags,
		char *length_modifier,
		int *field_width, int *precision)
{
int flag_index;

flag_index = 0;
parse_flags(format, flags, &flag_index);

if (**format == 'l' || **format == 'h')
{
*length_modifier = *(*format)++;
}

*field_width = parse_field_width(format);
*precision = parse_precision(format);
}
