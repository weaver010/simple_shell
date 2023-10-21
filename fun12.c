#include "shell.h"
/**
 * main -the func
 * @ac:the ac
 * @av:the av
 * Return:int
 *
 */

int main(int ac, char **av)
{
t_e ele[] = { e_i };
int f = 2;
asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (f)
		: "r" (f));
if (ac == 2)
{
f = open(av[1], O_RDONLY);
if (f == -1)
{
if (errno == EACCES)
{
exit(126);
}
if (errno == ENOENT)
{
e_put(av[0]);
e_put(": 0: CAN'T  OPEN");
e_put(av[1]);
e_putchar('\n');
e_putchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
ele->f_d = f;
}
b_env_list(ele);
shell_lo(ele, av);
return (EXIT_SUCCESS);
}


