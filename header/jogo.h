/*Arquivo header do modulo de jogo. */

#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include "regras.h"
#include "jogador.h"
#include "vendedor.h"
#include "globals.h"

void gerenciador_round();
void gerenciador_tabuleiro();
void *gerenciador_geral();
int inicializa_jogo();

#endif
