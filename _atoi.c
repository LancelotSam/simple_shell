#include "shell.h"
/**
 * _atoi-this is the main function
 *
 * It converts a string into an integer
 * @str:teh string to be converted
 * Return:int argument
 */
int _atoi(const char *str)
{
	int i = 0;/*initialize index for first digit*/
	int res = 0;/*initialize result*/
	int sign = 1;/*sign init as positive*/

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			/*str[i] - '\0', subtracts ascii val of 0,i.e 48*/
			res = res * 10 + str[i] - '0';
		}
	}
	if (str[i] != '\0')
	{
		return (-1);
	}
	return (res * sign);
}
