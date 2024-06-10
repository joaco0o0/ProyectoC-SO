#include "minish.h" // Incluye el archivo de cabecera "minish.h"

// Función para manejar el comando 'unsetenv'
int builtin_unsetenv(int argc, char **argv) {
    (void)argc; // Indicamos que 'argc' no se usa para evitar advertencias del compilador
    
    // Verifica si se proporciona al menos un argumento
    if (argv[1] == NULL) {
        fprintf(stderr, "Uso: unsetenv variable [variable ...]\n"); // Imprime un mensaje de uso correcto en stderr
        return 0; // Retorna 0 indicando éxito
    }

    // Itera sobre los argumentos proporcionados y elimina las variables de entorno correspondientes
    for (int i = 1; argv[i] != NULL; i++) {
        if (unsetenv(argv[i]) != 0) { // Intenta eliminar la variable de entorno especificada
            perror("unsetenv"); // Imprime un mensaje de error utilizando perror
        }
    }
    return 0; // Retorna 0 indicando éxito
}