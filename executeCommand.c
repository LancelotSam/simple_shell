#include "shell.h"
/**
 * executeCommand-this is the main function
 * it executes received commands
 * @argv: tokens to be executed
 * @name: program name
 *
 * Return: an interger indicating suceess or failure
 */
int executeCommand(char **argv, char *name)
{
	unsigned long int index;
	char *built_ins_list[] = {
		"exit",
		"env",
		"cd"
	};
	int (*built_ins[])(char **) = {
		&my_exit,
		&my_env,
		&my_cd
	};

	if (!argv)
	{
		/*empty command */
		return (-1);
	}
	for (index = 0; index < sizeof(built_ins_list) / sizeof(char *); index++)
	{
		/* if there is a match in the builtins */
		if (strcmp(argv[0], built_ins_list[index]) == 0)
		{
			return ((*built_ins[index])(argv));
		}
	}
	/*Create a process to execute */
	return (system_call(argv, name));
}
