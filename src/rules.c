#include "../header/rules.h"

void createPool(){
    int tier1 = 39;
    int tier2 = 21;
    int tier3 = 13;
    int tier4 = 10;

    for(int i=0; i<20; i++){
        if(i<8)
            champions_pool[i] = tier1;
        else if(i<14)
            champions_pool[i] = tier2;
        else if(i<18)
            champions_pool[i] = tier3;
        else
            champions_pool[i] = tier4;
    }
}

int endGame(){
    int alive = 0;
    int winner = 0;
    for(int i=0; i<PLAYERS; i++){
        if(HPs[i]>0){
            alive++;
            winner = i+1;
        }
    }
    if(alive == 1){
        return winner;
    }else{
        return 0;
    }
}
void setHealth(){
    for(int i=0; i<PLAYERS; i++){
        HPs[i] = HP;
    }
}

void initialPower(){
    for(int i=0; i<PLAYERS; i++){
        combat_power[i] = 10;
    }
}

void winner(int id1, int id2, int *winner_id, int *loser_id) {
    if(combat_power[id1-1]>combat_power[id2-1]) {
        *winner_id = id1;
        *loser_id = id2;
    } else {
        *winner_id = id2;
        *loser_id = id1;
    }
}

int loserDamage(int id1, int id2) {
    int k = 0;
    k = rand()%combat_power[id2-1];
    return (combat_power[id1-1]-k);
}
