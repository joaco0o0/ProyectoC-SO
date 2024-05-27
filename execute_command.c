#include "minish.h"

extern int status; // Variable global para almacenar el último estado de retorno

int execute_command(char **args) {
    if (args[0] == NULL) {
        return 0; // No se ingresó comando
    }

    // Comparación de comandos internos
    if (strcmp(args[0], "exit") == 0) {
        handle_exit(args); // Maneja el comando 'exit'
    } else if (strcmp(args[0], "help") == 0) {
        handle_help(); // Maneja el comando 'help'
    } else if (strcmp(args[0], "pid") == 0) {
        handle_getpid(); // Maneja el comando 'pid'
    } else if (strcmp(args[0], "uid") == 0) {
        handle_getuid(); // Maneja el comando 'uid'
    } else if (strcmp(args[0], "gid") == 0) {
        handle_getgid(); // Maneja el comando 'gid'
    } else if (strcmp(args[0], "getenv") == 0) {
        handle_getenv(args); // Maneja el comando 'getenv'
    } else if (strcmp(args[0], "setenv") == 0) {
        handle_setenv(args); // Maneja el comando 'setenv'
    } else if (strcmp(args[0], "unsetenv") == 0) {
        handle_unsetenv(args); // Maneja el comando 'unsetenv'
    }  else if (strcmp(args[0], "cd") == 0) {
        handle_cd(args); // Maneja el comando 'cd'
    } else if (strcmp(args[0], "status") == 0) {
        handle_status(status); // Maneja el comando 'status'
    } else if (strcmp(args[0], "history") == 0) {
        handle_history(args); // Maneja el comando 'history'
    }else {
        printf("Comando no reconocido: %s\n", args[0]); // Comando no reconocido
    }

    return 0;
}