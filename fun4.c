#include "shell.h"
/**
 * _e_a - the func
 * @c:the c
 * Return:int
 *
 */

int _e_a(char *c)
{
int i = 0;
unsigned long int res = 0;
if (*c == '+')
{
c++;
}
for (i = 0;  c[i] != '\0'; i++)
{
if (c[i] >= '0' && c[i] <= '9')
{
res *= 10;
res += (c[i] - '0');
if (res > INT_MAX)
{
return (-1);
}
}
else
{
return (-1);
}
}
return (res);
}

/**
 * h_error - the func
 * @ele:the ele
 * @st:the st
 * Return:void
 *
 */
void h_error(t_e *ele, char *st)
{
e_put(ele->prog);
e_put(": ");
p_d(ele->line_con, STDERR_FILENO);
e_put(": ");
e_put(ele->argv[0]);
e_put(": ");
e_put(st);
}
/**
 * p_d - the func
 * @in:the in
 * @f:the f
 * Return:int
 *
 */

int p_d(int in, int f)
{
int (*__putchar)(char) = _putchar;
int i, c = 0;
unsigned int abslu, cr;

if (f == STDERR_FILENO)
{
__putchar = e_putchar;
}
if (in < 0)
{
abslu = -in;
__putchar('-');
c++;
}
else
{
abslu = in;
}
cr = abslu;
for (i = 1000000000; i > 1; i /= 10)
{
if (abslu / i)
{
__putchar('0' + cr / i);
c++;
}
cr %= i;
}
__putchar('0' + cr);
c++;
return (c);
}

/**
 * c_n - the func
 * @n:the n
 * @bs:the bs
 * @f:the f
 * Return:char
 *
 */
char *c_n(long int n, int bs, int f)
{
static char *arr;
static char buf[50];
char sig = 0;
char *o;
unsigned long no = n;
if (!(f & CONVERT_UNSIGNED) && n < 0)
{
no = -n;
sig = '-';
}
arr = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
o = &buf[49];
*o = '\0';
do {
*(--o) = arr[no % bs];
no /= bs;
} while (no != 0);
if (sig)
{
*(--o) = sig;
}
return (o);
}
/**
 * r_comment - the func
 * @bu:the bu
 * Return:void
 *
 */

void r_comment(char *bu)
{
int i;
for (i = 0; bu[i] != '\0'; i++)
{
if (bu[i] == '#' && (!i || bu[i - 1] == ' '))
{
bu[i] = '\0';
break;
}
}
}

