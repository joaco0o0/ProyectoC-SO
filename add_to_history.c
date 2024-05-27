#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minish.h"

#define HISTORY_FILE ".minish_history"


// Función para agregar un comando al historial
void add_to_history(const char *cmd) {
    if (history_count < MAX_HISTORY) {
        history[history_count++] = strdup(cmd);
    } else {
        free(history[0]); // Liberar el comando más antiguo
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i]; // Desplazar comandos
        }
        history[MAX_HISTORY - 1] = strdup(cmd);
    }
}