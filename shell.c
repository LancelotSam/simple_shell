#include "shell.h"
/**
 * read_line-this is the main function
 *
 * it reads user input from stdin
 *
 * Return: returns lineptr
 */
char *read_line(void)
{
	char *lineptr = NULL;
	size_t buffer = 0;
	ssize_t read_inp;

	read_inp = _getline(&lineptr, &buffer, stdin);

	if (read_inp == -1 || read_inp == EOF)
	{
		perror("Exiting shell");
		free(lineptr);
		exit(EXIT_SUCCESS);
	} else if (read_inp == 1)
	{
		perror("Empty line");
		lineptr = malloc(2); /* mem for '\n' and '\0'*/
		lineptr[0] = '\n';
		lineptr[1] = '\0';
	} else if (lineptr[read_inp - 1] == '\n')
	{
		lineptr[read_inp - 1] = '\0';
	}

	return (lineptr);
}
/**
 *split_line-this is the main function
 *
 * it splits input from lineptr
 * @lineptr:the user input from stdin
 * Return:tokens
 */
char **split_line(char *lineptr)
{
	const char delimiter[] = " \n\t\r\a\"";
	int args_index = 0;
	char *token;
	char **args_tokens;

	args_tokens = malloc(sizeof(char *) * (MAX_ARGS + 1));
	if (args_tokens == NULL)
		return (NULL);

	token = _strtok(lineptr, delimiter);
	while (token != NULL && args_index < MAX_ARGS)
	{
		args_tokens[args_index++] = token;
		token = _strtok(NULL, delimiter);
	}
	args_tokens[args_index] = NULL;

	return (args_tokens);

}
/**
 * MyShell-this is the main function
 *
 * It calls other functions in my custom shell
 * Return:void
 */
void MyShell(void)
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
			}else if (_strcmp(args[0], "cd") == 0)
			{
				cd(args);
			}
			else
			{
				result = executeCommand(args);
				if (result != 0)
					perror("Failed to execute command");
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
