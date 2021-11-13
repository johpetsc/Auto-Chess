#include "../header/player.h"

// player thread
void *player(void *args){
    int power = 0;
    int id = *((int *)args);
    printf("[Player %d] Initialized with 100 health points\n", id+1);
    sleep(1);
    int d = -1;
    int k = 0;
    while(end){
        if(d!=stage){
            d = stage;
            do{
                k = play(id);
            }while(k);
            buy(id);
        }else{
            sleep(1);
        }

    }
    pthread_exit(NULL);
}

void buy(int id){
    int a, b;
    a = rand()%5;
    b = rand()%5;
    pthread_mutex_lock(&mutex_round[id]);

    if(player_pool[id][a]<8)
        combat_power[id] +=1;
    else if(player_pool[id][a]<14)
        combat_power[id] +=2;
    else if(player_pool[id][a]<18)
        combat_power[id] +=3;
    else
        combat_power[id] +=4;
    
    if(player_pool[id][b]<8)
        combat_power[id] +=1;
    else if(player_pool[id][b]<14)
        combat_power[id] +=2;
    else if(player_pool[id][b]<18)
        combat_power[id] +=3;
    else
        combat_power[id] +=5;
    pthread_mutex_unlock(&mutex_round[id]);
    pthread_cond_signal(&buy_condition[id]);

}

int play(int id){
    while(end){
        pthread_mutex_lock(&mutex_board);
        if(magic){
            pthread_mutex_unlock(&mutex_board);
            return 1;
        }
        board +=1;

        if (board == 1) {
            battle_ids[0] = id+1;
            pthread_mutex_unlock(&mutex_board);
            return 0;
        }

        if (board == 2) {
            battle_ids[1] = id+1;
            pthread_cond_signal(&cond_full);
            magic = 1;
            pthread_mutex_unlock(&mutex_board);
            return 0;
        }else{
            pthread_mutex_unlock(&mutex_board);
            return 0;
        }
    }

    return 0;

}
