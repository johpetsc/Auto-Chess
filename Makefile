#Makefile#

all: game clean

game: game.o main.o player.o rules.o seller.o
	gcc -o game main.o player.o game.o rules.o seller.o -lpthread

player.o: src/player.c
	gcc src/player.c -o player.o -c -lpthread

game.o: src/game.c
	gcc src/game.c -o game.o -c -lpthread

rules.o: src/rules.c
	gcc src/rules.c -o rules.o -c -lpthread

seller.o: src/seller.c
	gcc src/seller.c -o seller.o -c -lpthread

main.o: src/main.c header/game.h
	gcc src/main.c -o main.o -c

clean:
	rm -rf *.o
