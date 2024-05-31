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




int main() {
    char line[MAX_INPUT];
    int argc=MAX_ARGV;
    char *argv[MAX_ARGV]={NULL};
    int status;
    int numero_args;

    // Cargar el historial desde el archivo
   
    load_history();
   
    // Ciclo principal del shell
    do {//cambiar el loop, hacer un for{}
        show_prompt(); // Mostrar el prompt
        
        if (fgets(line, sizeof(line), stdin) == NULL) { //parece que tiene que ser *line pero antes era sin
            perror("fgets");
            exit(EXIT_FAILURE); //diferenciar entre control D y control
        }
        
        add_to_history(line); // Agregar el comando al historial
        numero_args=linea2argv(line,argc,argv); // Convierte la línea de entrada en una lista de argumentos
        
        status = ejecutar(argc,argv); // Ejecuta el comando ingresado por el usuario
    
        //Esta repetido creo
    } while (status == 0); // Continuar hasta que el comando de salida se ejecute correctamente
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

