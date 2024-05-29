#include "minish.h"

struct builtin_struct builtin_arr[]= {
    {"exit", "builtin_exit", "exit [N] - termina el shell, admite un parámetro que es el status de retorno."},
    {"pid", "builtin_pid", "pid - muestra el process id del shell."},
    {"uid", "builtin_uid", "uid - muestra el userid como número y también el nombre de usuario."},
    {"gid", "builtin_gid", "gid - muestra el grupo principal y los grupos secundarios del usuario."},
    {"getenv", "builtin_getenv", "getenv variable [variable ...] - muestra el valor de dichas variables de ambiente."},
    {"setenv", "builtin_setenv", "setenv variable valor - define una variable nueva de ambiente o cambia el valor de una variable existente."},
    {"unsetenv", "builtin_unsetenv", "unsetenv var [var ...] - elimina variables de ambiente."},
    {"cd", "builtin_cd", "cd [dir] - Cambia el directorio corriente. Opciones:\n cd xxx - Cambia al directorio xxx\n cd     - Cambia al directorio valor de la variable de ambiente HOME\n"},
    {"status", "builtin_status", "status - muestra el status de retorno del último comando ejecutado."},
    {"help", "builtin_help", "help [comando] - escribe una ayuda para los comandos."},
    {"history", "builtin_history", "history [N] - muestra los 10 comandos anteriores."},
    {NULL, NULL, NULL}, // Marca el final del array
};

struct builtin_struct *builtin_lookup(char *cmd) {
    for (int i = 0; builtin_arr[i].cmd != NULL; i++) {
        if (strcmp(builtin_arr[i].cmd, cmd) == 0) {
            return &builtin_arr[i];
        }
    }
    return NULL; // No se encontró el comando
}