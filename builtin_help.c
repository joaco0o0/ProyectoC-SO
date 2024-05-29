#include "minish.h"

int builtin_help(int argc,char **argv) {
    if (argv[1] == NULL) {
        for (int i=1; builtin_arr[i].cmd != NULL; i++) {
            printf("%s", builtin_arr[i].help_txt);
        }

    } else {
    
        printf("%s",builtin_lookup(argv[1])->help_txt);
    }
    return 0;
}
