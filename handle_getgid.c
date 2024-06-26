#include "minish.h"

void handle_getgid() {
    gid_t gid = getgid();
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
            perror("malloc");
        }
    }
    printf("\n");
}