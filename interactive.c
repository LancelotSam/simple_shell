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
		if (line[0] == '#')
		{
			free(line);
			continue;
		}
		args = split_line(line);
		execute_status = executeCommand(args, name);
		free(args);
		free(line);
		if (execute_status >= 0)
		{
			exit(execute_status);
		} else
		{
			continue;
		}
	}
}
