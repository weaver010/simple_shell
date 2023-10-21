#include "shell.h"

/**
 * istrlen -the func
 * @st:the st
 * Return:int
 *
 */
int istrlen(char *st)
{
int i = 0;
if (!st)
{
return (0);
}
while (*st++)
{
i++;
}
return (i);
}

/**
 * istrcmp -the func
 * @st1:the st1
 * @st2:st2
 * Return:int
 *
 */
int istrcmp(char *st1, char *st2)
{
while (*st1 && *st2)
{
if (*st1 != *st2)
{
return (*st1 - *st2);
}
st1++;
st2++;
}
if (*st1 == *st2)
{
return (0);
}
else
{
if (*st1 < *st2)
{
return (-1);
}
else
{
return (1);
}
}
}

/**
 * starto -the func
 * @ha:the ha
 * @ne:ne
 * Return:char
 *
 */

char *starto(const char *ha, const char *ne)
{
while (*ne)
{
if (*ne++ != *ha++)
{
return (NULL);
}
}
return ((char *)ha);
}

/**
 * istrcat -the func
 * @des:the des
 * @sr:sr
 * Return:char
 *
 */
char *istrcat(char *des, char *sr)
{
char *r = des;

while (*des)
{
des++;
}
while (*sr)
{
*des++ = *sr++;
}
*des = *sr;
return (r);
}


