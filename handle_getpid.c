#include "minish.h"

void handle_getpid() {
    printf("PID del shell: %d\n", getpid());
}