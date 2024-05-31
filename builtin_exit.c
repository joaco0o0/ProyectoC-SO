#include "minish.h"

int builtin_exit(int argc,char **argv) {
    (void)argc; 
    int status = 0;
    if (argv[1] != NULL) {
        status = atoi(argv[1]); // Convierte el argumento opcional a entero
    }
    exit(status); // Termina el shell con el estado de retorno especificado
    return 0;
}