#include "minish.h"

void read_command(char *line) {
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }
}