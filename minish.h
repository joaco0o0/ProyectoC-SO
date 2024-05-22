// minish.h

#ifndef MINISH_H
#define MINISH_H

struct builtin_struct {
    char *cmd;                   // nombre del comando interno
    int (*func) (int, char **);  // la función que lo ejecuta
    char *help_txt;              // el texto de ayuda
};

extern struct builtin_struct builtin_arr[]; // array que almacena todos los builtins
extern struct builtin_struct *builtin_lookup(char *cmd); // función para buscar un builtin

int linea2argv(char *linea, int argc, char **argv); // función para separar línea en argumentos
int ejecutar(int argc, char **argv);                // función para ejecutar comandos
int externo(int argc, char **argv);                 // función para ejecutar comandos externos

// Prototipos de las funciones builtin
int builtin_exit(int argc, char **argv);
int builtin_pid(int argc, char **argv);
int builtin_uid(int argc, char **argv);

#endif // MINISH_H