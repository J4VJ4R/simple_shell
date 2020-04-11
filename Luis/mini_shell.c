#include "shell.h"

void tokens(char *line, char **args)
{
	int position;
	char *token;

	token = strtok(line, " \r\t\n");

	for (position = 0; position < 10 && token != NULL; position++)
 	{
		args[position] = token;
		token = strtok(NULL, " \r\t\n");
	}
	args[position] = NULL;
}
int main(int argc, char **argv, char *env[])
{
	char *line = NULL, *args[10], *token;
	size_t bufsize = 0, read;
	int position = 0, i = 0, status;
	pid_t child_pid = 1;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		read = getline(&line, &bufsize, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			return (0);
		}
		if (*line != '\n')
		{
			tokens(line, args);
			if (args && args[0])
			{
				_execute(args);
			}
			position = 0;
			while (position < 10)
			{	args[position] = 0;
				position++;
			}
		}
	}
	position = 0;
	while (i < 10)
	{
		free(args[position]);
		position++;
	}
	free(args);
	free(line);
	return (0);
}
