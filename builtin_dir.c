#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <error.h>

#define MAX_FILES 1000

// Estructura para almacenar información sobre cada archivo
struct FileInfo {
    char *name;
    struct stat statbuf;
};

// Función para comparar dos estructuras FileInfo y ordenarlas alfabéticamente por nombre de archivo
int compare_fileinfo(const void *a, const void *b) {
    return strcmp(((struct FileInfo *)a)->name, ((struct FileInfo *)b)->name);
}

// Función principal para simular el comando 'dir'
int builtin_dir(int argc, char **argv) {
    (void)argc;
    (void)argv;

    char *dir = "."; // Directorio actual por defecto

    // Abrir el directorio
    DIR *dp = opendir(dir);
    if (dp == NULL) {
        error(0, errno, "No se pudo abrir el directorio %s", dir);
        return 1;
    }

    // Almacenar información de archivo en un array de estructuras FileInfo
    struct FileInfo files[MAX_FILES];
    int file_count = 0;
    struct dirent *entry;
    while ((entry = readdir(dp)) != NULL && file_count < MAX_FILES) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);

        // Obtener información de estado del archivo y almacenarla en la estructura FileInfo
        if (stat(path, &files[file_count].statbuf) == -1) {
            error(0, errno, "No se pudo obtener la información del archivo %s", path);
            continue;
        }

        // Almacenar el nombre del archivo en la estructura FileInfo
        files[file_count].name = strdup(entry->d_name);
        file_count++;
    }
    closedir(dp);

    // Ordenar el array de archivos alfabéticamente utilizando qsort y la función de comparación compare_fileinfo
    qsort(files, file_count, sizeof(struct FileInfo), compare_fileinfo);

    // Imprimir detalles de archivo ordenados
    for (int i = 0; i < file_count; i++) {
        struct FileInfo *fileinfo = &files[i];
        struct stat *statbuf = &fileinfo->statbuf;

        // Imprimir los detalles de cada archivo formateados
        printf("%10.10s", S_ISDIR(statbuf->st_mode) ? "d" : "-"); // Tipo de archivo
        printf("%c%c%c%c%c%c%c%c%c ", (statbuf->st_mode & S_IRUSR) ? 'r' : '-', // Permisos de usuario
               (statbuf->st_mode & S_IWUSR) ? 'w' : '-',
               (statbuf->st_mode & S_IXUSR) ? 'x' : '-',
               (statbuf->st_mode & S_IRGRP) ? 'r' : '-', // Permisos de grupo
               (statbuf->st_mode & S_IWGRP) ? 'w' : '-',
               (statbuf->st_mode & S_IXGRP) ? 'x' : '-',
               (statbuf->st_mode & S_IROTH) ? 'r' : '-', // Permisos de otros
               (statbuf->st_mode & S_IWOTH) ? 'w' : '-',
               (statbuf->st_mode & S_IXOTH) ? 'x' : '-');
        printf(" %ld", statbuf->st_nlink); // Número de enlaces

        struct passwd *pwd = getpwuid(statbuf->st_uid); // Obtener información del usuario propietario
        struct group *grp = getgrgid(statbuf->st_gid);  // Obtener información del grupo propietario
        printf(" %s %s", pwd->pw_name, grp->gr_name);   // Nombre de usuario y grupo
        printf(" %5ld", statbuf->st_size);              // Tamaño del archivo

        char timebuf[80];
        strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", localtime(&statbuf->st_mtime)); // Formatear la fecha de modificación
        printf(" %s", timebuf); // Fecha de modificación

        printf(" %s\n", fileinfo->name); // Nombre del archivo

        free(fileinfo->name); // Liberar la memoria asignada al nombre del archivo
    }

    return 0;
}
