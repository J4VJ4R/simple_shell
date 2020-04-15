#include "shell.h"
/**
 *_getchar - Get characters value.
 *Description: Get char by char from standard input.
 *Return: A character. -1 if fails.
 */
int _getchar(void)
{
	char buffer[1];

	if ((read(STDIN_FILENO, buffer, 1)) > 0)
	{
		return (buffer[0]);
	}
	return (EOF);
}
