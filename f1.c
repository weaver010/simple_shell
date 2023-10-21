#include "shell.h"
/**
 * interact - func
 * @inf:the enf
 * Return:int
 *
 */

int interact(t_e *inf)
{
return (isatty(STDIN_FILENO) && inf->f_d <= 2);
}
/**
 * is_deli - the func
 * @c:the c
 * @de:the de
 *  Return:int
 */

int is_deli(char c, char *de)
{
while (*de)
{
if (*de++ == c)
{
return (1);
}
}
return (0);
}

/**
 * _isalph - the func
 * @ch:the ch
 *  Return:int
 */


int _isalph(int ch)
{
if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
{
return (1);
}
else
{
return (0);
}
}

/**
 * _atoi - the func
 * @s:the s
 *  Return:int
 */

int _atoi(char *s)
{
int i, sig = 1, f = 0, o;
unsigned int result = 0;

for (i = 0;  s[i] != '\0' && f != 2; i++)
{
if (s[i] == '-')
{
sig *= -1;
}
if (s[i] >= '0' && s[i] <= '9')
{
f = 1;
result *= 10;
result += (s[i] - '0');
}
else if (f == 1)
{
f = 2;
}
}
if (sig == -1)
{
o = -result;
}
else
{
o = result;
}
return (o);
}


