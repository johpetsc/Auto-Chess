/*Modulo responsavel por executar as ações de cada jogador. */


#include "../header/jogador.h"

//Thread Jogador
void *jogador(void *args){
    // Inicializa Jogador
    int poder = 0;
    int id = *((int *)args);
    printf("[Jogador %d] Iniciado com 100 de Vida\n", id+1);
    sleep(1);
    int d = -1;
    int k = 0;
    while(fim){
        if(d!=stage){
            d = stage;
            do{
                k = joga(id);
            }while(k);
            compra(id);
        }else{
            sleep(1);
        }

    }
    pthread_exit(NULL);
}

void compra(int id){
    int a, b;
    a = rand()%5;
    b = rand()%5;
    //printf("opa%d\n", id);
    pthread_mutex_lock(&mutex_round[id]);
    //printf("bao%d\n", id);
    if(poolJogador[id][a]<8)
        poderDeCombate[id] +=1;
    else if(poolJogador[id][a]<14)
        poderDeCombate[id] +=2;
    else if(poolJogador[id][a]<18)
        poderDeCombate[id] +=3;
    else
        poderDeCombate[id] +=4;
    
    if(poolJogador[id][b]<8)
        poderDeCombate[id] +=1;
    else if(poolJogador[id][b]<14)
        poderDeCombate[id] +=2;
    else if(poolJogador[id][b]<18)
        poderDeCombate[id] +=3;
    else
        poderDeCombate[id] +=5;
    pthread_mutex_unlock(&mutex_round[id]);
    pthread_cond_signal(&cond_compra[id]);
    //printf("k%d\n", id);

}
// Entra no tabuleiro sempre que disponivel
int joga(int id){

    while(fim){
        pthread_mutex_lock(&mutex_tabuleiro);
        if(pqp){
            pthread_mutex_unlock(&mutex_tabuleiro);
            return 1;
        }
        tabuleiro +=1;

        if (tabuleiro == 1) {
            battle_ids[0] = id+1;
            pthread_mutex_unlock(&mutex_tabuleiro);
            return 0;
        }

        if (tabuleiro == 2) {
            battle_ids[1] = id+1;
            pthread_cond_signal(&cond_full);
            pqp = 1;
            pthread_mutex_unlock(&mutex_tabuleiro);
            return 0;
        }else{
            pthread_mutex_unlock(&mutex_tabuleiro);
            return 0;
        }
    }

    return 0;

}
