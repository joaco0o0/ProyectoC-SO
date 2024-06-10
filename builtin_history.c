#include <stdio.h> // Incluye la biblioteca estándar para operaciones de entrada/salida
#include <stdlib.h> // Incluye la biblioteca estándar para funciones de utilidad
#include <string.h> // Incluye la biblioteca estándar para funciones de manipulación de cadenas
#include <unistd.h> // Incluye la biblioteca estándar para funciones POSIX (e.g., getpid())
#include "minish.h" // Incluye el archivo de cabecera "minish.h"

#define HISTORY_FILE ".minish_history" // Define el nombre del archivo de historial

// Función para manejar el comando 'history'
int builtin_history(int argc, char **argv) {
    int num = 10; // Número predeterminado de comandos a mostrar
    (void)argc; // Indicamos que 'argc' no se usa para evitar advertencias del compilador
    
    if (argv[1] != NULL) { // Si se proporciona un argumento adicional (número de comandos a mostrar)
        num = atoi(argv[1]); // Convierte el argumento en un entero
    }
    if (num > history_count) { // Si el número de comandos a mostrar es mayor que el historial disponible
        num = history_count; // Ajusta el número de comandos a mostrar al tamaño del historial
    }

    // Itera sobre los comandos en el historial y los muestra
    for (int i = history_count - num; i < history_count; i++) {
        printf("%d %s\n", i + 1, history[i]); // Imprime el número de comando y el comando correspondiente
    }
    return 0; // Retorna 0 indicando éxito
}