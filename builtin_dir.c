#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <error.h>

// Función para simular el comando 'ls -l'
int builtin_dir(int argc,char **args) {
    (void) argc;
    struct dirent *entry;  // Estructura para entrada de directorio
    struct stat statbuf;   // Estructura para información de estado del archivo
    DIR *dp;               // Puntero a la estructura del directorio
    char *dir;             // Dirección del directorio a listar
    

    // Verificar si se pasó un argumento para listar un directorio específico o un patrón
    if (args[1]) {
        dir = args[1];
    } else {
        dir = ".";  // Directorio actual por defecto
    }

    // Abrir el directorio
    dp = opendir(dir);
    if (dp == NULL) {
        error(0, errno, "No se pudo abrir el repositorio %s", dir);  // Manejo de error al abrir el directorio
        
    }

    // Leer entradas en el directorio
    while ((entry = readdir(dp)) != NULL) {
        char path[1024];
        sprintf(path, "%s/%s", dir, entry->d_name);  // Construir ruta completa al archivo

        // Obtener información de estado del archivo
        if (stat(path, &statbuf) == -1) {
            error(0, errno, "No se pudo obtener la información del estado del archivo %s", path);  // Manejo de error al obtener información del archivo
            continue;
        }

        // Imprimir tipo de archivo y permisos
        printf("%10.10s", S_ISDIR(statbuf.st_mode) ? "d" : "-");
        printf("%c%c%c%c%c%c%c%c%c ",
               (statbuf.st_mode & S_IRUSR) ? 'r' : '-',
               (statbuf.st_mode & S_IWUSR) ? 'w' : '-',
               (statbuf.st_mode & S_IXUSR) ? 'x' : '-',
               (statbuf.st_mode & S_IRGRP) ? 'r' : '-',
               (statbuf.st_mode & S_IWGRP) ? 'w' : '-',
               (statbuf.st_mode & S_IXGRP) ? 'x' : '-',
               (statbuf.st_mode & S_IROTH) ? 'r' : '-',
               (statbuf.st_mode & S_IWOTH) ? 'w' : '-',
               (statbuf.st_mode & S_IXOTH) ? 'x' : '-');
        
        // Imprimir cantidad de links
        printf(" %ld", statbuf.st_nlink);
        
        // Obtener y imprimir nombre de usuario y grupo del propietario
        struct passwd *pwd = getpwuid(statbuf.st_uid);
        struct group  *grp = getgrgid(statbuf.st_gid);
        printf(" %s %s", pwd->pw_name, grp->gr_name);
        
        // Imprimir tamaño del archivo
        printf(" %5ld", statbuf.st_size);
        
        // Imprimir fecha de última modificación
        char timebuf[80];
        strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", localtime(&statbuf.st_mtime));
        printf(" %s", timebuf);
        
        // Imprimir nombre del archivo
        printf(" %s\n", entry->d_name);
    }

    closedir(dp);  // Cerrar el directorio
    return 0;
}