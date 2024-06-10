#include "minish.h" // Incluye el archivo de cabecera "minish.h"

int builtin_getuid(int argc, char **argv) {
    (void)argc; // Indicamos que 'argc' no se usa para evitar advertencias del compilador
    (void)argv; // Indicamos que 'argv' no se usa para evitar advertencias del compilador
    
    uid_t uid = getuid(); // Obtiene el UID (ID de usuario) del proceso actual
    struct passwd *pw = getpwuid(uid); // Obtiene la estructura passwd correspondiente al UID
    
    if (pw != NULL) { // Si la estructura passwd no es NULL (es decir, se encontró el UID)
        printf("UID: %d (%s)\n", uid, pw->pw_name); // Imprime el UID y el nombre de usuario asociado
    } else { // Si la estructura passwd es NULL (es decir, no se encontró el UID)
        perror("getpwuid"); // Imprime un mensaje de error
    }
    
    return 0; // Retorna 0 indicando éxito
}