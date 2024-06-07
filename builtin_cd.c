#include "minish.h"

static char prev_dir[MAX_INPUT]; // Directorio anterior

int builtin_cd(int argc,char **argv) {
    char *dir;
    char cwd[MAX_INPUT];
    (void)argc;

    // Si no hay argumentos o el argumento es "~", cambia al directorio HOME
    if (argv[1] == NULL || strcmp(argv[1], "~") == 0) {
        dir = getenv("HOME");
    } else if (strcmp(argv[1], "-") == 0) {
        // Cambia al directorio anterior
        dir = prev_dir;
    } else {
        // Cambia al directorio especificado
        dir = argv[1];
    }

    // Obtiene el directorio actual antes de cambiar
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        strcpy(prev_dir, cwd);
    }

    // Cambia al directorio especificado
    if (chdir(dir) != 0) {
        error(EXIT_FAILURE,errno,"error en el directorio");;
    } else {
        // Actualiza la variable de entorno PWD
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            setenv("PWD", cwd, 1);
        }
    }
    return 0;
}