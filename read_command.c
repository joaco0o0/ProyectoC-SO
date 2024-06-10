#include "minish.h" // Incluye el archivo de cabecera "minish.h"

// Función para leer el comando desde la entrada estándar
void read_command(char *line) {
    // Verifica si el último carácter de la línea es un salto de línea
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0'; // Si es así, lo reemplaza por el carácter nulo terminador de cadena
    }
}