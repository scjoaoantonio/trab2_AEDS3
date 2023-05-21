CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

OBJ = main.o
HDR = ./lib/dfs.h ./lib/dinamica.h

all: tp2

tp2: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o tp2

main.o: main.c $(HDR)
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f $(OBJ) tp2 saida.txt