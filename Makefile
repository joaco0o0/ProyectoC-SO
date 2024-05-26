# Definición de los archivos fuente y de encabezado
CFILES   = $(wildcard *.c)
HFILES   = $(wildcard *.h)
OBJFILES = $(CFILES:.c=.o)
DEPS     = $(CFILES:.c=.d)
OUT      = minish
CFLAGS   = -Wall -Wextra -std=gnu99 -ggdb

# Regla para generar el ejecutable
$(OUT): $(OBJFILES)
	$(CC) $(CFLAGS) -o $@ $^

# Incluir archivos de dependencias
-include $(DEPS)

# Regla para compilar .c a .o y generar archivos .d
%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Regla para limpiar
.PHONY: clean
clean:
	rm -f $(OBJFILES) $(OUT) $(DEPS)