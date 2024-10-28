#include <stdio.h>
#include <stdlib.h>

void selection_sort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor_idx = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (array[j] < array[menor_idx]) {
                menor_idx = j;
            }}
        if (menor_idx != i) {
            int temp = array[i];
            array[i] = array[menor_idx];
            array[menor_idx] = temp;
        }}}

float calcular_mediana(int array[], int tamanho) {
    selection_sort(array, tamanho);

    if (tamanho % 2 == 0) {
        int meio1 = array[tamanho / 2 - 1];
        int meio2 = array[tamanho / 2];
        return (meio1 + meio2) / 2.0;
    } else {
        return array[tamanho / 2];
    }}

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
    float mediana = calcular_mediana(array, tamanho);
    printf("A mediana do array eh: %.2f\n", mediana);



    return 0;


}

