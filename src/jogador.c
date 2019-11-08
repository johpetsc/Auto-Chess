/*Modulo responsavel por executar as ações de cada jogador. */


#include "../header/jogador.h"

//Thread Jogador
void *jogador(void *args){
    // Inicializa Jogador
    int id = *((int *)args);
    printf("[Jogador %d] Iniciado com 100 de Vida\n", id+1);
    sleep(1);
    joga(id);
    pthread_exit(NULL);
}

// Entra no tabuleiro sempre que disponivel
void joga(int id){
    while(1){
        pthread_mutex_lock(&mutex_tabuleiro);
        if (tabuleiro == 2) {
            pthread_cond_wait(&cond_empty, &mutex_tabuleiro);
        } else {
            tabuleiro += 1;
        }

        if (tabuleiro == 1) {
            battle_ids[0] = id+1;
        }

        if (tabuleiro == 2) {
            battle_ids[1] = id+1;
            pthread_cond_signal(&cond_full);
        }
        pthread_mutex_unlock(&mutex_tabuleiro);

    }
}
