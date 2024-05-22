// linea2argv.c

#include <stdlib.h>
#include <string.h>

int linea2argv(char *linea, int argc, char **argv) {
    int count = 0;
    char *token;
    char *delim = " \t\n";

    token = strtok(linea, delim);
    while (token != NULL && count < argc - 1) {
        argv[count] = strdup(token);
        if (argv[count] == NULL) {
            return -1; // Error en malloc
        }
        count++;
        token = strtok(NULL, delim);
    }

    argv[count] = NULL; // El último elemento debe ser NULL
    return count;
}
/*linea2argv: Esta función:
Recibe una línea de texto y la divide en palabras.
Asigna memoria para cada palabra y la guarda en argv.
Retorna la cantidad de palabras encontradas.*/