#include <stdio.h>
#include <stdlib.h>

int remove_repetidos(int array[], int tamanho) {
    if (tamanho == 0) return 0;

    int nova_pos = 1;

    for (int i = 1; i < tamanho; i++) {
        int j;
        for (j = 0; j < nova_pos; j++) {
            if (array[i] == array[j]) {
                break;
            }
        }

        if (j == nova_pos) {
            array[nova_pos] = array[i];
            nova_pos++;
        }}

    return nova_pos;
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Array antes da remocao de repetidos: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    tamanho = remove_repetidos(array, tamanho);

    printf("Array apos a remocao de repetidos: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Novo tamanho do array:%d.",tamanho);

    return 0;
}

