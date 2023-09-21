#include "shell.h"
/**
 * _getline-this is the main function
 *
 * it reads line input from stdin
 * @lineptr: the linepoinnter with input
 * @n:buffer
 * @stream:stdin
 * Return:current position at lineptr
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t read_chars;
	char *new_buff;
	size_t current_position = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		perror("invalid parameters");
		return (-1);
	}
	if (*lineptr == NULL)
	{
		*n = 128; /* Set initial buffer size*/
		*lineptr = malloc(sizeof(char) * *n);
		if (*lineptr == NULL)
		{
			perror("memory allocation failed");
			return (-1);
		}
	}
	read_chars = fgetc(stream);
	while (read_chars != EOF)
	{
		if (current_position >= *n - 1)
		{
			*n *= 2;
		/*	free(*lineptr);*/
			new_buff = realloc(*lineptr, sizeof(char) * *n);
			if (new_buff == NULL)
			{
				perror("Mem reallocation failed");
				return (-1);
			}
			*lineptr = new_buff;
			free(*lineptr);
		}
		(*lineptr)[current_position++] = (char)read_chars;
		if (read_chars == '\n')
		{
			break;
		}
		read_chars = fgetc(stream);
	}

	(*lineptr)[current_position] = '\0';

	if (current_position == 0 && read_chars == EOF)
	{
		perror("no chars read");
		free(*lineptr);
		*lineptr = NULL;
		return (-1);
	}

	free(*lineptr);

	return (current_position);
}
/**
 * read_line-this is the main function
 *
 * it reads user input from stdin
 *
 * Return: returns lineptr
 */
char *read_line(void)
{
	char *lineptr = NULL;
	size_t buffer = 0;
	ssize_t read_inp;

	read_inp = _getline(&lineptr, &buffer, stdin);

	if (read_inp == -1 || read_inp == EOF)
	{
		perror("Exiting shell");
		free(lineptr);
		exit(EXIT_SUCCESS);
	} else if (read_inp == 1)
	{
		perror("Empty line");
		free(lineptr);
		lineptr = malloc(2); /* mem for '\n' and '\0'*/
		lineptr[0] = '\n';
		lineptr[1] = '\0';
	} else if (lineptr[read_inp - 1] == '\n')
	{
		lineptr[read_inp - 1] = '\0';
	}

	return (lineptr);
}
