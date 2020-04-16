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
int string_len(char *s);
void _execute(char *args[], char *env[]);
int _getchar(void);
size_t _getline(char **line);
char *_strdup(char *str);
char **tokenizar(char *line);
int _strcmp(char *s1, char *s2);

#endif
