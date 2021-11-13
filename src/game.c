#include "../header/game.h"

void roundManager() {
    int check_end = 0;
    stage = 1;
    end = 1;
    while(end){
        printf("[Game] ROUND %d\n", stage);
        boardManager();
        printf("HP TABLE\n");
        for(int i=0; i<PLAYERS; i++){
            if(HPs[i]>0)
                printf("HP player %d: %d\n", i+1, HPs[i]);
            else
                printf("Player %d is dead.\n", i+1);
        }
        check_end = endGame();
        if(check_end){
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("Winner: %d\n", check_end);
            end = 0;
        }
        stage += 1;
        sleep(2);
    }
}

void boardManager() {
    int played = 0;
    while(played != alive_players){
        pthread_mutex_lock(&mutex_board);
        if (board < 2) {
            pthread_cond_wait(&cond_full, &mutex_board);
        } else {
            if(HPs[battle_ids[0]] < 0)
                printf("[Game] Player %d is battling in the arena against a ghost!\n", battle_ids[1]);
            else if(HPs[battle_ids[1]] < 0)
                printf("[Game] Player %d is battling in the arena against a ghost!\n", battle_ids[0]);
            else
                printf("[Game] Players %d and %d are battling in the arena!\n", battle_ids[0], battle_ids[1]);
            //sleep(1);
            int winner_id, loser_id;
            winner(battle_ids[0], battle_ids[1], &winner_id, &loser_id);
            int damage_amt = loserDamage(winner_id, loser_id);
            HPs[loser_id-1] -= damage_amt;
            printf("[Game] Player %d Won and Player %d lost %d health points\n", winner_id, loser_id, damage_amt);
            board = 0;
            played += 2;
            magic = 0;
        }
        pthread_mutex_unlock(&mutex_board);
    }
}

void *generalManager() {

    int *id;
    pthread_t players[PLAYERS];
    pthread_t winners[PLAYERS];

    setHealth();
    createPool();

    for(int i=0; i<PLAYERS; i++){
        pthread_mutex_init(&mutex_round[i], NULL);
    }
    for(int i=0; i<PLAYERS; i++){
        pthread_cond_init(&buy_condition[i], NULL);
    }
    pthread_mutex_init(&mutex_pool, NULL);
    pthread_mutex_init(&mutex_board, NULL);
    pthread_cond_init(&cond_full, 0);
    pthread_cond_init(&cond_empty, 0);
    

    for (int i = 0; i < PLAYERS; i++) {
        id = (int*)malloc(sizeof(int));
        *id = i;
        pthread_create(&PLAYERS[i], NULL, player, (void*)id);
        pthread_create(&winners[i], NULL, winner, (void*)id);
    }

    roundManager();

    for (int i = 0; i < PLAYERS; i++) {
        pthread_join(players[i], NULL);
        pthread_join(winners[i], NULL);
    }

    pthread_exit(NULL);
}

int initGame(){
    pthread_t game;
    pthread_create(&game, NULL, generalManager, NULL);

    pthread_join(game, NULL);
}
