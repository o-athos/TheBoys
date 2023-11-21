# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -lm 

# Nome do executável
TARGET = the_boys

# Lista de arquivos fonte
SOURCES = main.c the_boys.c lef.c fila.c conjunto.c

# Lista de objetos gerados durante a compilação
OBJECTS = $(SOURCES:.c=.o)

# Nome do arquivo compactado
PACKAGE_NAME = the_boy_athos

# Regra padrão: compilar todos os objetos e criar o executável
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Regra para compilar cada arquivo fonte em um objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para criar um pacote
entrega: $(TARGET)
	tar -czvf $(PACKAGE_NAME).tar.gz $(SOURCES) Makefile $(TARGET)

# Regra para limpar os arquivos gerados durante a compilação e o pacote
clean:
	rm -f $(TARGET) $(OBJECTS) $(PACKAGE_NAME).tar.gz

