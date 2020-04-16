#include "shell.h"
/**
 * tokens - Function that split a line of arguments.
 * @args: List of args.
 * @line: Line of arguments.
 * Return: Void Funtion.
 */

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
/**
 * main - Execute depends of type format.
 * @argv: Argv.
 * @argc: Argc
 * @env: Env.
 * Return: Void Funtion.
 */
int main(int argc, char **argv, char *env[])
{
	char *line = NULL, *args[10];
	size_t bufsize = 0;
	int position = 0, i = 0, read;
	(void)argc;
	(void)argv;

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
		if (_strcmp(line, "exit\n") == 0)
			exit(0);
		if (*line != '\n')
		{
			tokens(line, args);
			_execute(args, env);
			position = 0;
			while (position < 10)
			{
				args[position] = 0;
				position++;
			}
		}
	}
	free(args);
	(void)i;
	return (0);
}

