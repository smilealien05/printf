#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _reverse(char s[]);
int _itoa(int n, char s[]);
void itoa_unsigned_int(unsigned int n, char s[]);
void itoa_hex(unsigned int n, char s[], int uppercase);
void itoa_octal(unsigned int n, char s[]);
int parse_field_width(const char **format);
int parse_precision(const char **format);
int _str_len(char *str);

int print_char(va_list args, char *buffer,
		char *flags, char length_modifier,
		int field_width, int precision);
int print_str(va_list args, char *buffer,
		char *flags, char length_modifier,
		int field_width, int precision);
int print_int(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);
int print_percent(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);
int print_binary(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);
int print_unsigned(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);
int print_hex_lower(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);
int print_hex_upper(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);
int print_octal(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);
int print_str_S(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);
int print_pointer(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);
int print_reverse(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);
int print_rot13(va_list args, char *buffer, char *flags,
		char length_modifier, int field_width, int precision);

void parse_flags_(char *flags, int *plus_flag, int *space_flag,
		int *zero_flag, int *minus_flag, int *hash_flag);
void handle_plus_space_flags(int *count, char *buffer, long num,
		int plus_flag, int space_flag);
void handle_precision(int *num_length, char *num_buffer, int precision);
void handle_field_width(int *count, char *buffer, int field_width,
		int minus_flag, int zero_flag);
void parse_flags_and_set(char *flags, int *plus_flag, int *space_flag,
		int *zero_flag, int *minus_flag, int *hash_flag);
unsigned long extract_number(va_list args, char length_modifier);

void parse_flags(const char **format, char *flags, int *flag_index);
int parse_field_width(const char **format);
int parse_precision(const char **format);
void parse_format(const char **format, char *flags, char *length_modifier,
		int *field_width, int *precision);
/**
 * struct print_handler - Maps a specifier to a handler function
 * @spec: The specifier for the type of operation
 * @handler: The function to handle the operation
 * Description: Maps a specifier to a handler function
 */
typedef struct print_handler
{
	char spec;
	int (*handler)(va_list, char *, char *, char, int, int);
} print_handler_t;

/**
 * struct Handlers - Contains an array of print handlers and its size
 * @handlers: Array of print handlers
 * @count: Number of handlers in the array
 * Description: Contains an array of print handlers and its size
 */
typedef struct Handlers
{
	print_handler_t *handlers;
	int count;
} Handlers;

int (*get_print_func(char s,
			print_handler_t handlers[],
			int handlers_count,
			char length_modifier
			))(va_list, char *, char *, char, int, int);

#endif
