#include "shell.h"
/**
 * _strcpy -the func
 * @des:the des
 * @sr:sr
 * Return:char
 *
 */
char *_strcpy(char *des, char *sr)
{
int i = 0;
if (des == sr || sr == 0)
{
return (des);
}
while (sr[i])
{
des[i] = sr[i];
i++;
}
des[i] = 0;
return (des);
}
/**
 * _strdup -the func
 * @st:the char
 * Return:void
 *
 */

char *_strdup(const char *st)
{
int l = 0;
char *r;
if (st == NULL)
{
return (NULL);
}
while (*st++)
{
l++;
}
r = malloc(sizeof(char) * (l + 1));
if (!r)
{
return (NULL);
}
for (l++; l--;)
{
r[l] = *--st;
}
return (r);
}
/**
 * _puts -the func
 * @st:the st
 * Return:void
 *
 */

void _puts(char *st)
{
int i = 0;

if (!st)
{
return;
}
while (st[i] != '\0')
{
_putchar(st[i]);
i++;
}
}

/**
 * _putchar -the func
 * @ch:the ch
 * Return:int
 *
 */
int _putchar(char ch)
{
static int i;
static char bu[WRITE_BUF_SIZE];
if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, bu, i);
i = 0;
}
if (ch != BUF_FLUSH)
{
bu[i++] = ch;
}
return (1);
}
