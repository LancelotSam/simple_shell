#include "shell.h"
/**
 * system_call - this is the main function
 * it searhces for a command in the system
 * @args: the command and option
 * @name: program name
 *
 * Return: integer indication sucess or failure
 */
int system_call(char **args, char *name)
{
	char path[1024], *main_path = getenv("PATH"), *directory;
	int index = 0;
	char full_path[256];

	while (args[index] != NULL)
	{
		if (strcmp(args[index], "|") == 0)
		{
			return (my_pipe(args));
		}
		index++;
	}
	if (access(args[0], X_OK) == 0)
	{
		return (search_command(args[0], args));
	}
	strcpy(path, main_path);
	directory = strtok(path, ":");
	while (directory != NULL)
	{
		strcpy(full_path, directory);
		strcat(full_path, "/");
		strcat(full_path, args[0]);
		if (access(full_path, X_OK) == 0)
		{
			return (search_command(full_path, args));
		}
		directory = strtok(NULL, ":");
	}
	perror(name);
	return (-1);
}
