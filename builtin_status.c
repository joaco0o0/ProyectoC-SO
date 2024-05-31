#include "minish.h"
extern int status;
int builtin_status(int argc, char **argv) {
    (void)argc;
    (void)argv;
    
    printf("Último estado de retorno: %d\n",status);
    return 0;
}