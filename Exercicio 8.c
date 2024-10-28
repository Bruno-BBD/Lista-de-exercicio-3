#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void imprimir_tabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\n  1   2   3\n");
    printf("-------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c |", tabuleiro[i][j]);
        }
        printf("\n-------------\n");
    }
    printf("\n");
}

int verificar_vencedor(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return tabuleiro[i][0];
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return tabuleiro[0][i];
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return tabuleiro[0][2];

    return ' ';
}

int main() {
    char tabuleiro[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    int jogadas = 0;
    char jogador = 'X';
    int linha, coluna;

    while (1) {
        imprimir_tabuleiro(tabuleiro);
        printf("Jogador %c, insira sua jogada (linha e coluna): ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (linha < 1 || linha > SIZE || coluna < 1 || coluna > SIZE || tabuleiro[linha - 1][coluna - 1] != ' ') {
            printf("Jogada invalida. Tente novamente.\n");
            continue;
        }

        tabuleiro[linha - 1][coluna - 1] = jogador;
        jogadas++;

        char vencedor = verificar_vencedor(tabuleiro);
        if (vencedor != ' ') {
            imprimir_tabuleiro(tabuleiro);
            printf("O jogador %c venceu!\n", vencedor);
            break;
        }

        if (jogadas == SIZE * SIZE) {
            imprimir_tabuleiro(tabuleiro);
            printf("Empate!\n");
            break;
        }

        jogador = (jogador == 'X') ? 'O' : 'X';
    }

    return 0;
}
