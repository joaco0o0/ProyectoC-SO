#include "minish.h"

int builtin_exit(int argc,char **argv) {
    (void)argc; 
    int status = 0;
    if (argv[1] != NULL) {
        status = atoi(argv[1]); // Convierte el argumento opcional a entero
    }
    save_history(); // Guarda el historial en el archivo antes de salir
    exit(status); // Termina el shell con el estado de retorno especificado
}