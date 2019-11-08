#include "../header/vendedor.h"

void *vendedor(void *args){
    int id = *((int *)args);
    printf("[Vendedor %d] Boas Jogador %d, serei seu vendedor! \n", id+1, id+1);
    sleep(1);
    while(1){
        pthread_mutex_lock(&mutexPool);
        for(int j=0; j<5; j++){
            if(stage == 0)
                poolJogador[id][j] = rand()%8;
            else if(stage == 1)
                poolJogador[id][j] = rand()%14;
            else if(stage == 2)
                poolJogador[id][j] = rand()%18;
            else
                poolJogador[id][j] = rand()%20;
            if(!poolDeCampeoes[poolJogador[id][j]])
                j--;
            else
                poolDeCampeoes[poolJogador[id][j]]--;
        }
        pthread_mutex_lock(&mutexPool);
    }
}
