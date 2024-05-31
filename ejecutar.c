#include "minish.h"

extern int status; // Variable global para almacenar el último estado de retorno

int ejecutar(int argc,char **argv) {
    
    if (argc == 0) {
        return 0; // No se ingresó comando
    }
    // Comparación de comandos internos
    struct builtin_struct *builtin = builtin_lookup(argv[0]);
    if (builtin != NULL) {
        return builtin->func(argc,argv);
    }
    
    
    return externo(argc,argv);
    
}