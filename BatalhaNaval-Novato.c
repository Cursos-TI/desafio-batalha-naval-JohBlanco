#include <stdio.h>
#include <stdlib.h> //Para utilizar a funcao rand,srand
#include <time.h> //Para utilizar a funcao time

int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com 0s (vazio)

void mostraTabuleiro() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}

int main(){
    srand(time(NULL)); //Inicializa o gerador com tempo atual, evitando valores repetidos    
    int linha,coluna;
    int navio1[3] = {3,3,3};
    int navio2[3] = {3,3,3};
       
    // Exibe o tabuleiro inicial
    mostraTabuleiro();

    // Define as coordenadas do navio 1
    linha = rand()%10; //Atribui a linha um valor aleatorio entre 0 e 9
    coluna = rand()%10; //Atribui a coluna um valor aleatorio entre 0 e 9
    
    //Certifica que o navio 1 caiba no tabuleiro
    if(linha<8){
        // Coloca o navio 1 na posição aleatória
        tabuleiro[linha][coluna] = navio1[0];
        tabuleiro[linha+1][coluna] = navio1[1];
        tabuleiro[linha+2][coluna] = navio1[2];
    }else{
        printf("O Navio 1 esta fora do tabuleiro.\n");
        return 0;
    }

    //Define as coordenadas do navio 2
    linha = rand()%10; //Atribui a linha um valor aleatorio entre 0 e 9
    coluna = rand()%10; //Atribui a coluna um valor aleatorio entre 0 e 9

    //Certifica que o navio 2 caiba no tabuleiro
    if(coluna<8){
        // Verifica se a posição está livre
        if(tabuleiro[linha][coluna] == 0 && tabuleiro[linha][coluna+1] == 0 && tabuleiro[linha][coluna+2] == 0){
            // Coloca o navio 2 na posição aleatória
            tabuleiro[linha][coluna] = navio2[0];
            tabuleiro[linha][coluna+1] = navio2[1];
            tabuleiro[linha][coluna+2] = navio2[2];
        }else{
            printf("O Navio 2 sobrepos o Navio 1.\n");
            return 0;
        }
    }else{
        printf("O Navio 2 esta fora do tabuleiro.\n");
        return 0;
    }

    // Exibe o tabuleiro atualizado
    mostraTabuleiro();

    return 0;
}
