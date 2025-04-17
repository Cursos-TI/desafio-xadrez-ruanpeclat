#include <stdio.h>

// Definindo constantes para os limites de movimento
#define MOVIMENTO_BISPO 5
#define MOVIMENTO_TORRE 5
#define MOVIMENTO_RAINHA 8

int main() {
    // Variáveis para armazenar as direções de movimento
    int i;

    // Movimento do Bispo - Diagonal superior direita
    printf("Movimento do Bispo (Diagonal superior direita):\n");
    for(i = 0; i < MOVIMENTO_BISPO; i++) {
        printf("Cima\n");
        printf("Direita\n");
    }

    // Movimento da Torre - 5 casas para a direita
    printf("\nMovimento da Torre (Direita):\n");
    for(i = 0; i < MOVIMENTO_TORRE; i++) {
        printf("Direita\n");
    }

    // Movimento da Rainha - 8 casas para a esquerda
    printf("\nMovimento da Rainha (Esquerda):\n");
    for(i = 0; i < MOVIMENTO_RAINHA; i++) {
        printf("Esquerda\n");
    }

    return 0;
}

