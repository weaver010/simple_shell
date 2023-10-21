#include "shell.h"
/**
 * shell_lo -the func
 * @inf:the inf
 * @av:av
 * Return:int
 *
 */

int shell_lo(t_e *inf, char **av)
{
ssize_t r = 0;
int b_r = 0;
while (r != -1 && b_r != -2)
{
clear_e(inf);
if (interact(inf))
{
_puts("$ ");
}
e_putchar(BUF_FLUSH);
r = get_in(inf);
if (r != -1)
{
set_e(inf, av);
b_r = find_b_cmd(inf);
if (b_r == -1)
{
find_comd(inf);
}
}
else if (interact(inf))
{
_putchar('\n');
}
free_e(inf, 0);
}
free_e(inf, 1);
if (!interact(inf) && inf->status)
{
exit(inf->status);
}
if (b_r == -2)
{
if (inf->error_num == -1)
{
exit(inf->status);
}
exit(inf->error_num);
}
return (b_r);
}

/**
 * find_b_cmd - the func
 * @inf:the inf
 * Return:int
 *
 */
int find_b_cmd(t_e *inf)
{
int i, b_r = -1;
b_arr buil[] = {
{"exit", myexit},
{"env", myenv},
{"help", myhelp},
{"setenv", mysetenv},
{"unsetenv", myunsetenv},
{"cd", mycd},
{NULL, NULL}
};
for (i = 0; buil[i].t; i++)
if (istrcmp(inf->argv[0], buil[i].t) == 0)
{
inf->line_con++;
b_r = buil[i].func(inf);
break;
}
return (b_r);
}
/**
 * find_comd -the func
 * @inf:the inf
 * Return:void
 *
 */

void find_comd(t_e *inf)
{
char *path = NULL;
int i, q;
inf->path = inf->argv[0];
if (inf->linecon_f == 1)
{
inf->line_con++;
inf->linecon_f = 0;
}
for (i = 0, q = 0; inf->arg[i]; i++)
{
if (!is_deli(inf->arg[i], " \t\n"))
{
q++;
}
}
if (!q)
{
return;
}
path = find_path(inf, mygetenv(inf, "PATH="), inf->argv[0]);
if (path)
{
inf->path = path;
fork_shell(inf);
}
else
{
if ((interact(inf) || mygetenv(inf, "PATH=")
|| inf->argv[0][0] == '/') && is_command(inf, inf->argv[0]))
{
fork_shell(inf);
}
else if (*(inf->arg) != '\n')
{
inf->status = 127;
h_error(inf, "not found\n");
}
}
}
/**
 * fork_shell -the func
 * @inf:the inf
 * Return:void
 *
 */

void fork_shell(t_e *inf)
{
pid_t ch_pid;

ch_pid = fork();
if (ch_pid == -1)
{
perror("Error:");
return;
}
if (ch_pid == 0)
{
if (execve(inf->path, inf->argv, get_environ(inf)) == -1)
{
free_e(inf, 1);
if (errno == EACCES)
{
exit(126);
}
exit(1);
}
}
else
{
wait(&(inf->status));
if (WIFEXITED(inf->status))
{
inf->status = WEXITSTATUS(inf->status);
if (inf->status == 126)
{
h_error(inf, "Permission denied\n");
}
}
}
}


