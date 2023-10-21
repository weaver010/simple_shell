#include "shell.h"

/**
 * is_cha - the func
 * @inf:the inf
 * @bu:the bu
 * @o:the o
 * Return:int
 */

int is_cha(t_e *inf, char *bu, size_t *o)
{
size_t u = *o;
if (bu[u] == '|' && bu[u + 1] == '|')
{
bu[u] = 0;
u++;
inf->cmd_buf_t = CMD_OR;
}
else if (bu[u] == '&' && bu[u + 1] == '&')
{
bu[u] = 0;
u++;
inf->cmd_buf_t = CMD_AND;
}
else if (bu[u] == ';')
{
bu[u] = 0;
inf->cmd_buf_t = CMD_CHAIN;
}
else
{
return (0);
}
*o = u;
return (1);
}

/**
 * check_cha - the func
 * @inf:the inf
 * @bu:the bu
 * @o:the o
 * @i:the i
 * @l:the l
 * Return:void
 */
void check_cha(t_e *inf, char *bu, size_t *o, size_t i, size_t l)
{
size_t u = *o;
if (inf->cmd_buf_t == CMD_AND)
{
if (inf->status)
{
bu[i] = 0;
u = l;
}
}
if (inf->cmd_buf_t == CMD_OR)
{
if (!inf->status)
{
bu[i] = 0;
u = l;
}
}
*o = u;
}



/**
 * replace_ars -the func
 * @inf:the inf
 * Return:int
 *
 */
int replace_ars(t_e *inf)
{
int i = 0;
list_t *node;
for (i = 0; inf->argv[i]; i++)
{
if (inf->argv[i][0] != '$' || !inf->argv[i][1])
{
continue;
}
if (!istrcmp(inf->argv[i], "$?"))
{
replace_str(&(inf->argv[i]),
_strdup(c_n(inf->status, 10, 0)));
continue;
}
if (!istrcmp(inf->argv[i], "$$"))
{
replace_str(&(inf->argv[i]),
_strdup(c_n(getpid(), 10, 0)));
continue;
}
node = node_starts_with(inf->env, &inf->argv[i][1], '=');
if (node)
{
replace_str(&(inf->argv[i]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_str(&inf->argv[i], _strdup(""));
}
return (0);
}

/**
 * replace_str -the func
 * @o:the o
 * @n:n
 * Return:int
 *
 */
int replace_str(char **o, char *n)
{
free(*o);
*o = n;
return (1);
}


