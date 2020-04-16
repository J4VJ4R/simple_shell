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
/**
 *_getline - Obtain a lin fron the standard input.
 *@line: Pointer wher the line its gonna be stored.
 *Return: Number of the line's characters.
 */
size_t _getline(char **line)
{
	size_t count = 0;
	char *initial = *line;
/*	char signal[1];*/

	if (*line == NULL)
	{
		write(STDOUT_FILENO, "Line is NULL", 13);
		return (-1);
	}
	while (1)
	{
		fflush(stdout);/*In case that standard output is open.*/
/*		_printf("args: %s\n", initial);*/
		count = read(STDIN_FILENO, *line, 1024);
		if (count < 1)
		{
			*line = initial;
			return (-1);
		}
		else if (count == 1 && (*line)[count - 1] == '\n')
		{
			*line = initial;
			if (string_len(initial) > 1)
			{
				return (string_len(initial));
			}
			return (0);
		}
		else if (count >= 1 && (*line)[count - 1] != '\n')
		{
			*line = *line + count;
		}
		else if (count >= 1)
		{
			(*line)[count - 1] = '\0';
			*line = initial;
			return (count);
		}
	}
	return (count);
}
