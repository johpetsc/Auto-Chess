#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define PLAYERS 8
#define ROWS 3
#define COLUMNS 6
#define HP 100

int champions_pool[20];
int HPs[PLAYERS];
int combat_power[PLAYERS];
static int alive_players = PLAYERS;
static int player_pool[PLAYERS][5];

pthread_mutex_t mutex_pool;
pthread_mutex_t mutex_board;
pthread_cond_t cond_full;
pthread_cond_t cond_empty;
pthread_cond_t buy_condition[PLAYERS];
pthread_mutex_t mutex_round[PLAYERS];

int board;
int battle_ids[2];
int stage;
int end;
int magic; //amen



#endif
