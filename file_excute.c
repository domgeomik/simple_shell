#include "file_myHeader.h"
/**
 * fun_check_cmd - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmd:Parsed Command
 * @input: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int fun_check_cmd(char **cmd, char *input, int c, char **argv)
{
int status;
pid_t pid;
if (*cmd == NULL)
{
return (-1);
}
pid = fork();
if (pid == -1)
{
perror("Error");
return (-1);
}
if (pid == 0)
{
if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
{
fun_path_cmd(cmd);
}
if (execve(*cmd, cmd, environ) == -1)
{
fun_print_error(cmd[0], c, argv);
free(input);
free(cmd);
exit(EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}
wait(&status);
return (0);
}
/**
 * fun_signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void fun_signal_to_handel(int sig)
{
if (sig == SIGINT)
{
OUTPUTPRINTER("\n$ ");
}
}
/**
 * fun_handle_builtin - Handle Builtin Command
 * @cmd: Parsed Command
 * @er:statue of last Excute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int fun_handle_builtin(char **cmd, int er)
{
my_bul_t bil[] = {
{"cd", fun_change_dir},
{"env", fun_dis_env},
{"help", fun_display_help},
{"echo", fun_echo_bul},
{"history", fun_history_dis},
{NULL, NULL}
};
int i = 0;
while ((bil + i)->command)
{
if (_strcmp(cmd[0], (bil + i)->command) == 0)
{
return ((bil + i)->fun(cmd, er));
}
i++;
}
return (-1);
}
