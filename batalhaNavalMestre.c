#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Função para imprimir o tabuleiro
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Habilidade: Cone (triângulo para baixo)
void applyCone(int board[SIZE][SIZE], int originX, int originY) {
    for (int i = originX; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j >= originY - (i - originX) && j <= originY + (i - originX)) {
                board[i][j] = 5;
            }
        }
    }
}

// Habilidade: Cruz
void applyCross(int board[SIZE][SIZE], int originX, int originY) {
    for (int i = 0; i < SIZE; i++) {
        board[i][originY] = 6;
        board[originX][i] = 6;
    }
}

// Habilidade: Octaedro (losango)
void applyOctahedron(int board[SIZE][SIZE], int originX, int originY) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (abs(i - originX) + abs(j - originY) <= 2) {
                board[i][j] = 7;
            }
        }
    }
}

// Função para imprimir a legenda
void printLegend() {
    printf("\nLegenda:\n");
    printf("0 - Água\n");
    printf("5 - Área afetada por Cone\n");
    printf("6 - Área afetada por Cruz\n");
    printf("7 - Área afetada por Octaedro\n");
}

int main() {
    // Inicializa o tabuleiro com 0
    int board[SIZE][SIZE] = {0};

    // Aplicar habilidades
    applyCone(board, 0, 5);       // Cone com origem no topo centro
    applyCross(board, 5, 5);      // Cruz no centro do tabuleiro
    applyOctahedron(board, 7, 3); // Octaedro no canto inferior esquerdo

    // Imprime resultado
    printf("Tabuleiro com habilidades aplicadas:\n");
    printBoard(board);

    // Imprime legenda
    printLegend();

    return 0;
}
