
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

int fim_jogo(){
    int vivos = 0;
    int vencedor = 0;
    for(int i=0; i<JOGADORES; i++){
        if(HPs[i]>0){
            vivos++;
            vencedor = i+1;
        }
    }
    if(vivos == 1){
        return vencedor;
    }else{
        return 0;
    }
}
void conf_hp(){
    for(int i=0; i<JOGADORES; i++){
        HPs[i] = HP;
    }
}

void poder_inicial(){
    for(int i=0; i<JOGADORES; i++){
        poderDeCombate[i] = 10;
    }
}

int ganhador(int id1, int id2, int *id_ganhador, int *id_perdedor) {
    int win = 0;

    if(poderDeCombate[id1-1]>poderDeCombate[id2-1]) {
        *id_ganhador = id1;
        *id_perdedor = id2;
    } else {
        *id_ganhador = id2;
        *id_perdedor = id1;
    }

    return win;
}

int dano_perdedor(int id1, int id2) {
    int k = 0;
    k = rand()%poderDeCombate[id2-1];
    return (poderDeCombate[id1-1]-k);
}
