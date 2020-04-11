#include "shell.h"

/**
 * _execute - Function that execute the arguments.
 * @args: The arguments to read and will execute..
 * @status: The status of the arguments.
 * Return: Void Funtion.
 */

void _execute(char *args[])
{
    pid_t child_pid;
    int status;
    // int i;

    //printf("%d\n", child_pid);
    if ((child_pid = fork()) == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            perror("->Error:");
            exit(127);
        }
        
        //args[0] = NULL;
        //printf("\nls de salida%s", args[0]);
    }
    else
    {
        wait(&status);
    }
}
