#Makefile#

all: jogo clean

jogo: jogo.o main.o jogador.o regras.o vendedor.o
	gcc -o jogo main.o jogador.o jogo.o regras.o vendedor.o -lpthread

jogador.o: src/jogador.c
	gcc src/jogador.c -o jogador.o -c -lpthread

jogo.o: src/jogo.c
	gcc src/jogo.c -o jogo.o -c -lpthread

regras.o: src/regras.c
	gcc src/regras.c -o regras.o -c -lpthread

vendedor.o: src/vendedor.c
	gcc src/vendedor.c -o vendedor.o -c -lpthread

main.o: src/main.c header/jogo.h
	gcc src/main.c -o main.o -c

clean:
	rm -rf *.o
