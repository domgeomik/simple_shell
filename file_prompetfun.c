#include "file_myHeader.h"
/**
 * fun_prompt - Display Shell Prompt
 */
void fun_prompt(void)
{
OUTPUTPRINTER("my_Simple_Shell$ ");
}
/**
 * fun_print_error - Display Error Based on
 * Command and How Many Time Shell Looped
 * @input:User Input
 * @counter:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */
void fun_print_error(char *input, int counter, char **argv)
{
char *er;
OUTPUTPRINTER(argv[0]);
OUTPUTPRINTER(": ");
er = _itoa(counter);
OUTPUTPRINTER(er);
free(er);
OUTPUTPRINTER(": ");
OUTPUTPRINTER(input);
OUTPUTPRINTER(": not found\n");
}
