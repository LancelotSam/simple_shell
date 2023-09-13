#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 10
#define MAX_TOTAL_LENGTH 1024
#define MAX_PATHS 10

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h> /*for size*/
#include <sys/types.h>
#include <sys/wait.h>

void MyShell(void);
char *read_line(void);
char **split_line(char *lineptr);
extern char **environ;
int env(char **args);
int my_exit(char **args);
int executeCommand(char **args);
char *_strncpy(char *dest, const char *src, size_t n);
const char *_strchr(const char *str, int c);
char *_strtok(const char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strdup(const char *src);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
int _atoi(const char *str);

#endif
