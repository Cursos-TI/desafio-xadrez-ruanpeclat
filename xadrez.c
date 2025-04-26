#include <stdio.h>
#include <stdlib.h>

// Tabuleiro inicial
char tabuleiro[8][8] = {
    { 't', 'c', 'b', 'k', 'q', 'b', 'c', 't' }, 
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' }, 
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' }, 
    { 'T', 'C', 'B', 'K', 'Q', 'B', 'C', 'T' }  
};

// Função para exibir o tabuleiro
void exibir_tabuleiro() {
    int i, j;
    char letras[] = "   A   B   C   D   E   F   G   H";

    printf("\n%s\n", letras);
    for (i = 0; i < 8; i++) {
        printf("  ---------------------------------\n");
        printf("%d", 8 - i);
        for (j = 0; j < 8; j++) {
            printf("| %c ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("  ---------------------------------\n");
}

// Função recursiva para mover Bispo
void mover_bispo(int passos) {
    if (passos == 0) return;
    printf("Diagonal Superior Direita\n");
    mover_bispo(passos - 1);
}

// Função para mover Torre usando for
void mover_torre(int passos) {
    for (int i = 0; i < passos; i++) {
        printf("Direita\n");
    }
}

// Função para mover Rainha usando while
void mover_rainha(int passos) {
    int i = 0;
    while (i < passos) {
        printf("Esquerda\n");
        i++;
    }
}

// Função para mover Cavalo usando loops aninhados
void mover_cavalo() {
    for (int i = 0; i < 2; i++) {
        int j = 0;
        do {
            if (i == 0 && j == 0) {
                printf("Baixo\n");
            } else if (i == 1 && j == 0) {
                printf("Baixo\n");
            } else if (i == 1 && j == 1) {
                printf("Esquerda\n");
            }
            j++;
        } while (j < 2);
    }
}

// Função para mover a peça e mostrar movimento especial
void mover_peca(int r1, int c1, int r2, int c2) {
    char temp = tabuleiro[r1][c1];
    tabuleiro[r1][c1] = ' ';
    tabuleiro[r2][c2] = temp;

    // Movimento especial apenas para Bispo, Torre, Rainha e Cavalo
    switch (temp) {
        case 'b': case 'B':
            mover_bispo(5);
            break;
        case 't': case 'T':
            mover_torre(5);
            break;
        case 'q': case 'Q':
            mover_rainha(8);
            break;
        case 'c': case 'C':
            mover_cavalo();
            break;
        default:
            break;
    }
}

// Função do turno do jogador
void turno_jogador(int jogador) {
    char col1, col2;
    int lin1, lin2;
    int c1, c2, r1, r2;

    printf("\nJogador %d", jogador);
    printf("\nDigite a posição da peça (ex: E2): ");
    scanf(" %c%d", &col1, &lin1);

    printf("Digite a nova posição (ex: E4): ");
    scanf(" %c%d", &col2, &lin2);

    c1 = col1 - 'A';
    c2 = col2 - 'A';
    r1 = 8 - lin1;
    r2 = 8 - lin2;

    if (r1 < 0 || r1 > 7 || c1 < 0 || c1 > 7 || tabuleiro[r1][c1] == ' ') {
        printf("Posição inválida!\n");
        return;
    }

    if (r2 < 0 || r2 > 7 || c2 < 0 || c2 > 7) {
        printf("Destino inválido!\n");
        return;
    }

    mover_peca(r1, c1, r2, c2);
}

// Função principal
int main() {
    int rodada = 1;

    printf("\n\tBEM-VINDO AO JOGO DE XADREZ");
    printf("\nPressione ENTER para iniciar...");
    getchar();

    do {
        system("cls"); // Se estiver no Linux/Mac troque para "clear"
        exibir_tabuleiro();
        turno_jogador((rodada % 2 == 1) ? 1 : 2);
        printf("\nPressione ENTER para continuar...\n");
        getchar();
        rodada++;
    } while (1);

    return 0;
}

