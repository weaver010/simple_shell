#include "shell.h"
/**
 * myenv - the func
 * @ele:the ele
 * Return:int
 */

int myenv(t_e *ele)
{
print_list_s(ele->env);
return (0);
}
/**
 * mygetenv - the func
 * @ele:the ele
 * @n:the n
 * Return:char
 */

char *mygetenv(t_e *ele, const char *n)
{
list_t *node = ele->env;
char *st;
while (node)
{
st = starto(node->str, n);
if (st && *st)
{
return (st);
}
node = node->next;
}
return (NULL);
}
/**
 * mysetenv - the func
 * @ele:the ele
 * Return:int
 */


int mysetenv(t_e *ele)
{
if (ele->argc != 3)
{
e_put("false num of arguements\n");
return (1);
}
if (vsetenv(ele, ele->argv[1], ele->argv[2]))
{
return (0);
}
return (1);
}
/**
 * myunsetenv - the func
 * @ele:the ele
 * Return:int
 */


int myunsetenv(t_e *ele)
{
int i;

if (ele->argc == 1)
{
e_put("Too little arguements.\n");
return (1);
}
for (i = 1; i <= ele->argc; i++)
{
vunsetenv(ele, ele->argv[i]);
}
return (0);
}
/**
 * b_env_list - the func
 * @ele:the ele
 * Return:int
 */

int b_env_list(t_e *ele)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
{
add_node_end(&node, environ[i], 0);
}
ele->env = node;
return (0);
}

