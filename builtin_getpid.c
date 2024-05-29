#include "minish.h"

int builtin_getpid(int argc,char **argv) {
    printf("PID del shell: %d\n", getpid());
    return 0;
}
