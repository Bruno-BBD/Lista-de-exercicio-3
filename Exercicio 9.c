#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20

void inicializar_matriz(int matriz[MAX_ROWS][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 2;
        }}}

void imprimir_matriz(int matriz[MAX_ROWS][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int contar_vizinhos_vivos(int matriz[MAX_ROWS][MAX_COLS], int m, int n, int x, int y) {
    int contagem = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int nova_x = x + i;
            int nova_y = y + j;
            if (nova_x >= 0 && nova_x < m && nova_y >= 0 && nova_y < n) {
                contagem += matriz[nova_x][nova_y];

      }}}
    return contagem;
}

void atualizar_matriz(int matriz[MAX_ROWS][MAX_COLS], int m, int n) {
    int nova_matriz[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int vizinhos_vivos = contar_vizinhos_vivos(matriz, m, n, i, j);
            if (matriz[i][j] == 1) {
                if (vizinhos_vivos < 2 || vizinhos_vivos > 3) {
                    nova_matriz[i][j] = 0;
                } else {
                    nova_matriz[i][j] = 1;
                }
            } else {
                if (vizinhos_vivos == 3) {
                    nova_matriz[i][j] = 1;
                } else {
                    nova_matriz[i][j] = 0;
                }}}}

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = nova_matriz[i][j];
        }}}

int main() {
    srand(time(NULL));

    int m, n;
    printf("Digite o numero de linhas (m) e colunas (n): ");
    scanf("%d %d", &m, &n);

    if (m > MAX_ROWS || n > MAX_COLS) {
        printf("Tamanho maximo da matriz eh %dx%d.\n", MAX_ROWS, MAX_COLS);
        return 1;
    }

    int matriz[MAX_ROWS][MAX_COLS];
    inicializar_matriz(matriz, m, n);

    printf("Estado inicial da matriz:\n");
    imprimir_matriz(matriz, m, n);

    for (int i = 0; i < 5; i++) {
        atualizar_matriz(matriz, m, n);
        printf("Estado apos a iteracao %d:\n", i + 1);
        imprimir_matriz(matriz, m, n);



    }




    return 0;




}

