#include <stdio.h>

int main(){

    // Letras das colunas do tabuleiro
    char* linha[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    
    // Inicialização do tabuleiro com zeros (0 = mar)
    int tabuleiro[10][10] = {0};

    // Definindo navios (3 = navio)
    // Navio horizontal na linha 1, colunas A, B, C
    tabuleiro[1][0] = 3;
    tabuleiro[1][1] = 3;
    tabuleiro[1][2] = 3;

    // Navio vertical na coluna F, linhas 5, 6, 7
    tabuleiro[4][5] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[6][5] = 3;

    // Cabeçalho
    printf(" - BATALHA NAVAL - \n\n");
    printf("   "); // Espaço para alinhar com números das linhas

    for(int i = 0; i < 10; i++){
        printf("%s ", linha[i]);
    }
    printf("\n");

    // Imprimindo linhas do tabuleiro
    for(int i = 0; i < 10; i++){
        if(i + 1 < 10){
            printf(" %d ", i + 1); // Alinhamento de números 1 a 9
        } else {
            printf("%d ", i + 1);  // Número 10
        }

        for(int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]); // Imprime 0 ou 3
        }
        printf("\n");
    }

    return 0;
}
