#include "minish.h"

int builtin_getuid(int argc,char **argv) {
    (void)argc;
    (void)argv;
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if (pw != NULL) {
        printf("UID: %d (%s)\n", uid, pw->pw_name);
    } else {
        perror("getpwuid");
    }
    return 0;
}