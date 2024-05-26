#ifndef MINISH_H
#define MINISH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64
#define DELIM " \t\r\n\a"

void read_command(char *line);
void linea2argv(char *line, char **args);
int execute_command(char **args);
void handle_exit(char **args);
void handle_help();
void handle_getpid();
void handle_getuid();
void handle_getgid();
void handle_getenv(char **args);
void handle_setenv(char **args);
void handle_unsetenv(char **args);
void handle_cd(char **args);
void handle_status(int status);

#endif // MINISH_H