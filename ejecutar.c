// ejecutar.c
#include <stdio.h>
#include "builtin.h"

int ejecutar(int argc, char **argv) {
    struct builtin_struct *builtin = builtin_lookup(argv[0]);
    if (builtin != NULL) {
        return builtin->func(argc, argv);
    } else {
        return externo(argc, argv);
    }
}