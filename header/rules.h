#ifndef RULES_H_INCLUDED
#define RULES_H_INCLUDED

#include "globals.h"

void createPool();
void setHealth();
void initialPower();
int endGame();
void winner(int id1, int id2, int *winner_id, int *loser_id);
int loserDamage(int id1, int id2);

#endif
