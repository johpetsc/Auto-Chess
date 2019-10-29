/*Arquivo header do modulo de jogador. */

#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED

#define JOGADORES 8
#define LINHAS 3
#define COLUNAS 6
#define HP 100

void setHP(int hp);
void joga(int id, int pool[JOGADORES][5]);
void tabuleiro(int id);

#endif