#include "shell.h"

/**
 * _execute - Function that execute the arguments.
 * @args: The arguments to read and will execute..
 * Return: Void Funtion.
 */

void _execute(char *args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("->Error:");
			exit(127);
		}
	}
	else
	{
	wait(&status);
	}
}
