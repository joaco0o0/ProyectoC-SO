#include "minish.h"
extern char **environ; // Declaración de la variable global 'environ' que contiene las variables de entorno

int builtin_getenv(int argc, char **argv) {
    (void)argc; // Indicamos que 'argc' no se usa para evitar advertencias del compilador

    // Si no se especifican argumentos, se muestran todas las variables de entorno
    if (argv[1] == NULL) {
        char **env = environ; // Puntero a la lista de variables de entorno
        while (*env != NULL) { // Itera a través de todas las variables de entorno
            printf("%s\n", *env); // Imprime cada variable de entorno
            env++; // Avanza al siguiente elemento en la lista
        } 
        
        return 0; 
    }

    // Si se especifican argumentos, se buscan y muestran los valores de las variables de entorno dadas
    for (int i = 1; argv[i] != NULL; i++) { // Itera sobre cada argumento proporcionado (excepto el nombre del comando)
        char *value = getenv(argv[i]); // Obtiene el valor de la variable de entorno
        if (value != NULL) { // Si la variable de entorno está definida
            printf("%s=%s\n", argv[i], value); // Imprime el nombre de la variable y su valor
        } else { // Si la variable de entorno no está definida
            printf("%s no está definido\n", argv[i]); // Imprime un mensaje indicando que la variable no está definida
        }
    }
    return 0; // Retorna 0 indicando éxito
}