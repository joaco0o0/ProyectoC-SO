#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minish.h"

#define HISTORY_FILE ".minish_history"



// Función para cargar el historial desde el archivo
void load_history() {
    char *home = getenv("HOME");
    if (home == NULL) {
        error(EXIT_FAILURE,errno,"error en getenv");;
        return;
    }

    char path[1024];
    snprintf(path, sizeof(path), "%s/%s", home, HISTORY_FILE);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return; // No hay historial previo
    }

    char line[MAX_INPUT];
    while (fgets(line, sizeof(line), file) != NULL) {
        read_command(line); // Eliminar el carácter de nueva línea
        history[history_count] = line; // Guardar el comando en el historial
        history_count++;
    }

    fclose(file);
}