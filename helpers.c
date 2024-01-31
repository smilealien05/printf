#include "main.h"

/**
 * _reverse - reverses a string
 * @s: string to reverse
 * Return: length of string
*/

int _reverse(char s[])
{
int len;
int start;
int end;
char temp;


len = 0;
start = 0;
end = 0;

while (s[len] != '\0')
{
len++;
}

start = 0;
end = len - 1;

while (start < end)
{
temp = s[start];
s[start] = s[end];
s[end] = temp;
start++;
end--;
}
return (len);
}

/**
 * _itoa - converts an integer to a string
 * @n: integer to convert
 * @s: string to convert to
 * Return: length of string
*/
int _itoa(int n, char s[])
{
int i;
int sign;
int len;

i = 0;
sign = n;

if (sign < 0)
n = -n;
do {
s[i++] = n % 10 + '0';
} while ((n /= 10) > 0);
if (sign < 0)
{
s[i++] = '-';
}
s[i] = '\0';

len = _reverse(s);

return (len);
}


/**
 * itoa_unsigned_int - converts an integer to a string
 * @n: integer to convert
 * @s: string to convert to
 * Return: length of string
*/
void itoa_unsigned_int(unsigned int n, char s[])
{
int i;

i = 0;

do {
s[i++] = n % 10 + '0';
} while ((n /= 10) > 0);

s[i] = '\0';
_reverse(s);
}

/**
 * itoa_hex - converts an integer to a string
 * @n: integer to convert
 * @s: string to convert to
 * @uppercase: whether to use uppercase or lowercase letters
 * Return: length of string
*/
void itoa_hex(unsigned int n, char s[], int uppercase)
{
int i;
unsigned int digit;

i = 0;
do {
digit = n % 16;
s[i++] = digit < 10 ? digit + '0' : digit - 10 + (uppercase ? 'A' : 'a');
} while ((n /= 16) > 0);
s[i] = '\0';
_reverse(s);
}

/**
 * itoa_octal - converts an integer to a string
 * @n: integer to convert
 * @s: string to convert to
 * Return: length of string
*/
void itoa_octal(unsigned int n, char s[])
{
int i;

i = 0;

do {
s[i++] = n % 8 + '0';
} while ((n /= 8) > 0);

s[i] = '\0';
_reverse(s);
}
