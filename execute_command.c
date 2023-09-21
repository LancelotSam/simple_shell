#include "shell.h"
/**
 * execute_Command - function
 * @commandArgs: args
 *
 * Return: void
 */
void execute_Command(char **commandArgs)
{
	execvp(commandArgs[0], commandArgs);
	perror("Execution of command failed");
	exit(EXIT_FAILURE);
}
