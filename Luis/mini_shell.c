#include "shell.h"

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
    int position = 0, i = 0;
    //char **args = malloc(bufsize * sizeof(char *)); //asignamos memoria par no quedarnos cortos
    char *args[10];
    char *token; //para guardar un solo argumento
    pid_t child_pid = 1;
    int status;
    //pid_t child_pid;
    //line = malloc(bufsize * sizeof(char));

    // if (line == NULL)
    // {
    //     perror("No hay espacio para la linea de entrada");
    // }
    while (1)
    {

        if (isatty(STDIN_FILENO) == 1)
            write(STDOUT_FILENO, "#cisfun$ ", 10);

        read = getline(&line, &bufsize, stdin);
        //if (*line = '\n')
        if (read == -1)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            free(line);
            return (0);
        }

        //printf(":%s, %zu\n", line, read);
        //void conthand(int handle_signal);

        if (*line != '\n')
        {

            //    if (line == NULL)
            //     return (0);

            token = strtok(line, " \r\t\n");
            for (position = 0; position < 10 && token != NULL; position++)
            {
                args[position] = token;/* _strdup(token);*/
                token = strtok(NULL, " \r\t\n");
            }
            
            //printf("%s", args[0]);
            args[position] = NULL;
            //printf("ls entrada %s", args[0]);
            if (args && args[0])
            {
                _execute(args);
            }
            
            
          
            position = 0;

			while (position < 10)
			{
				args[position] = 0;
			    position++;
			}
        }
       
    }

    position = 0;
    while(i < 10)
    {
        free(args[position]);
        position++;
    }
    free(args);
    free(line);

    return (0);
}
