#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minish.h"

#define HISTORY_FILE ".minish_history"

// Función para manejar el comando 'history'
int builtin_history(int argc,char **argv) {
    int num = 10; // Número predeterminado de comandos a mostrar
    if (argv[1] != NULL) {
        num = atoi(argv[1]);
    }
    if (num > history_count) {
        num = history_count;
    }

    for (int i = history_count - num; i < history_count; i++) {
        printf("%d %s\n", i + 1, history[i]);
    }
    return 0;
}