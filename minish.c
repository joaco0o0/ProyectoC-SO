#include "minish.h"




//Para el enviroment
extern char **environ;
int status = 0;
// Declaraciones para el historial
char *history[MAX_HISTORY];
int history_count=0;
void load_history();
void save_history();
void add_to_history(char *cmd);



void
sigint_handler(int signum) {                    // the handler for SIGINT
    fprintf(stderr, "Interrupt! (signal number %d)\n", signum);
}
int main() {
    char line[MAX_INPUT];
    int argc=MAX_ARGV;
    char *argv[MAX_ARGV]={NULL};
    int status;
    struct sigaction oldact, newact;

    sigaction(SIGINT, NULL, &newact);           // the  previous action for SIGINT is saved in oldact
    newact.sa_handler = sigint_handler;
    sigaction(SIGINT, &newact, NULL);           // set SIGINT handler for loop

    // Cargar el historial desde el archivo
   
    load_history();
   
    // Ciclo principal del shell
    for (;;) {//cambiar el loop, hacer un for{}
        show_prompt(); // Mostrar el prompt
        
        if (fgets(line, sizeof(line), stdin) == NULL) { 
            error(EXIT_FAILURE,errno,"error en la lectura");
            save_history(); // Guardar el historial en el archivo antes de salir
             //diferenciar entre control D y control
        }
        sigaction(SIGINT, NULL, &oldact);   // the  previous action for SIGINT is saved in oldact
        newact = oldact; //esto es el inicio de los de sigint
        add_to_history(line); // Agregar el comando al historial
        linea2argv(line,argc,argv); // Convierte la línea de entrada en una lista de argumentos
        status = ejecutar(argc,argv); // Ejecuta el comando ingresado por el usuario
        // Liberar la memoria asignada a los argumentos
        for (int i = 0; i < argc && argv[i] != NULL; i++) {
            free(argv[i]);
            argv[i] = NULL; // Previene el uso de punteros colgantes.
        }//Hay que HACER ALGO CON STATUS
    }

   
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

