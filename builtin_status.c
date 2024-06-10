#include "minish.h" // Incluye el archivo de cabecera "minish.h"

extern int status; // Declaración externa de la variable 'status' definida en otro lugar

// Función para manejar el comando 'status'
int builtin_status(int argc, char **argv) {
    (void)argc; // Indicamos que 'argc' no se usa para evitar advertencias del compilador
    (void)argv; // Indicamos que 'argv' no se usa para evitar advertencias del compilador
    
    // Imprime el estado de retorno del último comando ejecutado
    printf("Último estado de retorno: %d\n", status);
    
    return 0; // Retorna 0 indicando éxito
}