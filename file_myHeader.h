#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <errno.h>

/**###### environ var ######*/

extern char **environ;

/**##### My_MACROS ######*/

#define MY_BUFSIZE 1024
#define MY_DELIM " \t\r\n\a"
#define OUTPUTPRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))


/** ###### file_builtin.c fun ###*/
int fun_dis_env(char **cmd, int er);
int fun_display_help(char **cmd, int er);
int fun_echo_bul(char **cmd, int er);
int fun_change_dir(char **cmd, int er);
void  fun_exit_bul(char **cmd, char *input, char **argv, int c);

/** ###### file_char_fun.c fun ###*/
int my_Write(char c);
int _strlen(char *s);
void _puts(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int fun_atoi(char *s);
char *_strncpy(char *dest, char *src, int n);

/** ###### file_execute_file.c fun ###*/
void fun_read_file(char *filename, char **argv);
void fun_treat_file(char *line, int counter, FILE *fd, char **argv);
void fun_exit_bul_for_file(char **cmd, char *line, FILE *fd);

/** ###### file_execute.c fun ###*/
int fun_handle_builtin(char **cmd, int er);
int fun_check_cmd(char **tokens, char *line, int count, char **argv);
void fun_signal_to_handel(int sig);

/** ###### file_finding_path.c fun ###*/
int fun_path_cmd(char **line);
char *fun_build(char *token, char *value);
char *_getenv(char *name);

/** ###### file_get_line.c fun ###*/
char *_getline(void);
void fun_hashtag_handle(char *buff);

/** ###### file_history.c fun ###*/
int fun_history(char *input);
void fun_free_env(char **env);

/** ###### file_memory_management.c fun ###*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void fun_free_all(char **input, char *line);
void *fun_fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);

/** ###### file_more_bul.c fun ###*/
int fun_history_dis(char **cmd, int er);
int fun_print_echo(char **cmd);

/** ###### file_more_charfun.c fun ###*/
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void fun_array_rev(char *arr, int len);
int fun_intlen(int num);
char *_itoa(unsigned int n);

/** ###### file_more_fun.c ###*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strchr(char *s, char c);

/** ###### file_output.c fun ###*/
void fun_prerror(char **argv, int c, char **cmd);

/** ###### file_parsing.c fun ###*/
char **fun_parse_cmd(char *cmd);

/** ###### file_printing.c fun ###*/
void fun_print_number(unsigned int n);
void fun_print_number_in(int n);

/** ###### file_promptetfun.c fun ###*/
void fun_prompt(void);
void fun_print_error(char *line, int c, char **argv);

/** ###### file_shell.c fun ###*/
int fun_check_builtin(char **cmd);
void fun_creat_envi(char **envi);

/** ###### file_strtok.c fun ###*/
unsigned int fun_check_delim(char c, const char *str);
char *_strtok(char *str, const char *tok);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} my_bul_t;

#endif

