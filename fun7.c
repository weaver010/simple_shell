#include "shell.h"
/**
 * get_environ -the func
 * @ele:the ele
 * Return:char
 *
 */

char **get_environ(t_e *ele)
{
if (!ele->environ || ele->env_change)
{
ele->environ = list_to_strings(ele->env);
ele->env_change = 0;
}
return (ele->environ);
}
/**
 * vunsetenv -the func
 * @ele:the ele
 * @v:the v
 * Return:char
 *
 */
int vunsetenv(t_e *ele, char *v)
{
list_t *node = ele->env;
size_t i = 0;
char *s;

if (!node || !v)
{
return (0);
}

while (node)
{
s = starto(node->str, v);
if (s  && *s == '=')
{
ele->env_change = delete_node_at_posi(&(ele->env), i);
i = 0;
node = ele->env;
continue;
}
node = node->next;
i++;
}
return (ele->env_change);
}

/**
 * vsetenv -the func
 * @ele:the ele
 * @v:the v
 * @val:the val
 * Return:char
 *
 */
int vsetenv(t_e *ele, char *v, char *val)
{
char *buf = NULL;
list_t *node;
char *s;
if (!v || !val)
{
return (0);
}
buf = malloc(istrlen(v) + istrlen(val) + 2);
if (!buf)
{
return (1);
}
_strcpy(buf, v);
istrcat(buf, "=");
istrcat(buf, val);
node = ele->env;
while (node)
{
s = starto(node->str, v);
if (s && *s == '=')
{
free(node->str);
node->str = buf;
ele->env_change = 1;
return (0);
}
node = node->next;
}
add_node_end(&(ele->env), buf, 0);
free(buf);
ele->env_change = 1;
return (0);
}


