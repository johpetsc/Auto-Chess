#include "../header/seller.h"

void *seller(void *args){
    int id = *((int *)args);
    printf("[Seller %d] Hello player %d, I'm your seller! \n", id+1, id+1);
    while(end){
        pthread_mutex_lock(&mutex_round[id]);
        pthread_mutex_lock(&mutex_pool);
        for(int j=0; j<5; j++){
            if(stage == 0)
                player_pool[id][j] = rand()%8;
            else if(stage == 1)
                player_pool[id][j] = rand()%14;
            else if(stage == 2)
                player_pool[id][j] = rand()%18;
            else
                player_pool[id][j] = rand()%20;
            if(!champions_pool[player_pool[id][j]])
                j--;
            else
                champions_pool[player_pool[id][j]]--;
        }
        pthread_mutex_unlock(&mutex_pool);
        pthread_cond_wait(&buy_condition[id], &mutex_round[id]);
        pthread_mutex_unlock(&mutex_round[id]);
    }
    pthread_exit(NULL);
}
