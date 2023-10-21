#include "shell.h"

/**
 * input_buf -the func
 * @ele:the ele
 * @buf:the buf
 * @l:the l
 * Return:int
 *
 */
ssize_t input_buf(t_e *ele, char **buf, size_t *l)
{
ssize_t r = 0;
size_t l_l = 0;
if (!*l)
{
free(*buf);
*buf = NULL;
signal(SIGINT, sig_hand);
#if USE_GETLINE
		r = getline(buf, &l_l, stdin);
#else
		r = mygetline(ele, buf, &l_l);
#endif
if (r > 0)
{
if ((*buf)[r - 1] == '\n')
{
(*buf)[r - 1] = '\0';
r--;
}
ele->linecon_f = 1;
r_comment(*buf);
{
*l = r;
ele->cmd_buf = buf;
}
}
}
return (r);
}

/**
 * get_in -the func
 * @ele:the ele
 * Return:int
 *
 */
ssize_t get_in(t_e *ele)
{
static char *buf;
static size_t i, j, l;
ssize_t r = 0;
char **buf_c = &(ele->arg), *o;
_putchar(BUF_FLUSH);
r = input_buf(ele, &buf, &l);
if (r == -1)
{
return (-1);
}
if (l)
{
j = i;
o = buf + i;
check_cha(ele, buf, &j, i, l);
while (j < l)
{
if (is_cha(ele, buf, &j))
{
break;
}
j++;
}
i = j + 1;
if (i >= l)
{
i = l = 0;
ele->cmd_buf_t = CMD_NORM;
}
*buf_c = o;
return (istrlen(o));
}
*buf_c = buf;
return (r);
}
/**
 * read_buf -the func
 * @ele:the ele
 * @buf:the buf
 * @i:the i
 * Return:int
 *
 */

ssize_t read_buf(t_e *ele, char *buf, size_t *i)
{
ssize_t r = 0;
if (*i)
{
return (0);
}
r = read(ele->f_d, buf, READ_BUF_SIZE);
if (r >= 0)
{
*i = r;
}
return (r);
}

/**
 * mygetline -the func
 * @ele:the ele
 * @o:the o
 * @length:the length
 * Return:int
 *
 */
int mygetline(t_e *ele, char **o, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t i, l;
size_t y;
ssize_t r = 0, s = 0;
char *h = NULL, *n_o = NULL, *c;
h = *o;
if (h && length)
{
s = *length;
}
if (i == l)
{
i = l = 0;
}
r = read_buf(ele, buf, &l);
if (r == -1 || (r == 0 && l == 0))
{
return (-1);
}
c = _strchr(buf + i, '\n');
y = c ? 1 + (unsigned int)(c - buf) : l;
n_o = _realloc(h, s, s ? s + y : y + 1);
if (!n_o)
{
return (h ? free(h), -1 : -1);
}
if (s)
{
_strncat(n_o, buf + i, y - i); }
else
{
_strncpy(n_o, buf + i, y - i + 1); }
s += y - i;
i = y;
h = n_o;
if (length)
{
*length = s; }
*o = h;
return (s); }

/**
 * sig_hand -the func
 * @sig_n:the sig_n
 * Return:void
 *
 */
void sig_hand(__attribute__((unused))int sig_n)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
