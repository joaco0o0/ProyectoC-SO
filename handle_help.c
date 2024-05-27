#include "minish.h"

void handle_help() {
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
}