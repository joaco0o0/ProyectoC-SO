
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "builtin.h"

#define MAXLINE 1024
#define MAXARGS 128

int main() {
    char linea[MAXLINE];
    char *argv[MAXARGS];
    int argc;

    while (1) {
        fprintf(stderr, "minibash> ");  // Prompt
        if (fgets(linea, MAXLINE, stdin) == NULL) {
            break;  // EOF
        }

        argc = linea2argv(linea, MAXARGS, argv);
        if (argc > 0) {
            ejecutar(argc, argv);
        }

        for (int i = 0; i < argc; i++) {
            free(argv[i]);
        }
    }
    return 0;
}