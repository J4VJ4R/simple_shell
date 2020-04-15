#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

void conthand(int handle_signal);
void _execute(char *args[]);
char *_strdup(char *str);
char **tokenizar(char *line);
#endif
