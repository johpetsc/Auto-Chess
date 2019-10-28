/*Modulo responsavel por executar as ações de cada jogador. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void joga(int id){
    printf("To jogando. %d\n", id);
}
