#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minish.h"

#define HISTORY_FILE "minish_history.txt"


// Función para cargar el historial desde un archivo
void load_history() {
    // Define una variable de arreglo de caracteres para almacenar la ruta del archivo de historial.
    char path[1024];

    // Construye la ruta del archivo de historial combinando la variable de entorno HOME con el nombre del archivo de historial.
    snprintf(path, sizeof(path), "%s/%s", getenv("HOME"), HISTORY_FILE);

    // Intenta abrir el archivo de historial en modo lectura.
    FILE *file = fopen(path, "r");

    // Si no se puede abrir el archivo, termina la función.
    if (!file) return;

    // Define un arreglo de caracteres para almacenar cada línea leída del archivo de historial.
    char linea_historias_anteriores[1024];

    // Lee el archivo línea por línea.
    while (fgets(linea_historias_anteriores, sizeof(linea_historias_anteriores), file)) {
        // Elimina el carácter de nueva línea al final de la cadena, si existe.
        linea_historias_anteriores[strcspn(linea_historias_anteriores, "\n")] = '\0';

        // Añade la línea leída (un comando previo) al historial.
        add_to_history(linea_historias_anteriores);
    }

    // Cierra el archivo una vez terminado de leer todas las líneas.
    fclose(file);
}
