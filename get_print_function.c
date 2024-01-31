#include "main.h"
typedef int (*handler_func_t)(va_list, char *, char *, char, int, int);
/**
 * get_print_func - gets the print function for a specifier
 * @s: specifier
 * @handlers: array of handler structs
 * @handlers_count: number of handlers
 * @length_modifier: length modifier
 * Return: pointer to print function
 */
handler_func_t get_print_func(char s,
		print_handler_t handlers[],
		int handlers_count,
		char length_modifier)
{
int i;

(void)length_modifier;

for (i = 0; i < handlers_count; i++)
{
if (handlers[i].spec == s)
{
return (handlers[i].handler);
}
}
return (NULL);
}
