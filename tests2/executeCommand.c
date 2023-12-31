#include "shell.h"
/**
 * executecommand-this is the main function
 *
 * it searchesd and executes commands
 * @args:the argumnets received from stdin
 * Return:0 if successful, -1 if not
 */
int executeCommand(char **args)
{
	const char *path;
	char *fullPath, *command, *token;
	int status;
	char *foundPath = NULL; /*store cmd path once found*/
	pid_t pid;

	if (args[0] == NULL)
	{
		perror("No command provided");
		return (-1);
	}

	command = args[0]; /* Assign the command */

	while (1)
	{
		/* if command provided as absolute path */
		if (_strchr(command, '/') != NULL)
		{
			if (access(command, X_OK) == 0)
			{
				/* Execute the command directly */
				pid = fork();
				if (pid < 0)
				{
					perror("Failed to fork a child process.");
					return (-1);
				} else if (pid == 0)
				{
					execve(command, args, NULL);
					perror("Failed to execute the command");
					return (-1); /* Exit child process*/
				} else
				{
					waitpid(pid, &status, 0);
					return (0);
				}
			} else
			{
				perror("Command not found.");
				return (-1);
			}
		}
		/* If command is in relative path i.e just the name */
		path = getenv("PATH");
		if (path == NULL)
		{
			perror("Failed to get the PATH environment variable.");
			return (-1);
		}

		/* Tokenize the PATH by ':' delimiter */
		token = _strtok(_strdup(path), ":");
	/*	free((void *)path);*/
		while (token != NULL)
		{
			/* Construct the full path of the command */
			fullPath = malloc(sizeof(char) * (_strlen(token) + _strlen(command) + 2));
			if (fullPath == NULL)
			{
				perror("Failed to allocate memory for the full path.");
				return (-1);
			}

			_strcpy(fullPath, token);
			_strcat(fullPath, "/");
			_strcat(fullPath, command);

			/* Check if the command exists at the current path */
			if (access(fullPath, X_OK) == 0)
			{
				/* If the command is found, store the full path */
				foundPath = _strdup(fullPath);

				pid = fork();
				if (pid < 0)
				{
					perror("Failed to fork a child process.");
					free(fullPath);
					free(token);
					return (-1);
				} else if (pid == 0)
				{
					execve(foundPath, args, NULL);
					perror("Failed to execute the command");
					free(fullPath); /* Free after command execution*/
					free(token);
					return (-1); /* Exit child process*/
				} else
				{
					waitpid(pid, &status, 0);
					free(fullPath); /* Free after command execution*/
					free(token);
					break;
				}
			}

			free(fullPath);
			token = _strtok(NULL, ":");/* Move to the next token*/
		}
	/*	free((void *)path);*/
		free(token);
		/* Command not found in any path*/
		if (foundPath != NULL)
		{
			free(foundPath);
			break;
		} else
		{
			perror("Command not found.");
			return (-1);
		}
	}

	return (-1); /*This line will never be reached*/
}
