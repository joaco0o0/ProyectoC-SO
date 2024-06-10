#include "minish.h" // Incluye el archivo de cabecera "minish.h"

// Definición de la estructura para almacenar información sobre los comandos internos (built-ins)
struct builtin_struct builtin_arr[] = {
    {"exit", builtin_exit, "exit [N] - termina el shell, admite un parámetro que es el status de retorno."},
    {"pid", builtin_getpid, "pid - muestra el process id del shell."},
    {"uid", builtin_getuid, "uid - muestra el userid como número y también el nombre de usuario."},
    {"gid", builtin_getgid, "gid - muestra el grupo principal y los grupos secundarios del usuario."},
    {"getenv", builtin_getenv, "getenv variable [variable ...] - muestra el valor de dichas variables de ambiente."},
    {"setenv", builtin_setenv, "setenv variable valor - define una variable nueva de ambiente o cambia el valor de una variable existente."},
    {"unsetenv", builtin_unsetenv, "unsetenv var [var ...] - elimina variables de ambiente."},
    {"cd", builtin_cd, "cd [dir] - Cambia el directorio corriente. Opciones:\n cd xxx - Cambia al directorio xxx\n cd     - Cambia al directorio valor de la variable de ambiente HOME\n"},
    {"status", builtin_status, "status - muestra el status de retorno del último comando ejecutado."},
    {"help", builtin_help, "help [comando] - escribe una ayuda para los comandos."},
    {"history", builtin_history, "history [N] - muestra los 10 comandos anteriores."},
    {"dir", builtin_dir, "ir [directorio] - muestra el contenido del directorio actual o del directorio proporcionado." },
    {NULL, NULL, NULL}, // Marca el final del array
};

// Función para buscar un comando interno por su nombre
struct builtin_struct *builtin_lookup(char *cmd) {
    for (int i = 0; builtin_arr[i].cmd != NULL; i++) { // Itera sobre el array de comandos internos
        if (strcmp(builtin_arr[i].cmd, cmd) == 0) { // Compara el nombre del comando con el proporcionado
            return &builtin_arr[i]; // Devuelve un puntero a la estructura del comando si se encuentra
        }
    }
    return NULL; // Devuelve NULL si no se encuentra el comando
}