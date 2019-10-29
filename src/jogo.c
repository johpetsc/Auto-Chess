/*Modulo responsavel por gerenciar a execucao do jogo. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../header/jogador.h"

static int poolDeCampeoes[20];
static int poolJogador[JOGADORES][5];
static int stage = 0;
pthread_mutex_t mutexPool;

void *chamaJogador(void *args){
    int id = *((int *)args);
    while(1){
        joga(id, poolJogador);
        sleep(1);
    }
}

void *chamaTabuleiro(void *args){
    int id = *((int *)args);
    while(1){
        tabuleiro(id);
    }
}

void *criaOfertas(void *args){
    int id = *((int *)args);
    while(1){
        pthread_mutex_lock(&mutexPool);
        for(int j=0; j<5; j++){
            if(stage == 0)
                poolJogador[id][j] = rand()%8;
            else if(stage == 1)
                poolJogador[id][j] = rand()%14;
            else if(stage == 2)
                poolJogador[id][j] = rand()%18;
            else
                poolJogador[id][j] = rand()%20;
            if(!poolDeCampeoes[poolJogador[id][j]])
                j--;
            else
                poolDeCampeoes[poolJogador[id][j]]--;
        }
        pthread_mutex_lock(&mutexPool);
    }
}

void setPool(){
    int tier1 = 39;
    int tier2 = 21;
    int tier3 = 13;
    int tier4 = 10;

    for(int i=0; i<20; i++){
        if(i<8)
            poolDeCampeoes[i] = tier1;
        else if(i<14)
            poolDeCampeoes[i] = tier2;
        else if(i<18)
            poolDeCampeoes[i] = tier3;
        else
            poolDeCampeoes[i] = tier4;
    }
}

int inicializaJogo(){
    pthread_t jogadores[JOGADORES];
    pthread_t tabuleiros[JOGADORES];
    pthread_t ofertas[JOGADORES];
    int *id;

    setHP(HP);
    setPool();
    pthread_mutex_init(&mutexPool, NULL);
    for (int i = 0; i < JOGADORES; i++) {
        id = (int*)malloc(sizeof(int));
        *id = i;
        pthread_create(&jogadores[i], NULL, chamaJogador, (void*)id);
        pthread_create(&tabuleiros[i], NULL, chamaTabuleiro, (void*)id);
        pthread_create(&ofertas[i], NULL, criaOfertas, (void*)id);
    }

    for (int i = 0; i < JOGADORES; i++) {
        pthread_join(jogadores[i], NULL);
        pthread_join(tabuleiros[i], NULL);
        pthread_join(ofertas[i], NULL);
    }

    return 0;
}