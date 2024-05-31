#include "minish.h"

int builtin_setenv(int argc,char **argv) {
    (void)argc;  
    if (argv[1] == NULL || argv[2] == NULL) {
        fprintf(stderr, "Uso: setenv variable valor\n");
        return 0 ;
    }

    if (setenv(argv[1], argv[2], 1) != 0) {
        perror("setenv");
    }
    return 0;
}