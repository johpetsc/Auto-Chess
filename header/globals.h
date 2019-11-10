#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define JOGADORES 8
#define LINHAS 3
#define COLUNAS 6
#define HP 100

int poolDeCampeoes[20];
int HPs[JOGADORES];
int poderDeCombate[JOGADORES];
static int jogadores_vivos = JOGADORES;
static int poolJogador[JOGADORES][5];

pthread_mutex_t mutexPool;
pthread_mutex_t mutex_tabuleiro;
pthread_cond_t cond_full;
pthread_cond_t cond_empty;
pthread_cond_t cond_compra[JOGADORES];
pthread_mutex_t mutex_round[JOGADORES];

int tabuleiro;
int battle_ids[2];
int stage;
int fim;
int pqp;//amem



#endif
