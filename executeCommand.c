//#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char *_strncpy(char *dest, const char *src, size_t n)
{
        size_t i = 0;

        while (src[i] != '\0' && i < n)
        {
                dest[i] = src[i];
                i++;
        }
        while (i < n)
        {
                dest[i] = '\0';
                i++;
        }

        return (dest);
}
int _strlen(const char *str)
{
        int index = 0;

        if (*str == '\0')
                return (0);
        while (str[index])
        {
                index++;
        }

        return (index);
}
char *_strcat(char *dest, const char *src)
{
        int dest_len = 0, i = 0, TOTAL_LEN = 64;

        while (dest[dest_len] != '\0')
        {
                dest_len++;
        }

        while (src[i] != '\0' && i < TOTAL_LEN - dest_len)
        {
                dest[dest_len + i] = src[i];
                i++;
        }
        dest[dest_len + i] = '\0';

        return (dest);
}
char *_strdup(const char *src)
{
        int len = 0;
        char *str;
        char *p;

        if (src == NULL)
                return (NULL);
        while (src[len])
        {
                len++;
        }
        /*allocate memory to store duplice*/
        str = malloc(len + 1);

        if (str == NULL)
        {
                perror("mem allocation failed");
                return (NULL);
        }
        /*since you cannot manipulate str, assign it to a pointer*/
        p = str;
        /*copy src to str*/
        while (*src)
        {
                *p++ = *src++;
        }
        *p = '\0';

        return (str);
}
const char *_strchr(const char *str, int c)
{
        while (*str != '\0')
        {
                if (*str == c)
                {
                        return (str);
                }
                str++;
        }
        return (NULL);
}
char *_strcpy(char *dest, const char *src)
{
        int i = 0;

        while (src[i] != '\0')
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';

        return (dest);
}
char *_strtok(const char *str, const char *delim)
{
        static const char *last_token;
        const char *current_token = NULL;
        size_t token_length;
        char *token_copy;

        if (str != NULL)
        {
                last_token = NULL;
                last_token = str;
        }
        else
                if (last_token == NULL)
                        return (NULL);
        str = last_token;
        /*skip leading delims*/
        while (*str && _strchr(delim, *str))
        {
                str++;
        }
        if (*str == '\0')
        {
                last_token = NULL;
                return (NULL);
        }
        current_token = str;
        while (*str && !_strchr(delim, *str))
        { /*check end of current tok*/
                str++;
        }
        token_length = str - current_token;

        last_token = str + 1;

        token_copy = malloc(token_length + 1);
        if (token_copy == NULL)
                return (NULL);
        _strncpy(token_copy, current_token, token_length);
        token_copy[token_length] = '\0';

        return (token_copy);
}
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
	int status, i;
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
		free((void *)path);
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
	//	free((void *)path);
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
int main() {
  char *args[] = {"ls", NULL}; // Example arguments, you can modify this array to test with different commands

  int result = executeCommand(args);

  if (result == 0) {
    printf("Command executed successfully.\n");
  } else {
    printf("Failed to execute command.\n");
  }
  return 0;
}

