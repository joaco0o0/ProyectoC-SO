#ifndef MINISH_H
#define MINISH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>
#include <error.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGV 64
#define DELIM " \t\r\n\a"
#define MAX_HISTORY 15

struct builtin_struct { 
char *cmd;                           // nombre del comando interno
int (*func) (int, char **);     // nombre de la función que lo ejecuta 
char *help_txt;                      // el texto de ayuda  
};    
extern struct builtin_struct builtin_arr[];               // array que almacena todos los builtins a desarrollar           
extern struct builtin_struct * builtin_lookup(char *cmd); // la función que busca un builtin por su nombre 
void read_command(char *line);
void show_prompt();
int linea2argv(char *line,int argc,char **argv); //sacar el asterisco
int ejecutar(int argc,char **argv);
int builtin_exit(int argc,char **argv);
int builtin_help(int argc,char **argv);
int builtin_getpid(int argc, char **argv);
int builtin_getuid(int argc, char **argv);
int builtin_getgid(int argc, char **argv);
int builtin_getenv(int argc, char **argv);
int builtin_setenv(int argc, char **argv);
int builtin_unsetenv(int argc, char **argv);
int builtin_cd(int argc, char **argv);
int builtin_dir(int argc, char **argv);
int builtin_status(int argc, char **argv); 
int builtin_history(int argc, char **argv);
int externo(int argc,char **argv);
// Declaraciones para el historial
extern char *history[MAX_HISTORY];
extern int history_count;

void load_history();
void save_history();
void add_to_history(char *cmd);
void free_argv(int argc,char **argv);

#endif // MINISH_H