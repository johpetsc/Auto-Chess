
#include "../header/regras.h"


void cria_pool(){
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


void conf_hp(int hp){
    for(int i=0; i<JOGADORES; i++){
        HPs[i] = hp;
    }
}


int ganhador(int id1, int id2, int *id_ganhador, int *id_perdedor) {
    int r_num = rand() % 2;
    int win = 0;

    if(r_num == 0) {
        *id_ganhador = id1;
        *id_perdedor = id2;
    } else {
        *id_ganhador = id2;
        *id_perdedor = id1;
    }

    return win;
}

int dano_perdedor(int id1, int id2) {
    return (rand() % 16) + 5;
}
