#include "shell.h"
/**
 *string_len - Obtain the lenght of the string.
 *@s: String to get lenght.
 *Return: The lenght of the string.
 */
int string_len(char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
