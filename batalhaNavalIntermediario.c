#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAMANHO 10
#define NAVIO 3

int main() {
    // Letras das colunas para exibição
    char* colunas[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

    // Inicializa o tabuleiro com 0 (representa água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Posicionamento dos navios
    // ---------------------------
    // 1º navio - Horizontal na linha 2 (índice 1), colunas 1 a 3
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[1][i + 1] = 3;
    }

    // 2º navio - Vertical na coluna 7 (índice 6), linhas 5 a 7
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[4 + i][6] = 3;
    }

    // 3º navio - Diagonal principal a partir de [0][0]
    for (int i = 0; i < NAVIO; i++) {
        // Verifica se posição está livre
        if (tabuleiro[i][i] == 0) {
            tabuleiro[i][i] = 3;
        }
    }

    // 4º navio - Diagonal secundária a partir de [2][7]
    for (int i = 0; i < NAVIO; i++) {
        int linha = 2 + i;
        int coluna = 7 - i;
        // Valida se está dentro dos limites e sem sobreposição
        if (linha < TAMANHO && coluna >= 0 && tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = 3;
        }
    }

    // Impressão do cabeçalho
    printf(" - BATALHA NAVAL - \n\n");
    printf("   ");
    for (int i = 0; i < TAMANHO; i++) {
        printf(" %s", colunas[i]);
    }
    printf("\n");

    // Impressão do tabuleiro com coordenadas
    for (int i = 0; i < TAMANHO; i++) {
        // Alinhamento dos números das linhas
        if (i + 1 < 10)
            printf(" %d ", i + 1);
        else
            printf("%d ", i + 1);

        for (int j = 0; j < TAMANHO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
