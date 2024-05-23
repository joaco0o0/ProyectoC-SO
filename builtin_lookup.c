// builtin_lookup.c
#include <string.h>
#include "builtin.h"

struct builtin_struct builtin_arr[] = {
    {"exit", builtin_exit, "Exit the shell"},
    {"pid", builtin_pid, "Print process ID"},
    {"uid", builtin_uid, "Print user ID"},
    {NULL, NULL, NULL}
};

struct builtin_struct *builtin_lookup(char *cmd) {
    for (int i = 0; builtin_arr[i].cmd != NULL; i++) {
        if (strcmp(builtin_arr[i].cmd, cmd) == 0) {
            return &builtin_arr[i];
        }
    }
    return NULL;
}