#include <stdio.h>
#include <stdlib.h>

#define MAX_ARGS 64
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
char *_strtok(const char *str, const char *delim)
{
        static const char *last_token;
	const char *current_pos = last_token;
        const char *current_token = NULL;
        size_t token_length;
        char *token_copy;

	last_token = NULL;

        if (str != NULL)
        {
                last_token = str;
        }
        else
	{
		if (last_token == NULL || *last_token == '\0')
                        return (NULL);
	}
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

        last_token = current_token + token_length + 1;

        token_copy = malloc(token_length + 1);
        if (token_copy == NULL)
                return (NULL);
        _strncpy(token_copy, current_token, token_length);
        token_copy[token_length] = '\0';

        return (token_copy);
}
char **split_line(char *lineptr)
{
        const char delimiter[] = " \n\t\r\a\"";
        int args_index = 0;
        char *token;
        char **args_tokens;

        args_tokens = malloc(sizeof(char *) * (MAX_ARGS + 1));
        if (args_tokens == NULL)
                return (NULL);

        token = _strtok(lineptr, delimiter);
        while (token != NULL && args_index < MAX_ARGS)
        {
                args_tokens[args_index++] = token;
                token = _strtok(NULL, delimiter);
        }
        args_tokens[args_index] = NULL;

        return (args_tokens);
}
