#include "minish.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>
#include <error.h>


int linea2argv(char *linea, int argc, char **argv) {

    int narg = 0;
    char *token; 

    for (narg=0, token=strtok(linea, DELIM); token != NULL && narg < argc; narg++) { 
        
        // Asigna memoria y guarda el argumento.
        if (argv[narg] != NULL) {
            free(argv[narg]);
            argv[narg] = NULL;
        }
        argv[narg] = strdup(token);

        token = strtok(NULL, DELIM);
        
    }
    

    return narg; // Retorna el número de argumentos almacenados en argv.
}
/*Recibe una línea de texto y la divide en palabras.
Asigna memoria para cada palabra y la guarda en argv.
Retorna la cantidad de palabras encontradas.*/