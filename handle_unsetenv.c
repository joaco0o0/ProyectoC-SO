#include "minish.h"

void handle_unsetenv(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Uso: unsetenv variable [variable ...]\n");
        return;
    }

    for (int i = 1; args[i] != NULL; i++) {
        if (unsetenv(args[i]) != 0) {
            perror("unsetenv");
        }
    }
}