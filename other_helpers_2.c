#include "main.h"

/**
 * _str_len - returns the length of a string
 * @str: string
 * Return: length of string
*/
int _str_len(char *str)
{
int length;

length = 0;
while (str[length] != '\0')
{
length++;
}
return (length);
}


/**
 * parse_flags_and_set - parses flags for a format
 * @flags: flags string
 * @plus_flag: pointer to plus flag
 * @space_flag: pointer to space flag
 * @zero_flag: pointer to zero flag
 * @minus_flag: pointer to minus flag
 * @hash_flag: pointer to hash flag
 * Return: void
*/
void parse_flags_and_set(char *flags, int *plus_flag,
		int *space_flag, int *zero_flag,
		int *minus_flag, int *hash_flag)
{
*plus_flag = 0;
*space_flag = 0;
*zero_flag = 0;
*minus_flag = 0;
*hash_flag = 0;
parse_flags_(flags, plus_flag, space_flag, zero_flag, minus_flag, hash_flag);
}
/**
 * extract_number - extracts a number from a va_list
 * @args: va_list to extract from
 * @length_modifier: length modifier for the format
 * Return: number
*/
unsigned long extract_number(va_list args, char length_modifier)
{
if (length_modifier == 'l')
{
return (va_arg(args, unsigned long));
}
else if (length_modifier == 'h')
{
return ((unsigned short)va_arg(args, int));
}
else
{
return (va_arg(args, unsigned int));
}
}
