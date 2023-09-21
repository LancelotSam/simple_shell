#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define TOKEN_DELIM " \n\t\r\a\""

extern char **environ;
void interactive(char *name);
void non_interactive(char *name);
int my_cd(char **args);
char *read_line(void);
char **split_line(char *command);
int my_env(char **args);
int my_exit(char **args);
int executeCommand(char **argv, char *name);
int system_call(char **args, char *name);
int search_command(char *full_path, char **args);
char *read_input(void);
int my_pipe(char *args[]);
int semiColon(char *args[]);
void execute_Command(char **commandArgs);
int semiColon(char *args[]);

#endif

