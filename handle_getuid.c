#include "minish.h"

void handle_getuid() {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if (pw != NULL) {
        printf("UID: %d (%s)\n", uid, pw->pw_name);
    } else {
        perror("getpwuid");
    }
}