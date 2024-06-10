#include <stdio.h> // Incluye la biblioteca estándar para operaciones de entrada/salida
#include <stdlib.h> // Incluye la biblioteca estándar para funciones de utilidad
#include <string.h> // Incluye la biblioteca estándar para funciones de manipulación de cadenas
#include <unistd.h> // Incluye la biblioteca estándar para funciones POSIX (e.g., getenv())
#include "minish.h" // Incluye el archivo de cabecera "minish.h"

#define HISTORY_FILE "minish_history.txt" // Define el nombre del archivo de historial

// Función para guardar el historial en el archivo
void save_history() {
    char *home = getenv("HOME"); // Obtiene el valor de la variable de entorno HOME
    if (home == NULL) { // Verifica si la variable de entorno HOME está definida
        error(EXIT_FAILURE,errno,"no encuentra HOME"); // Imprime un mensaje de error utilizando perror si la variable no está definida
    }

    char path[1024]; // Declara un buffer para almacenar la ruta del archivo de historial
    snprintf(path, sizeof(path), "%s/%s", home, HISTORY_FILE); // Construye la ruta completa del archivo de historial

    FILE *file = fopen(path, "w"); // Abre el archivo de historial en modo escritura
    if (file == NULL) { // Verifica si se pudo abrir el archivo
        error(EXIT_FAILURE,errno," no se pudo abrir el archivo"); // Imprime un mensaje de error utilizando si no se pudo abrir el archivo
        
    }
    if (history_count == 0) { // Verifica si el historial está vacío
        fclose(file); // Cierra el archivo de historial
        return; // Retorna sin escribir nada si el historial está vacío
    }
   
    // Escribe cada comando del historial en una línea del archivo de historial y libera la memoria
    for (int i = 0; i < history_count; i++) {
        fprintf(file, "%s\n", history[i]); // Escribe el comando en el archivo de historial
        free(history[i]); // Libera la memoria asignada para el comando
        
    }
    history_count = 0; // Establece el contador de historial a cero
    if (fclose(file) != 0) { // Cierra el archivo de historial y verifica si hubo errores al cerrar
        error(EXIT_FAILURE,errno,"Error al cerrar el archivo de historial");
    }
}