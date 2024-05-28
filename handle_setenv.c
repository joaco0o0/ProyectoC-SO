#include "minish.h"

void handle_setenv(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Uso: setenv variable valor\n");
        return;
    }

    if (setenv(args[1], args[2], 1) != 0) {
        perror("setenv");
    }
}