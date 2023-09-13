#include "shell.h"
/**
 * _strncpy-this is the main function
 *
 * it copies a string
 * @dest:where teh string is to be copied to
 * @src:the string to be copied
 * @n:the length of teh string
 * Return: copied, null terminated  string
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
/**
 * _strchr-this is the main function
 *
 * it searches astring
 * @str:teh string to be searched
 * @c: the charcater to be searched
 * Return: NULL
 */
const char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
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
	const char *last_token = NULL;
	const char *current_token = NULL;
	size_t token_length;
	char *token_copy;

	if (str != NULL)
		last_token = str;
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
/**
 * _strdup-this is the main function
 *
 * it duplicates a string
 * @src:initial string taht does not change
 * Return: duplicated string
 */
char *_strdup(const char *src)
{
	int len = 0;
	char *str;
	char *p;

	if (src == NULL)
		return (NULL);
	while (src[len])
	{
		len++;
	}
	/*allocate memory to store duplice*/
	str = malloc(len + 1);

	if (str == NULL)
	{
		perror("mem allocation failed");
		return (NULL);
	}
	/*since you cannot manipulate str, assign it to a pointer*/
	p = str;
	/*copy src to str*/
	while (*src)
	{
		*p++ = *src++;
	}
	*p = '\0';

	return (str);
}
/**
 * _strcpy-this is the main function
 *
 * it copies a string
 * @dest:where teh string is to be copied to
 * @src:the string to be copied
 * Return: copied, null terminated  string
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
