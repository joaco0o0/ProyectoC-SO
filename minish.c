#include "minish.h"
#include <ctype.h>




//Para el enviroment
extern char **environ;
int status = 0;
// Declaraciones para el historial
char *history[MAX_HISTORY];
int history_count=0;
void load_history();
void save_history();
void add_to_history(char *cmd);
void sigint_handler(int sig);
int is_blank(const char *str);




int main() {
    char line[MAX_INPUT];
    int argc=MAX_ARGV;
    char *argv[MAX_ARGV]={NULL};
    
    
    signal(SIGINT, sigint_handler);    

   
    load_history();  // Cargar el historial desde el archivo
   
    // Ciclo principal del shell
    for (;;) {//cambiar el loop, hacer un for{}
        show_prompt(); // Mostrar el prompt
        
        if (fgets(line, sizeof(line), stdin) == NULL) { 
            error(EXIT_FAILURE,errno,"se pulso control D");
            save_history(); // Guardar el historial en el archivo antes de salir
            
        }
        

        // Dentro del bucle principal
        if (is_blank(line)) {
            continue; // Saltar al siguiente ciclo si la línea contiene solo espacios
        }





        
        
        linea2argv(line,argc,argv); // Convierte la línea de entrada en una lista de argumentos
        
        status = ejecutar(argc,argv); // Ejecuta el comando ingresado por el usuario
        
        // Liberar la memoria asignada a los argumentos
        for (int i = 0; i < argc && argv[i] != NULL; i++) {
            free(argv[i]);
            argv[i] = NULL; // Previene el uso de punteros colgantes.
        }
    }

   
}
    
void sigint_handler(int sig){
    (void) sig;
    printf("\n");
    show_prompt();
    fflush(stdout);
    status=0;
    }

void show_prompt() {
    char cwd[1024];
    struct passwd *pw;
    uid_t uid;
    
    // Obtener el directorio actual
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd"); //cambiar los perror por error
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
int is_blank(const char *str) {
    while (*str != '\0') {
        if (!isspace(*str)) {
            return 0; // No está vacío
        }
        str++;
    }
    return 1; // Está vacío (solo contiene espacios)
}


