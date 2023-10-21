#include "shell.h"
/**
 * myexit - the func
 * @ele:the ele
 * Return:int
 *
 *
 */

int myexit(t_e *ele)
{
int ex;
if (ele->argv[1])
{
ex = _e_a(ele->argv[1]);
if (ex == -1)
{
ele->status = 2;
h_error(ele, "Illelnumber: ");
e_put(ele->argv[1]);
e_putchar('\n');
return (1);
}
ele->error_num = _e_a(ele->argv[1]);
return (-2);
}
ele->error_num = -1;
return (-2);
}
/**
 * mycd - the func
 * @ele:the ele
 * Return:int
 *
 *
 */
int mycd(t_e *ele)
{
char *s, *di, buf[1024];
int chdi;
s = getcwd(buf, 1024);
if (!s)
{
_puts("TO do: >>getcwd failure em here<<\n"); }
if (!ele->argv[1])
{
di = mygetenv(ele, "HOME=");
if (!di)
{di = mygetenv(ele, "PWD=");
if (di)
{chdi = chdir((di)); }
else
{chdi = chdir(("/")); }
}
else
{chdi = chdir(di); }
}
else if (istrcmp(ele->argv[1], "-") == 0)
{
if (!mygetenv(ele, "OLDPWD="))
{_puts(s);
_putchar('\n');
return (1); }
_puts(mygetenv(ele, "OLDPWD=")), _putchar('\n');
di = mygetenv(ele, "OLDPWD=");
if (di)
{chdi = chdir(di); }
else
{chdi = chdir("/"); }
}
else
{chdi = chdir(ele->argv[1]); }
if (chdi == -1)
{h_error(ele, "can't cd to ");
e_put(ele->argv[1]), e_putchar('\n'); }
else
{vsetenv(ele, "OLDPWD", mygetenv(ele, "PWD="));
vsetenv(ele, "PWD", getcwd(buf, 1024)); }
return (0); }

/**
 * myhelp - the func
 * @ele:the ele
 * Return:int
 *
 *
 */
int myhelp(t_e *ele)
{
char **arg_arr;
arg_arr = ele->argv;
_puts("help call works. Function not implement \n");
if (0)
{
_puts(*arg_arr);
}
return (0);
}
