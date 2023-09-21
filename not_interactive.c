#include "shell.h"
/**
 * non_interactive - this is the main function
 * it runs non interactive mode
 * @name: program name
 *
 * Return: void
 */
void non_interactive(char *name)
{
	char *line;
	char **args;
	int execute_status;

	while (1)
	{
		line = read_line();
		args = split_line(line);
		execute_status = executeCommand(args, name);
		free(line);
		free(args);
		if (execute_status >= 0)
		{
			exit(execute_status);
		} else
			continue;
	}
}
