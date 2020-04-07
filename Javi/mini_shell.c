#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
void conthand(int handle_signal);
/**
 * conthand - That handle the signal of ^C.
 * @handle_signal: The signal that enters..
 *
 * Return: Void Funtion.
 */
void conthand(int handle_signal)
{
	if (handle_signal)
		write(STDIN_FILENO, "\n#cisfun$ ", 10);
}

int main(int argc, char **argv, char *env[])
{
    char *line = NULL;
    size_t bufsize = 32, read;
    int position = 0;
    char **args = malloc(bufsize * sizeof(char *)); //asignamos memoria par no quedarnos cortos
    char *token;                                    //para guardar un solo argumento
    pid_t child_pid;
    int status;
    line = malloc(bufsize * sizeof(char));
    if (line == NULL)
    {
        perror("No hay espacio para la linea de entrada");
    }
    while (1)
    {
        printf("1");
        printf("#cisfun$ ");
        
        read = getline(&line, &bufsize, stdin);
        //tests 
        if (read < 0)
        {
            perror("Unexpected EOF or error:");
            exit(EXIT_FAILURE);
        }

        token = strtok(line, "\n");
        position++;
        void conthand(token);
        // while (token != NULL)
        // {
        //     args[position] = token;
        //     position++;

        //     token = strtok(NULL, " \r\t\n\a");
        // }
        // args[position] = NULL;
        //args = args;

        child_pid = fork();
        if (child_pid == 0)
        {
            args[0] = line;
            if (execve(args[0], &argv[0], env[0]) == -1)
            {
                perror("./shell: ");
            }
            // printf("2");
            else
            {
                wait(&status);
            }
        }
    }
    free(line);
    free(args);
    return (0);
}
