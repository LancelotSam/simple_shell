#include "shell.h"
/**
 * my_exit - this is the main function
 * it exits the shell
 * @args: an array of commands received
 *
 * Return: an interger
 */
int my_exit(char **args)
{
	/* exit with int status */
	if (args[1])
	{
		return (atoi(args[1]));
	}
	/* exit success */
	else
	{
		return (0);
	}
}
