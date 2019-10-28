#Makefile#

all: jogo clean

jogo: jogo.o main.o jogador.o
	gcc -o jogo main.o jogador.o jogo.o -lpthread

jogador.o: src/jogador.c
	gcc src/jogador.c -o jogador.o -c -lpthread

jogo.o: src/jogo.c
	gcc src/jogo.c -o jogo.o -c -lpthread

main.o: src/main.c header/jogo.h
	gcc src/main.c -o main.o -c

clean:
	rm -rf *.o