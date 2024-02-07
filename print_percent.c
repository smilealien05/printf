#include "main.h"

/**
 * print_percent - prints a percent symbol
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
int print_percent(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision)
{
(void)flags;
(void)length_modifier;
(void)args;
(void)precision;
(void)field_width;

buffer[0] = '%';
return (1);
}
