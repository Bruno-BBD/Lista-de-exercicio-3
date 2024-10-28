#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (array[j] > array[j + 1]) {

                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }}}}

void imprimir_array(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
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
    bubble_sort(array, tamanho);

    printf("Array ordenado: ");
    imprimir_array(array, tamanho);




    return 0;





}

