#include "file_myHeader.h"
/**
 * fun_prerror - Print Custome Error
 * @argv:Program Name
 * @c:Error Count
 * @cmd:Command
 * Return: Void
 */
void fun_prerror(char **argv, int c, char **cmd)
{
char *er = _itoa(c);
OUTPUTPRINTER(argv[0]);
OUTPUTPRINTER(": ");
OUTPUTPRINTER(er);
OUTPUTPRINTER(": ");
OUTPUTPRINTER(cmd[0]);
OUTPUTPRINTER(": Illegal number: ");
OUTPUTPRINTER(cmd[1]);
OUTPUTPRINTER("\n");
free(er);
}
