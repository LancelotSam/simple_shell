#include "shell.h"
/**
 * _strcmp-this is the main function
 *
 * It compares two strings
 * @s1:the first string
 * @s2:the second string
 * Return: -1 if s1<s2, 1 if s1>s2, 0 if s1=s2
 */
int _strcmp(const char *s1, const char *s2)
{
	size_t i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}
/**
 * _strcat-this is the main function
 *
 * It concatenates two strings
 * @dest:the destination string
 * @src:teh source string
 * Return:concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = 0, i = 0, TOTAL_LEN = 64;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	while (src[i] != '\0' && i < TOTAL_LEN - dest_len)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';

	return (dest);
}
/**
 * _strlen-this is the main function
 *
 * it calculates teh length of a string
 * @str:string length to be determined
 * Return:int length
 */
int _strlen(const char *str)
{
	int index = 0;

	if (*str == '\0')
		return (0);
	while (str[index])
	{
		index++;
	}

	return (index);
}
