#include "minish.h"

void handle_exit(char **args) {
    int status = 0;
    if (args[1] != NULL) {
        status = atoi(args[1]); // Convierte el argumento opcional a entero
    }
    exit(status); // Termina el shell con el estado de retorno especificado
}