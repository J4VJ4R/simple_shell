#include "holberton.h"
/**
 * execve - Funtion.
 * @ac: Argc.
 * @av: Argv.
 * @envp: Enviroment.
 * @f: Time promgram execute.
 * Return: Void.
 */
void execve(int ac, char *av[], char *envp[], int f)
{
	int a = 0;
	char *paths = NULL;

	(void) f;
	paths = path(av[1], envp);
	if (ac >= 1)
	{
		a = execve(paths, (av + 1), envp);
		if (a == -1)
		{
			perror("error");
			free(paths);
			exit(0);
		}
	}
}
