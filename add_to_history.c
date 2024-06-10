#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minish.h"

#define HISTORY_FILE "minish_history.txt"


// Función para agregar un comando al historial
void add_to_history(char *cmd) {
    
    if (history_count < MAX_HISTORY) {
        history[history_count++] = strdup(cmd); // Agregar comando al historial

    } else {
        if (history[0] != NULL){
            free(history[0]); // Liberar el comando más antiguo
        }
        
        for (int i = 1; i < history_count; i++) {
            history[i - 1] = history[i]; // Desplazar comandos
        }
        history[MAX_HISTORY - 1] = strdup(cmd); // Agregar comando al historial
    }
}