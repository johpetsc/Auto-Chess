/*Arquivo main do jogo Auto Chess
  Programação Concorrente 02/2019
  Johannes Peter Schulte - 15/0132662
  Renato Avellar Nobre -  15/0146698*/

#include "../header/jogo.h"


int main(){
    // Cria Seed para funcoes rand
    srand(time(NULL));

    // Mostra uma msg bonitinha
    printf("Welcome to Thread Auto-Chess!\n");
    sleep(1);

    // Comeca o jogo
    inicializa_jogo();

    return 0;
}
