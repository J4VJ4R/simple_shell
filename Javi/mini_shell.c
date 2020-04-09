#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
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
void _execute(char **args)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    //printf("%d\n", child_pid);
    if (child_pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            perror("./shell");
        }
        args[0] = NULL;
        //printf("\nls de salida%s", args[0]);
    }
    else
    {
        wait(&status);
    }
}

char *_strdup(char *str)
{
    int i, count;
    char *dest;

    if (str == 0)
    {
        return (NULL);
    }

    count = 0;

    while (*(str + count) != '\0')
    {
        count++;
    }

    dest = malloc(sizeof(char) * (count + 1));

    if (dest == 0)
    {
        return (NULL);
    }

    for (i = 0; *(str + i) != '\0'; i++)
    {
        *(dest + i) = *(str + i);
    }
    *(dest + i) = '\0';
    return (dest);
}

// void signal_c(void)
// {
//     signal(SIG_IGN, conthand);
// }
int main(int argc, char **argv, char *env[])
{
    char *line = NULL;
    size_t bufsize = 0, read;
    int position = 0;
    char **args = malloc(bufsize * sizeof(char *)); //asignamos memoria par no quedarnos cortos
    char *token;                                    //para guardar un solo argumento
    pid_t child_pid = 1;
    int status;
    //line = malloc(bufsize * sizeof(char));

    // if (line == NULL)
    // {
    //     perror("No hay espacio para la linea de entrada");
    // }
    while (1)
    {

        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "#cisfun$ ", 10);
        read = getline(&line, &bufsize, stdin);
        //if (*line = '\n')

        //printf(":%s, %zu\n", line, read);
        //void conthand(int handle_signal);

        if (*line != '\n')
        {

            if (read == -1)
            {
                write(STDOUT_FILENO, "\n", 1);
                exit(0);
            }
            //    if (line == NULL)
            //     return (0);

            token = strtok(line, " \r\t\n\a");
            while (token != NULL)
            {
                args[position] = _strdup(token);
                position++;

                token = strtok(NULL, " \r\t\n\a");
            }
            //printf("%s", args[0]);
            //args[position] = NULL;
            //printf("ls entrada %s", args[0]);
            _execute(args);
            //free(line);
            free(args);
           
            free(args[0]);
        }
        else
        {
            // write(STDIN_FILENO, "#cisfun$ ", 10);
        }
    }

   
    return (0);
}
