#include "shell.h"
/**
 * main - this is the maain function
 * it calls other funtionss interactively orotherwise
 * @argc: number of argument provided
 * @args: an array of all arguments
 *
 * Return: an int status (0)
 */
int main(int argc, char *args[])
{
	int fd = STDIN_FILENO;

	if (isatty(fd) == 1)
		interactive(args[argc - 1]);
	else
		non_interactive(args[argc - 1]);
	return (0);
}
