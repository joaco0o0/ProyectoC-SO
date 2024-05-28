#include "minish.h"

static char prev_dir[MAX_INPUT]; // Directorio anterior

void handle_cd(char **args) {
    char *dir;
    char cwd[MAX_INPUT];

    // Si no hay argumentos o el argumento es "~", cambia al directorio HOME
    if (args[1] == NULL || strcmp(args[1], "~") == 0) {
        dir = getenv("HOME");
    } else if (strcmp(args[1], "-") == 0) {
        // Cambia al directorio anterior
        dir = prev_dir;
    } else {
        // Cambia al directorio especificado
        dir = args[1];
    }

    // Obtiene el directorio actual antes de cambiar
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        strcpy(prev_dir, cwd);
    }

    // Cambia al directorio especificado
    if (chdir(dir) != 0) {
        perror("cd");
    } else {
        // Actualiza la variable de entorno PWD
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            setenv("PWD", cwd, 1);
        }
    }
}