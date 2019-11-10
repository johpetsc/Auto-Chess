/*Arquivo header do modulo de jogo. */

#ifndef REGRAS_H_INCLUDED
#define REGRAS_H_INCLUDED

#include "globals.h"

void cria_pool();
void conf_hp();
void poder_inicial();
int fim_jogo();
int ganhador(int id1, int id2, int *id_ganhador, int *id_perdedor);
int dano_perdedor(int id1, int id2);

#endif
