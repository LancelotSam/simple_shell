#include "shell.h"
/**
 * main - this is the main function
 * It runs custom shell onteractively & non-interactively
 * Return: 0 if successfully executed
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		interactive();
	}
	else
	{
		non_interactive();
	}
	return (0);
}
