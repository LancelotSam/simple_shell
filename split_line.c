#include "shell.h"
/**
 * split_line-this is the main function
 * it splits lineptr input
 * @line:the input to be split
 * Return: splitted chars
 */
char **split_line(char *line)
{
	int buffer_size = 64;
	int index = 0;
	char *token;
	char **tokens;

	tokens = malloc(buffer_size * sizeof(char *));
	if (!tokens)
	{
		perror("memory allocation of tokens");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOKEN_DELIM);
	while (token != NULL)
	{
		if (token[0] != '#')/*token not a comment*/
		{
			tokens[index] = token;
			index++;
			if (index >= buffer_size)
			{
				buffer_size += buffer_size;
				tokens = realloc(tokens, buffer_size * sizeof(char *));
				if (tokens == NULL)
				{
					perror("reallocation failed");
					exit(EXIT_FAILURE);
				}
			}
			token = strtok(NULL, TOKEN_DELIM);
		}
	}
	tokens[index] = NULL;
	return (tokens);
}
