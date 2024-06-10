#include "minish.h" // Incluye el archivo de cabecera "minish.h"

int builtin_help(int argc, char **argv) {
    (void)argc; // Indicamos que 'argc' no se usa para evitar advertencias del compilador
    
    if (argv[1] == NULL) { // Si no se proporcionan argumentos adicionales
        for (int i = 1; builtin_arr[i].cmd != NULL; i++) { // Itera sobre los comandos internos (built-ins)
            printf("%s", builtin_arr[i].help_txt); // Imprime el texto de ayuda de cada comando
        }

    } else { // Si se proporciona un argumento adicional (un comando específico)
    
        printf("%s", builtin_lookup(argv[1])->help_txt); // Busca y imprime el texto de ayuda del comando especificado
    }
    
    return 0; // Retorna 0 indicando éxito
}
