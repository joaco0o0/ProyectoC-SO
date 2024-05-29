#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "minish.h"
int externo(int argc, char **argv){
    pid_t pid; //Es un entero que identifica de manera única un proceso en el sistema operativo
    int status;

    pid = fork();
    if (pid < 0) {
        perror("fork error");
        return -1; // Indica error en el fork
    }
    if (pid == 0) {
        // En el proceso hijo
        if (execvp(argv[0], argv) == -1) {
            perror("execvp error");
            exit(EXIT_FAILURE);
        }
    } else {
        // En el proceso padre
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid error");
            return -1; // Indicar error en waitpid
        }
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status); // Retornar el estado de retorno del comando
        } else {
            return -1; // Indicar que el proceso no terminó normalmente
        }
    }
    return 0; // Valor de retorno en caso de éxito
}