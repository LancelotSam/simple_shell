#include "shell.h"
/**
 * my_env - this is the main function
 * it prints the enviroment
 * @args:an array of all variables in string
 *
 * Return: an integer status
 */
int my_env(char **args)
{
	int i = 0;

	args = environ;

	while (args[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}
