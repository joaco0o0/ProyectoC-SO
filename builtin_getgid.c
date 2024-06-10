#include "minish.h" // Incluye el archivo de cabecera "minish.h"

int builtin_getgid(int argc, char **argv) {
    (void)argc; // Indicamos que 'argc' no se usa para evitar advertencias del compilador
    (void)argv; // Indicamos que 'argv' no se usa para evitar advertencias del compilador
    
    gid_t gid = getgid(); // Obtiene el GID principal del proceso
    printf("GID principal: %d\n", gid); // Imprime el GID principal

    printf("GIDs secundarios: "); // Prepara la salida para los GIDs secundarios
    
    int ngroups = getgroups(0, NULL); // Obtiene el número de GIDs secundarios
    if (ngroups > 0) { // Si hay GIDs secundarios
        gid_t *groups = malloc(ngroups * sizeof(gid_t)); // Reserva memoria para los GIDs secundarios
        if (groups != NULL) { // Si la reserva de memoria fue exitosa
            ngroups = getgroups(ngroups, groups); // Obtiene los GIDs secundarios y los almacena en 'groups'
            for (int i = 0; i < ngroups; i++) { // Itera sobre los GIDs secundarios
                printf("%d ", groups[i]); // Imprime cada GID secundario
            }
            free(groups); // Libera la memoria asignada
        } else { // Si la reserva de memoria falla
            perror("malloc"); // Imprime un mensaje de error
        }
    }
    printf("\n"); // Nueva línea al final de la lista de GIDs secundarios
    return 0; // Retorna 0 indicando éxito
}