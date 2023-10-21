#include "shell.h"

/**
 * add_node -the func
 * @he:the he
 * @s:the s
 * @n:the n
 * Return:list_t
 *
 */
list_t *add_node(list_t **he, const char *s, int n)
{
list_t *new;

if (!he)
{
return (NULL);
}
new = malloc(sizeof(list_t));
if (!new)
{
return (NULL);
}
imemset((void *)new, 0, sizeof(list_t));
new->num = n;
if (s)
{
new->str = _strdup(s);
if (!new->str)
{
free(new);
return (NULL);
}
}
new->next = *he;
*he = new;
return (new);
}
/**
 * add_node_end -the func
 * @he:the he
 * @s:the s
 * @n:the n
 * Return:list_t
 *
 */

list_t *add_node_end(list_t **he, const char *s, int n)
{
list_t *new, *node;
if (!he)
{
return (NULL);
}
node = *he;
new = malloc(sizeof(list_t));
if (!new)
{
return (NULL);
}
imemset((void *)new, 0, sizeof(list_t));
new->num = n;
if (s)
{
new->str = _strdup(s);
if (!new->str)
{
free(new);
return (NULL);
}
}
if (node)
{
while (node->next)
{
node = node->next;
}
node->next = new;
}
else
{
*he = new;
}
return (new);
}

/**
 * print_list_s -the func
 * @he:the he
 * Return:int
 *
 */
size_t print_list_s(const list_t *he)
{
size_t i = 0;

while (he)
{
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
 * delete_node_at_posi -the func
 * @he:the he
 * @posi:the posi
 * Return:int
 *
 */

int delete_node_at_posi(list_t **he, unsigned int posi)
{
list_t *node, *pre;
unsigned int i = 0;

if (!he || !*he)
{
return (0);
}
if (!posi)
{
node = *he;
*he = (*he)->next;
free(node->str);
free(node);
return (1);
}
node = *he;
while (node)
{
if (i == posi)
{
pre->next = node->next;
free(node->str);
free(node);
return (1);
}
i++;
pre = node;
node = node->next;
}
return (0);
}

/**
 * free_list -the func
 * @he_po:the he_po
 * Return:int
 *
 */
void free_list(list_t **he_po)
{
list_t *node, *next_n, *he;
if (!he_po || !*he_po)
{
return;
}
he = *he_po;
node = he;
while (node)
{
next_n = node->next;
free(node->str);
free(node);
node = next_n;
}
*he_po = NULL;
}

