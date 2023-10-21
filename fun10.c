#include "shell.h"
/**
 * list_leng -the func
 * @head:the head
 * Return:int
 *
 */

size_t list_leng(const list_t *head)
{
size_t i = 0;
while (head)
{
head = head->next;
i++;
}
return (i);
}
/**
 * list_to_strings -the func
 * @h:the h
 * Return:int
 *
 */

char **list_to_strings(list_t *h)
{
list_t *node = h;
size_t i = list_leng(h), o;
char **string;
char *s;
if (!h || !i)
{
return (NULL);
}
string = malloc(sizeof(char *) * (i + 1));
if (!string)
{
return (NULL);
}
for (i = 0; node; node = node->next, i++)
{
s = malloc(istrlen(node->str) + 1);
if (!s)
{
for (o = 0; o < i; o++)
{
free(string[o]);
}
free(string);
return (NULL);
}
s = _strcpy(s, node->str);
string[i] = s;
}
string[i] = NULL;
return (string);
}


/**
 * print_list -the func
 * @he:the he
 * Return:int
 *
 */
size_t print_list(const list_t *he)
{
size_t i = 0;
while (he)
{
_puts(c_n(he->num, 10, 0));
_putchar(':');
_putchar(' ');
if (he->str)
{
_puts(he->str);
}
else
{
_puts("(NIL)");
}
_puts("\n");
he = he->next;
i++;
}
return (i);
}
/**
 * node_starts_with -the func
 * @pre:the pre
 * @node:the node
 * @c:the c
 * Return:list_t
 *
 */

list_t *node_starts_with(list_t *node, char *pre, char c)
{
char *s = NULL;

while (node)
{
s = starto(node->str, pre);
if (s && ((c == -1) || (*s == c)))
{
return (node);
}
node = node->next;
}
return (NULL);
}

/**
 * get_node_posi -the func
 * @h:the h
 * @node:the node
 * Return:int
 *
 */
ssize_t get_node_posi(list_t *h, list_t *node)
{
size_t i = 0;

while (h)
{
if (h == node)
{
return (i);
}
h = h->next;
i++;
}
return (-1);
}

