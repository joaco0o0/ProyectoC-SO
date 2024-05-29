#include "minish.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>
// Esta función convierte una línea de entrada en una lista de argumentos separados por delimitadores
/*int linea2argv(char *line, int argc,char **argv)  {
    int position = 0; // Inicializa la posición del array de argumentos
    // strtok es una función que divide la cadena 'line' en tokens basados en los delimitadores especificados en DELIM
    char *token = strtok(line, DELIM);

    // Bucle para iterar sobre cada token obtenido de la cadena 'line'
    while (token != NULL) {
        // Asigna el token actual a la posición actual del array de argumentos
        argv[position++] = token;
        // Obtiene el siguiente token en la cadena 'line'
        token = strtok(NULL, DELIM);
    }
    // Marca el final del array de argumentos con NULL
    argv[position] = NULL;
    argc=position; // Asigna la cantidad de argumentos encontrados
    return 0;
}
/*linea2argv: Esta función:
Recibe una línea de texto y la divide en palabras.
Asigna memoria para cada palabra y la guarda en argv.
Retorna la cantidad de palabras encontradas.*/

int linea2argv(char *linea, int argc, char **argv) {
    // Primero, elimina el carácter de nueva línea al final, si existe.

    
    int numArgs = 0;
    char *token = strtok(linea, " ");

    while (token != NULL && numArgs < argc) {
        // Asigna memoria y guarda el argumento.
        argv[numArgs] = (char *) malloc(strlen(token) + 1);
        if (argv[numArgs] == NULL) {
            // Manejo de error de memoria, liberar memoria asignada.
            for (int i = 0; i < numArgs; i++) {
                free(argv[i]);
            }
            return -1; // Retorna error en caso de que no pueda asignar memoria.
        }
        strcpy(argv[numArgs], token);
        numArgs++;
        token = strtok(NULL, " ");

    }
    

    return numArgs; // Retorna el número de argumentos almacenados en argv.
}