#include "shell.h"
/**
 * interactive-this is the main function
 * It calls other functions in my custom shell
 * Return:void
 */
void interactive(void)
{
	char *read_line_result;
	char **args;
	int result, exit_status;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
		read_line_result = read_line();
		if (read_line_result == NULL)
			break;
		args = split_line(read_line_result);
		if (args != NULL && args[0] != NULL)
		{
			if (_strcmp(args[0], "env") == 0)
			{
				env(args);
			} else if (_strcmp(args[0], "exit") == 0)
			{
				exit_status = my_exit(args);
				free(args);
				free(read_line_result);
				exit(exit_status);
			} else if (_strcmp(args[0], "cd") == 0)
			{
				cd(args);
			} else
			{
				result = executeCommand(args);
				if (result != 0)
				{
					perror("Failed to execute command");
				}
			}
		}
		if (read_line_result[0] == '\0')
		{
			write(STDOUT_FILENO, "$ ", 2);
			fflush(stdout);
		}
		free(args);
		free(read_line_result);
	}
}
