#include "minish.h"
extern char **environ;
int builtin_getenv(int argc,char **argv) {
    // Si no se especifican argumentos, se muestran todas las variables de entorno
    if (argv[1] == NULL) { 
        char **env = environ;
        while (*env != NULL) {
            printf("%s\n", *env);
            env++;
        } 
        
        return 0;
    }

    for (int i = 1; argv[i] != NULL; i++) {
        char *value = getenv(argv[i]);
        if (value != NULL) {
            printf("%s=%s\n", argv[i], value);
        } else {
            printf("%s no está definido\n", argv[i]);
        }
    }
    return 0;
}