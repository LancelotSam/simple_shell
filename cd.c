#include "shell.h"
/**
 * cd-this is the main function
 *
 * It changes the directory
 * @args:the list of commands
 * Return: 0 if successful, -1 if unsuccessful
 */
int cd(char **args)
{
	char *HomeDir, *oldDir, *newDir;

	if (args[0] == NULL)
	{
		perror("Expected arguments to cd: \"cd\"\n");
		return (-1);
	}
	if (_strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL || _strcmp(args[1], "") == 0)
		{
			HomeDir = getenv("HOME");
			if (HomeDir != NULL)
			{
				chdir(HomeDir);
			}
		}
		else if (_strcmp(args[1], "-") == 0)
		{
			oldDir = getenv("OLDPWD");
			if (oldDir != NULL)
			{
				chdir(oldDir);
			}
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("Error changing current directory");
				return (-1);
			}
		}
	}
	/*Null is memory, allows dynamic allocation, 0 size of buff*/
	newDir = getcwd(NULL, 0);
	if (newDir != NULL)
	{
		setenv("PWD", newDir, 1);/*1 is overwite as pwd exits*/
	}
	else
	{
		perror("Error getting cwd");
		return (-1);
	}
	return (0);
}
