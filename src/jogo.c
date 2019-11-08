/*Modulo responsavel por gerenciar a execucao do jogo. */

#include "../header/jogo.h"

void gerenciador_round() {
    int round = 1;
    while(jogadores_vivos != 1){

        printf("[Jogo] ROUND %d\n", round);
        gerenciador_tabuleiro();
        round += 1;
    }
}

void gerenciador_tabuleiro() {
    int jogados = 0;
    while(jogados != jogadores_vivos){
        pthread_mutex_lock(&mutex_tabuleiro);
        if (tabuleiro < 2) {
            pthread_cond_wait(&cond_full, &mutex_tabuleiro);
        } else {
            printf("[Jogo] Jogadores %d e %d estao batalhando na arena\n", battle_ids[0], battle_ids[1]);
            sleep(2);
            int id_ganhador, id_perdedor;
            ganhador(battle_ids[0], battle_ids[1], &id_ganhador, &id_perdedor);
            int dano_amt = dano_perdedor(battle_ids[0], battle_ids[1]);
            printf("[Jogo] Jogador %d Ganhou e Jogador %d perdeu %d de vida\n", id_ganhador, id_perdedor, dano_amt);
            sleep(2);
            tabuleiro = 0;
            jogados += 2;
            pthread_cond_signal(&cond_empty);
        }
        pthread_mutex_unlock(&mutex_tabuleiro);
    }
}

void *gerenciador_geral() {

    int *id;
    pthread_t jogadores[JOGADORES];
    pthread_t vendedores[JOGADORES];

    conf_hp(HP);
    cria_pool();

    pthread_mutex_init(&mutexPool, NULL);
    pthread_cond_init(&cond_full, 0);
    pthread_cond_init(&cond_empty, 0);

    for (int i = 0; i < JOGADORES; i++) {
        id = (int*)malloc(sizeof(int));
        *id = i;
        pthread_create(&jogadores[i], NULL, jogador, (void*)id);
        pthread_create(&vendedores[i], NULL, vendedor, (void*)id);
    }

    gerenciador_round();

    for (int i = 0; i < JOGADORES; i++) {
        pthread_join(jogadores[i], NULL);
        pthread_join(vendedores[i], NULL);
    }

    pthread_exit(NULL);
}

// Inicializa um jogo em uma thread
int inicializa_jogo(){
    // Cria a Thread que cuidara do jogo
    pthread_t jogo;
    pthread_create(&jogo, NULL, gerenciador_geral, NULL);

    // Espera a Thread terminar
    pthread_join(jogo, NULL);
}
