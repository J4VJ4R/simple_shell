#include "shell.h"
/**
 * verification - Function that execute the arguments.
 * @args: The arguments to read and will execute..
 * Return: Void Funtion.
 */
int verification(char **args)
{
	int i = 0, j = 0;

	while (args[i] != NULL)
	{
		j = 0;
		while (*(args[i] + j) != '\0')
		{
			j++;
		}
		i++;
	}
	if (i > 0)
		return (0);
	return (1);
}
/**
 * _execute - Function that execute the arguments.
 * @args: The arguments to read and will execute..
 * @env: this a enviroment
 * Return: Void Funtion.
 */

void _execute(char *args[], char *env[])
{
	pid_t child_pid;
	int status = 0, i = 0, box = 0;

	box = verification(args);
	if (box == 1)
		return;
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("./shell");
			while (args[i])
			{
				free(args[i]);
				i++;
			}
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
