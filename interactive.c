#include "shell.h"
/**
 * interactive - function for interactive mode
 * @name: program name
 *
 * Return: void
 */
void interactive(char *name)
{
	char *line;
	char **args;
	int execute_status;

	while (1)
	{
		write(0, "$ ", 2);
		line = read_line();
		args = split_line(line);
		execute_status = executeCommand(args, name);
		free(line);
		free(args);
		if (execute_status >= 0)
		{
			exit(execute_status);
		} else
		{
			continue;
		}
	}
}
