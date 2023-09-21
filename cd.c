#include "shell.h"
/**
 * my_cd - this is the main function
 * it changes the working dir of the current shell
 * @args: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int my_cd(char **args)
{
	char *HomeDir, *oldDir;

	if (args[0] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL || strcmp(args[1], "") == 0)
		{
			HomeDir = getenv("HOME");
			if (HomeDir != NULL)
			{
				chdir(HomeDir);
			}
		}
		else if (strcmp(args[1], "-") == 0)
		{
			oldDir = getenv("OLDPWD");
			if (oldDir != NULL)
				chdir(oldDir);
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("error in function, dir not changed\n");
			}
		}
	}
	return (-1);
}
