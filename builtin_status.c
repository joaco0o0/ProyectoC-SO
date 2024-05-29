#include "minish.h"
extern status;
int builtin_status(int argc, char **argv) {
    printf("Último estado de retorno: %d\n",status);
    return 0;
}