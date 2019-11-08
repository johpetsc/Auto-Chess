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

static int poolDeCampeoes[20];
static int HPs[JOGADORES];
static int jogadores_vivos = JOGADORES;
static int poolJogador[JOGADORES][5];
static int stage = 0;

pthread_mutex_t mutexPool;
pthread_mutex_t mutex_tabuleiro;
pthread_cond_t cond_full;
pthread_cond_t cond_empty;

int tabuleiro;
int battle_ids[2];



#endif
