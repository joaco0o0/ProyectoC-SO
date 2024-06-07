#include "minish.h"

int builtin_getgid(int argc, char **argv) {
    (void)argc;
    (void)argv;
    gid_t gid = getgid();
    //la funcion getgid nunca resulta en error
    printf("GID principal: %d\n", gid);
    printf("GIDs secundarios: ");
    
    int ngroups = getgroups(0, NULL);
    if (ngroups > 0) {
        gid_t *groups = malloc(ngroups * sizeof(gid_t));
        if (groups != NULL) {
            ngroups = getgroups(ngroups, groups);
            for (int i = 0; i < ngroups; i++) {
                printf("%d ", groups[i]);
            }
            free(groups);
        } else {
            error(EXIT_FAILURE,errno,"error en malloc");;
        }
    }
    printf("\n");
    return 0;
}