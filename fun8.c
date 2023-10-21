#include "shell.h"
/**
 * clear_e -the func
 * @ele:the ele
 * Return:void
 *
 */

void clear_e(t_e *ele)
{
ele->arg = NULL;
ele->argv = NULL;
ele->path = NULL;
ele->argc = 0;
}
/**
 * set_e -the func
 * @ele:the ele
 * @av:the av
 * Return:void
 *
 */

void set_e(t_e *ele, char **av)
{
int i = 0;
ele->prog = av[0];
if (ele->arg)
{
ele->argv = strto(ele->arg, " \t");
if (!ele->argv)
{

ele->argv = malloc(sizeof(char *) * 2);
if (ele->argv)
{
ele->argv[0] = _strdup(ele->arg);
ele->argv[1] = NULL;
}
}
for (i = 0; ele->argv && ele->argv[i]; i++)
;
ele->argc = i;
replace_ars(ele);
}
}

/**
 * free_e -the func
 * @ele:the ele
 * @e:the e
 * Return:void
 *
 */
void free_e(t_e *ele, int e)
{
s_free(ele->argv);
ele->argv = NULL;
ele->path = NULL;
if (e)
{
if (!ele->cmd_buf)
{
free(ele->arg);
}
if (ele->env)
{
free_list(&(ele->env));
}
s_free(ele->environ);
ele->environ = NULL;
b_free((void **)ele->cmd_buf);
if (ele->f_d > 2)
{
close(ele->f_d);
}
_putchar(BUF_FLUSH);
}
}

