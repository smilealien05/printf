#include "main.h"

/**
 * handle_null_pointer - handles null pointer
 * @ptr: pointer
 * @buffer: buffer to write to
 * Return: number of chars written
*/
int handle_null_pointer(void *ptr, char *buffer)
{
if (ptr == NULL)
{
buffer[0] = '(';
buffer[1] = 'n';
buffer[2] = 'i';
buffer[3] = 'l';
buffer[4] = ')';
return (5);
}
return (0);
}

/**
 * print_pointer - prints a pointer
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
int print_pointer(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision)
{
void *ptr;
unsigned char *address_bytes;
int count;
int i;
char hex_digits[] = "0123456789abcdef";
int leading_zero;
int plus_flag;
int space_flag;
int zero_flag;
int minus_flag;
int hash_flag;

(void)length_modifier;

parse_flags_and_set(flags, &plus_flag, &space_flag,
		&zero_flag, &minus_flag, &hash_flag);

ptr = va_arg(args, void *);
address_bytes = (unsigned char *)&ptr;
count = 0;
leading_zero = 1;

count = handle_null_pointer(ptr, buffer);
if (count > 0)
	return (count);

buffer[0] = '0';
buffer[1] = 'x';
count = 2;
for (i = sizeof(ptr) - 1; i >= 0; i--)
{
if (leading_zero && address_bytes[i] == 0 && count < precision)
continue;
leading_zero = 0;
buffer[count++] = hex_digits[address_bytes[i] >> 4];
buffer[count++] = hex_digits[address_bytes[i] & 0xf];
}
handle_field_width(&count, buffer, field_width, minus_flag, zero_flag);
return (count);
}
