#include "shell.h"


/**
 * strto -the func
 * @st:the st
 * @de:de
 * Return:char
 *
 */
char **strto(char *st, char *de)
{
int i, u, o, n, n_w = 0;
char **s;
if (st == NULL || st[0] == 0)
{
return (NULL); }
if (!de)
{de = " "; }
for (i = 0; st[i] != '\0'; i++)
{
if (!is_deli(st[i], de) && (is_deli(st[i + 1], de) || !st[i + 1]))
{
n_w++; }
}
if (n_w == 0)
{return (NULL); }
s = malloc((1 + n_w) *sizeof(char *));
if (!s)
{return (NULL); }
for (i = 0, u = 0; u < n_w; u++)
{
while (is_deli(st[i], de))
{
i++; }
o = 0;
while (!is_deli(st[i + o], de) && st[i + o])
{
o++; }
s[u] = malloc((o + 1) * sizeof(char));
if (!s[u])
{
for (o = 0; o < u; o++)
{
free(s[o]); }
free(s);
return (NULL); }
for (n = 0; n < o; n++)
{
s[u][n] = st[i++]; }
s[u][n] = 0; }
s[u] = NULL;
return (s); }

/**
 * strtow -the func
 * @st:the st
 * @de:de
 * Return:char
 *
 */
char **strtow(char *st, char de)
{
int i, u, o, n, n_w = 0;
char **s;
if (st == NULL || st[0] == 0)
{
return (NULL); }
for (i = 0; st[i] != '\0'; i++)
{
if ((st[i] != de && st[i + 1] == de) ||
(st[i] != de && !st[i + 1]) || st[i + 1] == de)
{
n_w++; }
}
if (n_w == 0)
{return (NULL); }
s = malloc((1 + n_w) *sizeof(char *));
if (!s)
{
return (NULL); }
for (i = 0, u = 0; u < n_w; u++)
{
while (st[i] == de && st[i] != de)
{
i++; }
o = 0;
while (st[i + o] != de && st[i + o] && st[i + o] != de)
{
o++; }
s[u] = malloc((o + 1) * sizeof(char));
if (!s[u])
{
for (o = 0; o < u; o++)
{
free(s[o]); }
free(s);
return (NULL); }
for (n = 0; n < o; n++)
{
s[u][n] = st[i++]; }
s[u][n] = 0; }
s[u] = NULL;
return (s); }
