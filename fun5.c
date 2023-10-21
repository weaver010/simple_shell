#include "shell.h"
/**
 * e_put - the func
 * @st:the st
 * Return:void
 *
 *
 */

void e_put(char *st)
{
int i = 0;
if (!st)
{
return;
}
while (st[i] != '\0')
{
e_putchar(st[i]);
i++;
}
}
/**
 * e_putchar - the func
 * @ch:the ch
 * Return:int
 *
 *
 */


int e_putchar(char ch)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (ch != BUF_FLUSH)
{
buf[i++] = ch;
}
return (1);
}
/**
 * put_f - the func
 * @ch:the ch
 * @f:the f
 * Return:int
 *
 *
 */

int put_f(char ch, int f)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(f, buf, i);
i = 0;
}
if (ch != BUF_FLUSH)
{
buf[i++] = ch;
}
return (1);
}
/**
 * puts_f - the func
 * @st:the st
 * @f:the f
 * Return:int
 *
 *
 */

int puts_f(char *st, int f)
{
int i = 0;

if (!st)
{
return (0);
}
while (*st)
{
i += put_f(*st++, f);
}
return (i);
}
