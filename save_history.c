
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minish.h"

#define HISTORY_FILE ".minish_history"



// Función para guardar el historial en el archivo
void save_history() {
    char *home = getenv("HOME");
    if (home == NULL) {
        perror("getenv");
        return;
    }

    char path[1024];
    snprintf(path, sizeof(path), "%s/%s", home, HISTORY_FILE);

    FILE *file = fopen(path, "w");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    for (int i = 0; i < history_count; i++) {
        fprintf(file, "%s\n", history[i]);
        free(history[i]); // Liberar memoria
    }

    fclose(file);
}
