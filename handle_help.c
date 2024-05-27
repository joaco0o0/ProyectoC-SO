#include "minish.h"

void handle_help(char **args) {
    if (args[1] == NULL) {
        printf("Comandos internos disponibles:\n");
        printf("  exit [N] - Termina el shell con el estado N\n");
        printf("  pid - Muestra el ID del proceso del shell\n");
        printf("  uid - Muestra el ID de usuario y el nombre de usuario\n");
        printf("  gid - Muestra el grupo principal y los grupos secundarios del usuario\n");
        printf("  getenv variable [variable ...] - Muestra el valor de las variables de entorno\n");
        printf("  setenv variable valor - Define una variable de ambiente o cambia su valor\n");
        printf("  unsetenv variable [variable ...] - Elimina variables de ambiente\n");
        printf("  cd [dir] - Cambia el directorio corriente. Opciones:\n");
        printf("             cd xxx - Cambia al directorio xxx\n");
        printf("             cd -   - Cambia al directorio anterior\n");
        printf("             cd     - Cambia al directorio valor de la variable de ambiente HOME\n");
        printf("  status - Muestra el estado de retorno del último comando ejecutado\n");
        printf("  history [N] - Muestra los últimos N comandos (por defecto 10)\n");
        printf("  help - Muestra esta ayuda\n");
    } else {
        if (strcmp(args[1], "exit") == 0) {
            printf("exit [N]: Termina el shell con el estado N. Sin argumentos, usa el estado del último comando ejecutado.\n");
        } else if (strcmp(args[1], "pid") == 0) {
            printf("pid: Muestra el ID del proceso del shell.\n");
        } else if (strcmp(args[1], "uid") == 0) {
            printf("uid: Muestra el ID de usuario y el nombre de usuario.\n");
        } else if (strcmp(args[1], "gid") == 0) {
            printf("gid: Muestra el grupo principal y los grupos secundarios del usuario.\n");
        } else if (strcmp(args[1], "getenv") == 0) {
            printf("getenv variable [variable ...]: Muestra el valor de las variables de entorno especificadas.\n");
        } else if (strcmp(args[1], "setenv") == 0) {
            printf("setenv variable valor: Define una variable de ambiente o cambia su valor.\n");
        } else if (strcmp(args[1], "unsetenv") == 0) {
            printf("unsetenv variable [variable ...]: Elimina variables de ambiente.\n");
        } else if (strcmp(args[1], "history") == 0) {
            printf("history [N]: Muestra los últimos N comandos. Si N no se especifica, muestra los últimos 10 comandos.\n");
        } else {
            printf("help: Comando no reconocido. Usa 'help' para ver la lista de comandos disponibles.\n");
        }
    }
}
