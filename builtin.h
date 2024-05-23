// builtin.h
#ifndef BUILTIN_H
#define BUILTIN_H

struct builtin_struct {
    char *cmd;                  // nombre del comando interno
    int (*func)(int, char **);  // la función que lo ejecuta
    char *help_txt;             // el texto de ayuda
};

extern struct builtin_struct builtin_arr[];
extern struct builtin_struct *builtin_lookup(char *cmd);

int linea2argv(char *linea, int argc, char **argv);
int ejecutar(int argc, char **argv);
int externo(int argc, char **argv);

// Prototipos para los builtins
int builtin_exit(int argc, char **argv);
int builtin_pid(int argc, char **argv);
int builtin_uid(int argc, char **argv);

#endif