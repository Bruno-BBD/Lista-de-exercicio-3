#include <stdio.h>
#include <stdlib.h>

void rotacionar_array(int array[], int tamanho, int rotacoes, char direcao) {
    rotacoes = rotacoes % tamanho;
    if (rotacoes < 0) {
        rotacoes += tamanho;
    }
    int temp[tamanho];

    for (int i = 0; i < tamanho; i++) {
        temp[(i + rotacoes) % tamanho] = array[i];
    }
    for (int i = 0; i < tamanho; i++) {
        array[i] = temp[i];
    }}

void imprimir_array(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main() {
    int tamanho, rotacoes;
    char direcao;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("Digite o numero de rotacoes: ");
    scanf("%d", &rotacoes);

    printf("Digite a direcao (d para direita, e para esquerda): ");
    scanf(" %c", &direcao);

    rotacionar_array(array, tamanho, (direcao == 'd' ? rotacoes : -rotacoes), direcao);

    printf("Array após a rotação: ");
    imprimir_array(array, tamanho);




    return 0;




}

