/*Modulo responsavel por gerenciar a execucao do jogo. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../header/jogador.h"

void *chamaJogador(void *args){
    int id = *((int *)args);
    joga(id);
}

void *chamaTabuleiro(void *args){
    int id = *((int *)args);
    tabuleiro(id);
}

int inicializaJogo(int n, int hp){
    pthread_t jogadores[n];
    pthread_t tabuleiros[n];
    int *id;

    setHP(hp);
    for (int i = 0; i < n; i++) {
        id = (int*)malloc(sizeof(int));
        *id = i;
        pthread_create(&jogadores[i], NULL, chamaJogador, (void*)id);
    }
    
    for (int i = 0; i < n; i++) {
        id = (int*)malloc(sizeof(int));
        *id = i;
        pthread_create(&tabuleiros[i], NULL, chamaTabuleiro, (void*)id);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(jogadores[i], NULL);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(tabuleiros[i], NULL);
    }

    return 0;
}