#include <stdio.h>
#include <stdlib.h>

void gnome_sort(int array[], int tamanho) {
    int indice = 0;

    while (indice < tamanho) {
        if (indice == 0) {
            indice++;
        }if (array[indice] >= array[indice - 1]) {
            indice++;
        }else {
            int temp = array[indice];
            array[indice] = array[indice - 1];
            array[indice - 1] = temp;
            indice--;
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

    gnome_sort(array, tamanho);

    printf("Array apos a ordenacao: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
