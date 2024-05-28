#include "minish.h"
extern char **environ;
void handle_getenv(char **args) {
    // Si no se especifican argumentos, se muestran todas las variables de entorno
    if (args[1] == NULL) { 
        char **env = environ;
        while (*env != NULL) {
            printf("%s\n", *env);
            env++;
        } 
        
        return;
    }

    for (int i = 1; args[i] != NULL; i++) {
        char *value = getenv(args[i]);
        if (value != NULL) {
            printf("%s=%s\n", args[i], value);
        } else {
            printf("%s no está definido\n", args[i]);
        }
    }
}