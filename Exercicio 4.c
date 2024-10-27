#include <stdio.h>
#include <stdlib.h>

void selection_sort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {

        int menor_idx = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (array[j] < array[menor_idx]) {
                menor_idx = j;
            }
        }
        if (menor_idx != i) {
            int temp = array[i];
            array[i] = array[menor_idx];
            array[menor_idx] = temp;
        }}}

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

    printf("Array antes da ordenacao: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    selection_sort(array, tamanho);

    printf("Array apos a ordenacao: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    return 0;


}

