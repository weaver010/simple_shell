#include "shell.h"
/**
 * _strncpy - the func
 * @des:the des
 * @sr:the sr
 * @n:the n
 * Return:char
 */

char *_strncpy(char *des, char *sr, int n)
{
int i, o;
char *s = des;
i = 0;
while (sr[i] != '\0' && i < n - 1)
{
des[i] = sr[i];
i++;
}
if (i < n)
{
o = i;
while (o < n)
{
des[o] = '\0';
o++;
}
}
return (s);
}
/**
 * _strncat - the func
 * @des:the des
 * @sr:the sr
 * @n:the n
 * Return:char
 */

char *_strncat(char *des, char *sr, int n)
{
int i, o;
char *s = des;
i = 0;
o = 0;
while (des[i] != '\0')
{
i++;
}
while (sr[o] != '\0' && o < n)
{
des[i] = sr[o];
i++;
o++;
}
if (o < n)
des[i] = '\0';
return (s);
}

/**
 * _strchr - the func
 * @s:the s
 * @ch:the ch
 * Return:char
 */
char *_strchr(char *s, char ch)
{
do {
if (*s == ch)
return (s);
} while (*s++ != '\0');
return (NULL);
}

