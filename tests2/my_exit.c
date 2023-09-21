#include "shell.h"
/**
 * my_exit-this is the main function
 *
 * It exits with an integer status
 * @args:the expected exit argument to cmd line
 * Return: int exit status
 */
int my_exit(char **args)
{
	int status;

	if (args[1] == 0)
	{
		status = 0;
		return (status);/* No exit status arg provided, exit with 0*/
	}
	else
	{
		status = _atoi(args[1]);
		return (status);
	}

	return (status);
}
