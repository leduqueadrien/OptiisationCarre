#options
CFLAGS = -Wall -Wextra -g -MMD
LIB  = -lm

SRC = $(wildcard src/*.c) $(wildcard src/Matrice/*.c) $(wildcard src/Optimisation/*.c) $(wildcard src/Network/*.c) $(wildcard src/Aleatoire/*.c)
OBJ = $(patsubst src/%.c,build/%.o,$(SRC))
DEP = $(patsubst %.o,%.d,$(OBJ))

.PHONY: all
all: bin/executable
	@echo "Executer avec ./bin/executable"

#édition des liens
bin/executable: $(OBJ)
	@mkdir -p $(@D) #créer le dossier bin, s'il n'existe pas
	cc -o $@ $^ $(LIB)

#génère les fichiers .o (dans build) à partir des fichiers .c (dans src) du même nom
#comppilation
build/%.o: src/%.c
	@mkdir -p $(@D) #créer le dossier build, s'il n'existe pas
	cc -c $< $(CFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf build

library:
	gcc -c -fPIC testLibrairie/afficher.c -o testLibrairie/afficher.o
	gcc -shared -fPIC testLibrairie/afficher.o -o testLibrairie/lib.dll

-include $(DEP)