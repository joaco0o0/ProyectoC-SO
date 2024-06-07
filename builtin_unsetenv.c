#include "minish.h"

int builtin_unsetenv(int argc,char **argv) {
    (void)argc;
    if (argv[1] == NULL) {
        fprintf(stderr, "Uso: unsetenv variable [variable ...]\n");
        return 0 ;
    }

    for (int i = 1; argv[i] != NULL; i++) {
        if (unsetenv(argv[i]) != 0) {
            perror("unsetenv");
        }//REVISAR ESTO
    }
    return 0;
}