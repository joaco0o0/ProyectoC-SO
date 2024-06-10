#include "minish.h" // Incluye el archivo de cabecera "minish.h"

int builtin_getpid(int argc, char **argv) {
    (void)argc; // Indicamos que 'argc' no se usa para evitar advertencias del compilador
    (void)argv; // Indicamos que 'argv' no se usa para evitar advertencias del compilador
    
    printf("PID del shell: %d\n", getpid()); // Imprime el PID (ID de proceso) del shell actual
    
    return 0; // Retorna 0 indicando éxito
}