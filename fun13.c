#include "shell.h"
/**
 * b_free -the func
 * @o:the o
 * Return:int
 *
 */

int b_free(void **o)
{
if (*o && o)
{
free(*o);
*o = NULL;
return (1);
}
return (0);
}

/**
 * imemset -the func
 * @s:the s
 * @t:the t
 * @n:the n
 * Return:char
 *
 */

char *imemset(char *s, char t, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
{
s[i] = t;
}
return (s);
}
/**
 * s_free -the func
 * @tt:the tt
 * Return:void
 *
 */


void s_free(char **tt)
{
char **u = tt;
if (!tt)
{
return;
}
while (*tt)
{
free(*tt++);
}
free(u);
}
/**
 * _realloc -the func
 * @po:the po
 * @p_s:the p_s
 * @n_s:the n_s
 * Return:int
 *
 */


void *_realloc(void *po, unsigned int p_s, unsigned int n_s)
{
char *o;
if (!po)
{
return (malloc(n_s));
}
if (!n_s)
{
return (free(po), NULL);
}
if (n_s == p_s)
{
return (po);
}
o = malloc(n_s);
if (!o)
{
return (NULL);
}
if (p_s < n_s)
{
p_s = p_s;
}
else
{
p_s = n_s;
}
while (p_s--)
{
o[p_s] = ((char *)po)[p_s];
}
free(po);
return (o);
}


