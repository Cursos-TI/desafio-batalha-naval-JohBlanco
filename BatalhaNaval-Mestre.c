#include <stdio.h>
#include <stdlib.h> //Para utilizar a funcao rand,srand
#include <time.h> //Para utilizar a funcao time

int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com 0s (vazio)

// ---------- CONE 3x3 ----------
void cone(int matriz[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matriz[i][j] = 0;

    int centro = 1;

    for (int i = 0; i <= centro; i++) {
        for (int j = centro - i; j <= centro + i; j++) {
            matriz[i][j] = 1;
        }
    }
}

// ---------- CRUZ 3x3 ----------
void cruz(int matriz[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matriz[i][j] = 0;

    int centro = 1;

    for (int i = 0; i < 3; i++) {
        matriz[i][centro] = 1; // coluna do meio
        matriz[centro][i] = 1; // linha do meio
    }
}

// ---------- OCTAEDRO 5x5 ----------
void octaedro(int matriz[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = 0;

    int centro = 2;

    for (int i = 0; i < 5; i++) {
        int dist = i <= centro ? i : 4 - i;
        for (int j = centro - dist; j <= centro + dist; j++) {
            matriz[i][j] = 1;
        }
    }
}

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
    int navio[3] = {3,3,3};
       
    // Exibe o tabuleiro inicial
    mostraTabuleiro();

    // Define as coordenadas do navio 1
    linha = rand()%10; //Atribui a linha um valor aleatorio entre 0 e 9
    coluna = rand()%10; //Atribui a coluna um valor aleatorio entre 0 e 9
    
    //Certifica que o navio 1 caiba no tabuleiro
    if(linha<8){
        // Coloca o navio 1 na posição vertical aleatória
        tabuleiro[linha][coluna] = navio[0];
        tabuleiro[linha+1][coluna] = navio[1];
        tabuleiro[linha+2][coluna] = navio[2];
    }else{
        printf("O Navio 1 esta fora do tabuleiro.\n");
        printf("-----------------------------\n");
    }

    //Define as coordenadas do navio 2
    linha = rand()%10; //Atribui a linha um valor aleatorio entre 0 e 9
    coluna = rand()%10; //Atribui a coluna um valor aleatorio entre 0 e 9

    //Certifica que o navio 2 caiba no tabuleiro
    if(coluna<8){
        // Verifica se a posição está livre
        if(tabuleiro[linha][coluna] == 0 && tabuleiro[linha][coluna+1] == 0 && tabuleiro[linha][coluna+2] == 0){
            // Coloca o navio 2 na posição horizontal aleatória
            tabuleiro[linha][coluna] = navio[0];
            tabuleiro[linha][coluna+1] = navio[1];
            tabuleiro[linha][coluna+2] = navio[2];
        }else{
            printf("O Navio 2 sobrepos um dos navios.\n");
            printf("-----------------------------\n");
        }
    }else{
        printf("O Navio 2 esta fora do tabuleiro.\n");
        printf("-----------------------------\n");
    }

    //Define as coordenadas do navio 3
    linha = rand()%10; //Atribui a linha um valor aleatorio entre 0 e 9
    coluna = rand()%10; //Atribui a coluna um valor aleatorio entre 0 e 9

    //Certifica que o navio 3 caiba no tabuleiro
    if(linha<8 && coluna<8){
        // Verifica se a posição está livre
        if(tabuleiro[linha][coluna] == 0 && tabuleiro[linha+1][coluna+1] == 0 && tabuleiro[linha+2][coluna+2] == 0){
            // Coloca o navio 3 na posição diagonal aleatória
            tabuleiro[linha][coluna] = navio[0];
            tabuleiro[linha+1][coluna+1] = navio[1];
            tabuleiro[linha+2][coluna+2] = navio[2];
        }else{
            printf("O Navio 3 sobrepos um dos Navios.\n");
            printf("-----------------------------\n");
        }
    }else{
        printf("O Navio 3 esta fora do tabuleiro.\n");
        printf("-----------------------------\n");
    }

    //Define as coordenadas do navio 4
    linha = rand()%10; //Atribui a linha um valor aleatorio entre 0 e 9
    coluna = rand()%10; //Atribui a coluna um valor aleatorio entre 0 e 9

    //Certifica que o navio 4 caiba no tabuleiro
    if(linha>1 && coluna<8){
        // Verifica se a posição está livre
        if(tabuleiro[linha][coluna] == 0 && tabuleiro[linha-1][coluna+1] == 0 && tabuleiro[linha-2][coluna+2] == 0){
            // Coloca o navio 4 na posição diagonal aleatória
            tabuleiro[linha][coluna] = navio[0];
            tabuleiro[linha-1][coluna+1] = navio[1];
            tabuleiro[linha-2][coluna+2] = navio[2];
        }else{
            printf("O Navio 4 sobrepos um dos Navios.\n");
            printf("-----------------------------\n");
        }
    }else{
        printf("O Navio 4 esta fora do tabuleiro.\n");
        printf("-----------------------------\n");
    }

    // Exibe o tabuleiro atualizado
    mostraTabuleiro();
    
    //Constroi as Matrizes de habilidades
    int HCone[3][3];
    int HCruz[3][3];
    int HOcta[5][5];
    cone(HCone);
    cruz(HCruz);
    octaedro(HOcta);

    //Define as coordenadas do centro de efeito da habilidade
    linha = rand()%10; //Atribui a linha um valor aleatorio entre 0 e 9
    coluna = rand()%10; //Atribui a coluna um valor aleatorio entre 0 e 9

    //Calculo da zona de efeito da Habilidade Cone
    if(linha > 0 && linha < 9 && coluna > 0 && coluna < 9) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (HCone[i][j] == 1) {
                    tabuleiro[linha+i-1][coluna+j-1] = 1; // Marca a zona de efeito no tabuleiro, utilizando o centro da matriz de habilidade como referência
                }
            }
        }
    }else{
        printf("A habilidade Cone caiu fora do tabuleiro.\n");
        printf("-----------------------------\n");
    }

    // Exibe o tabuleiro atualizado
    mostraTabuleiro();

    //Define as coordenadas do centro de efeito da habilidade
    linha = rand()%10; //Atribui a linha um valor aleatorio entre 0 e 9
    coluna = rand()%10; //Atribui a coluna um valor aleatorio entre 0 e 9

    //Calculo da zona de efeito da Habilidade Cruz
    if(linha > 0 && linha < 9 && coluna > 0 && coluna < 9) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (HCruz[i][j] == 1) {
                    tabuleiro[linha+i-1][coluna+j-1] = 1; // Marca a zona de efeito no tabuleiro, utilizando o centro da matriz de habilidade como referência
                }
            }
        }
    }else{
        printf("A habilidade Cruz caiu fora do tabuleiro.\n");
        printf("-----------------------------\n");
    }
    // Exibe o tabuleiro atualizado
    mostraTabuleiro();

    //Define as coordenadas do centro de efeito da habilidade
    linha = rand()%10; //Atribui a linha um valor aleatorio entre 0 e 9
    coluna = rand()%10; //Atribui a coluna um valor aleatorio entre 0 e 9

    //Calculo da zona de efeito da Habilidade Octaedro
    if(linha > 1 && linha < 8 && coluna > 1 && coluna < 8) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (HOcta[i][j] == 1) {
                    tabuleiro[linha+i-2][coluna+j-2] = 1; // Marca a zona de efeito no tabuleiro, utilizando o centro da matriz de habilidade como referência
                }
            }
        }
    }else{
        printf("A habilidade Octaedro caiu fora do tabuleiro.\n");
        printf("-----------------------------\n");
    }

    // Exibe o tabuleiro atualizado
    mostraTabuleiro();
    return 0;
}
