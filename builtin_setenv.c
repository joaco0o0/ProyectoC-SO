#include "minish.h" // Incluye el archivo de cabecera "minish.h"

// Función para manejar el comando 'setenv'
int builtin_setenv(int argc, char **argv) {
    (void)argc; // Indicamos que 'argc' no se usa para evitar advertencias del compilador
    
    // Verifica si se proporcionan los argumentos necesarios
    if (argv[1] == NULL || argv[2] == NULL) {
        fprintf(stderr, "Uso: setenv variable valor\n"); // Imprime un mensaje de uso correcto en stderr
        return 0; // Retorna 0 indicando éxito
    }

    // Intenta establecer la variable de entorno con el valor especificado
    if (setenv(argv[1], argv[2], 1) != 0) { // Si setenv devuelve un valor distinto de 0 (indicando error)
        perror("setenv"); // Imprime un mensaje de error utilizando perror
    }
    return 0; // Retorna 0 indicando éxito
}