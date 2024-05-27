#include "minish.h"

extern char **environ;
int status = 0;
// Declaraciones para el historial
char *history[MAX_HISTORY];
int history_count=0;

void load_history();
void save_history();
void add_to_history(const char *cmd);

int main() {
    char line[MAX_INPUT];
    char *args[MAX_ARGS];
    // Cargar el historial desde el archivo
    load_history();

    // Ciclo principal del shell
    do {
        show_prompt(); // Mostrar el prompt
        printf("minish> "); // Prompt del shell
        if (fgets(line, sizeof(line), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
        add_to_history(line); // Agregar el comando al historial
        read_command(line); // Ajusta la línea de entrada eliminando el carácter de nueva línea
        linea2argv(line, args); // Convierte la línea de entrada en una lista de argumentos
        status = execute_command(args); // Ejecuta el comando ingresado por el usuario
    } while (status == 0);
    // Guardar el historial en el archivo antes de salir
    save_history();
    return status;
}
void show_prompt() {
    char cwd[1024];
    struct passwd *pw;
    uid_t uid;
    
    // Obtener el directorio actual
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }
    
    // Obtener el nombre del usuario
    uid = geteuid();
    pw = getpwuid(uid);
    if (pw == NULL) {
        perror("getpwuid");
        exit(EXIT_FAILURE);
    }

    // Mostrar el prompt
    printf("(minish) %s:%s > ", pw->pw_name, cwd);
}
