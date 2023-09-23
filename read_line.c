#include "shell.h"
/**
 * read_line - reads user input
 *
 * Return: a string read from user
 */
char *read_line(void)
{
	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar(); /* read first char from stream */
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else if (character == '#' && i == 0)
		{
			while (character != '\n' && character != EOF)
				;/*skips the rest of teh fline*/
			free(line);
			return (NULL); /*indicate a comment line*/
		}
		line[i] = character;
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
