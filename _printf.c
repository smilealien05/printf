#include "main.h"
/**
 * initialize_handlers - initializes an array of
 *  print handler structs
 * Return: array of print handler structs
*/
Handlers initialize_handlers(void)
{
static print_handler_t handlers[] = {
{'c', print_char}, {'s', print_str}, {'d', print_int},
{'i', print_int}, {'%', print_percent}, {'b', print_binary},
{'u', print_unsigned}, {'x', print_hex_lower}, {'S', print_str_S},
{'X', print_hex_upper}, {'o', print_octal}, {'p', print_pointer},
{'r', print_reverse}, {'R', print_rot13}, {'\0', NULL}
};
Handlers result = {handlers, sizeof(handlers) / sizeof(print_handler_t)};
return (result);
}
/**
 * _printf - prints a string
 * @format: string to print
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
Handlers handlers = initialize_handlers();

char buffer[1024];
int buffer_index;
char flags[4] = {0};
char length_modifier;
int field_width, precision;
int (*handler)(va_list, char *, char *, char, int, int);

va_list args;
va_start(args, format);

buffer_index = 0;
length_modifier = '\0';

while (*format)
{
if (*format == '%')
{
format++;
parse_format(&format, flags, &length_modifier, &field_width, &precision);
handler = get_print_func(*format, handlers.handlers,
		handlers.count, length_modifier);
if (handler != NULL)
{
buffer_index += handler(args, buffer + buffer_index, flags,
		length_modifier, field_width, precision);
}
}
else
{
buffer[buffer_index++] = *format;
}
format++;
}

write(1, buffer, buffer_index);

va_end(args);
return (buffer_index);
}
