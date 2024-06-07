#include "minish.h"

int builtin_getpid(int argc,char **argv) {
    (void)argc;
    (void)argv;
    printf("PID del shell: %d\n", getpid()); //nunca falla la funcion getpid
    return 0;
}
