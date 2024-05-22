
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minish.h"

#define MAX_LINE 1024
#define MAX_ARGS 100
int main() {
    char line[MAX_LINE];
    char *argv[MAX_ARGS];
    int argc;
    int status;

    while (1) {
        fprintf(stderr, "minish> "); // Escribir prompt en standard error
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            break; // Salir en caso de EOF
        }

        argc = linea2argv(line, MAX_ARGS, argv);
        if (argc > 0) {
            status = ejecutar(argc, argv);
            for (int i = 0; i < argc; i++) {
                free(argv[i]); // Liberar memoria asignada en linea2argv
            }
        }
    }
    return 0;
}// MINISH_H
/*main: Esta es la función principal que contiene el bucle infinito que:
Muestra el prompt "minish> ".
Lee una línea de entrada del usuario.
Usa linea2argv para dividir la línea en argumentos.
Llama a ejecutar para procesar el comando.
Libera la memoria asignada para los argumentos.*/