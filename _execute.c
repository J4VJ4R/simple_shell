#include "shell.h"

/**
 * _execute - Function that execute the arguments.
 * @args: The arguments to read and will execute..
 * Return: Void Funtion.
 */

void _execute(char *args[])
{
	pid_t child_pid;
	int status = 0, i = 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
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
