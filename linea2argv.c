#include "minish.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>
// Esta función convierte una línea de entrada en una lista de argumentos separados por delimitadores
void linea2argv(char *line, char **args) {
    int position = 0; // Inicializa la posición del array de argumentos
    // strtok es una función que divide la cadena 'line' en tokens basados en los delimitadores especificados en DELIM
    char *token = strtok(line, DELIM);

    // Bucle para iterar sobre cada token obtenido de la cadena 'line'
    while (token != NULL) {
        // Asigna el token actual a la posición actual del array de argumentos
        args[position++] = token;
        // Obtiene el siguiente token en la cadena 'line'
        token = strtok(NULL, DELIM);
    }
    // Marca el final del array de argumentos con NULL
    args[position] = NULL;
}
/*linea2argv: Esta función:
Recibe una línea de texto y la divide en palabras.
Asigna memoria para cada palabra y la guarda en argv.
Retorna la cantidad de palabras encontradas.*/