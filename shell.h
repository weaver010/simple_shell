#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>



#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CMD_NORM        0
#define CMD_OR          1
#define CMD_AND         2
#define CMD_CHAIN       3


#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2


#define USE_GETlINE 0
#define USE_STROK 0


extern char **environ;


/**
 * struct lists - lists
 * @num: the num
 * @str: a str
 * @next:next
 */
typedef struct lists
{
int num;
char *str;
struct lists *next;
} list_t;

/**
 *struct elem - struct
 *@arg: arg
 *@argv: argv
 *@path:path
 *@argc: argc
 *@line_con: line_con
 *@error_num: error_num
 *@linecon_f:linecon_f
 *@prog: prog
 *@env: env
 *@environ: environ
 *@env_change:env_change
 *@status:status
 *@cmd_buf: cmd_buf
 *@cmd_buf_t:cmd_buf_t
 *@f_d: f_d
 */
typedef struct elem
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_con;
int error_num;
int linecon_f;
char *prog;
list_t *env;
char **environ;
int env_change;
int status;
char **cmd_buf;
int cmd_buf_t;
int f_d;
} t_e;
#define e_i {NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, 0, 0, NULL, 0, 0}

/**
 *struct built - bulit
 *@t: the t
 *@func: the func
 */
typedef struct built
{
	char *t;
	int (*func)(t_e *);
} b_arr;



int shell_lo(t_e *, char **);
int find_b_cmd(t_e *);
void find_comd(t_e *);
void fork_shell(t_e *);
int istrlen(char *);
int istrcmp(char *, char *);
char *starto(const char *, const char *);
char *istrcat(char *, char *);


int is_command(t_e *, char *);
char *dupl_ch(char *, int, int);
char *find_path(t_e *, char *, char *);

void e_put(char *);
int e_putchar(char);
int put_f(char c, int fd);
int puts_f(char *str, int fd);




char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);


char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);


char **strto(char *, char *);
char **strto2(char *, char);


char *imemset(char *, char, unsigned int);
void s_free(char **);
void *_realloc(void *, unsigned int, unsigned int);


int b_free(void **);


int interact(t_e *);
int is_deli(char, char *);
int _isalp(int);
int _atoi(char *);


int _e_a(char *);
void h_error(t_e *, char *);
int p_d(int, int);
char *c_n(long int, int, int);
void r_comment(char *);


int myexit(t_e *);
int mycd(t_e *);
int myhelp(t_e *);



ssize_t get_in(t_e *);
int mygetline(t_e *, char **, size_t *);
void sig_hand(int);


void clear_e(t_e *);
void set_e(t_e *, char **);
void free_e(t_e *, int);

char *mygetenv(t_e *, const char *);
int myenv(t_e *);
int mysetenv(t_e *);
int myunsetenv(t_e *);
int b_env_list(t_e *);


char **get_environ(t_e *);
int vunsetenv(t_e *, char *);
int vsetenv(t_e *, char *, char *);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_s(const list_t *);
int delete_node_at_posi(list_t **, unsigned int);
void free_list(list_t **);


size_t list_leng(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_posi(list_t *, list_t *);


int is_cha(t_e *, char *, size_t *);
void check_cha(t_e *, char *, size_t *, size_t, size_t);
int replace_ars(t_e *);
int replace_str(char **, char *);

#endif


