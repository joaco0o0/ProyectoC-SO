#include "minish.h"

extern char **environ;
int status = 0;
int main() {
    char line[MAX_INPUT];
    char *args[MAX_ARGS];

    // Ciclo principal del shell
    do {
        printf("minish> "); // Prompt del shell
        if (fgets(line, sizeof(line), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        read_command(line); // Ajusta la línea de entrada eliminando el carácter de nueva línea
        linea2argv(line, args); // Convierte la línea de entrada en una lista de argumentos
        status = execute_command(args); // Ejecuta el comando ingresado por el usuario
    } while (status == 0);

    return status;
}