#include "shell.h"
/**
 * _strtok-this is the main function
 *
 * It tokenizes a string
 * @str: teh string to be tokenized
 * @delim: teh delimite rto be used to split the string
 * Return: tokens of splitted string
 */
char *_strtok(const char *str, const char *delim)
{
	static const char *last_token;
	const char *current_token = NULL;
	size_t token_length;
	char *token_copy;

	if (str != NULL)
	{
		last_token = NULL;
		last_token = str;
	}
	else
		if (last_token == NULL)
			return (NULL);
	str = last_token;
	/*skip leading delims*/
	while (*str && _strchr(delim, *str))
	{
		str++;
	}
	if (*str == '\0')
	{
		last_token = NULL;
		return (NULL);
	}
	current_token = str;
	while (*str && !_strchr(delim, *str))
	{ /*check end of current tok*/
		str++;
	}
	token_length = str - current_token;

	last_token = str + 1;

	token_copy = malloc(token_length + 1);
	if (token_copy == NULL)
		return (NULL);
	_strncpy(token_copy, current_token, token_length);
	token_copy[token_length] = '\0';

	return (token_copy);
}
