#include "shell.h"
/**
 * is_command -the func
 * @inf:the inf
 * @path:path
 * Return:int
 *
 */

int is_command(t_e *inf, char *path)
{
struct stat st;
(void)inf;
if (!path || stat(path, &st))
{
return (0);
}
if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * dupl_ch - the func
 * @pat:the pat
 * @f:the f
 * @e:the e
 * Return:char
 */
char *dupl_ch(char *pat, int f, int e)
{
static char bu[1024];
int i = 0, o = 0;
for (o = 0, i = f; i < e; i++)
{
if (pat[i] != ':')
{
bu[o++] = pat[i];
}
}
bu[o] = 0;
return (bu);
}
/**
 * find_path - the func
 * @inf:the inf
 * @pat:the pat
 * @comd:the comd
 * Return:char
 */

char *find_path(t_e *inf, char *pat, char *comd)
{
int i = 0, pros = 0;
char *path;
if (!pat)
{
return (NULL);
}
if ((istrlen(comd) > 2) && starto(comd, "./"))
{
if (is_command(inf, comd))
{
return (comd);
}
}
while (1)
{
if (!pat[i] || pat[i] == ':')
{
path = dupl_ch(pat, pros, i);
if (!*path)
{
istrcat(path, comd);
}
else
{
istrcat(path, "/");
istrcat(path, comd);
}
if (is_command(inf, path))
{
return (path);
}
if (!pat[i])
{
break;
}
pros = i;
}
i++;
}
return (NULL);
}


