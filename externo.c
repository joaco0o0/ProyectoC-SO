#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "minish.h"
int externo(int argc, char **argv){
    (void)argc;
    pid_t pid; //Es un entero que identifica de manera única un proceso en el sistema operativo
    int status;

    pid = fork();
    if (pid < 0) {
        error(EXIT_FAILURE,errno,"error en fork");
        return -1; // Indica error en el fork
    }
    if (pid == 0) {
        // En el proceso hijo
        if (execvp(argv[0], argv) == -1) {
            error(EXIT_FAILURE,errno,"error en execvp");
            exit(EXIT_FAILURE);
        }
        
    } else {
        
        // En el proceso padre
        if (waitpid(pid, &status, 0) == -1) {
            error(EXIT_FAILURE,errno,"error en wait");
            return -1; // Indicar error en waitpid
        }
        if (WIFEXITED(status)) {
            int exitStatus = WEXITSTATUS(status);
            if (exitStatus == 0) {
                add_to_history(argv[0]); // Agregar el comando al historial                
                return exitStatus; // Indicar que el proceso terminó normalmente
            }
            
        } else {
            return -1; // Indicar que el proceso no terminó normalmente
        }
    }
   return 0;
}