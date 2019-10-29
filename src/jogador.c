/*Modulo responsavel por executar as ações de cada jogador. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define JOGADORES 8
#define LINHAS 3
#define COLUNAS 6
#define HP 100

static int instancia[JOGADORES][LINHAS][COLUNAS] = {0};
static int HPs[JOGADORES];
pthread_mutex_t mutexEscrita;

/*enum custo{Basico=1, Raro, Epico, Lendario};
enum basico{Darius=1, Garen, Tristana, Vayne, Mordekaiser, Varus, Shen, Lulu};
enum raro{Aatrox=1, Ashe, Kennen, Poppy, Veigar, Vi};
enum epico{Brand=1, ChoGath, Draven, Leona};
enum lendario{Yasuo=1, Karthus};*/

void setHP(int hp){
    for(int i=0; i<JOGADORES; i++){
        HPs[i] = hp;
    }

}

void joga(int id, int pool[JOGADORES][5]){
    HPs[id] = HPs[id] - id;
    printf("To jogando. %d\n", HPs[id]);
}
void initMutex(){
    pthread_mutex_init(&mutexEscrita, NULL);
}


void tabuleiro(int id){

    
    pthread_mutex_lock(&mutexEscrita);
    printf("Tabuleiro do jogador %d\n", id);
    for(int i=0; i<LINHAS; i++){
        for(int j=0; j<COLUNAS; j++){
            printf("<%d>", instancia[id][i][j]);
        }
        printf("\n");
    }
    pthread_mutex_unlock(&mutexEscrita);
    sleep(1);
}
