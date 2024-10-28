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

int* merge_and_sort(int array1[], int tamanho1, int array2[], int tamanho2) {
    int* resultado = (int*)malloc((tamanho1 + tamanho2) * sizeof(int));
    if (resultado == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return NULL;
    }
    for (int i = 0; i < tamanho1; i++) {
        resultado[i] = array1[i];
    }
    for (int i = 0; i < tamanho2; i++) {
        resultado[tamanho1 + i] = array2[i];
    }
    selection_sort(resultado, tamanho1 + tamanho2);
    return resultado;
}
int main() {
    int tamanho;

    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &tamanho);

    int array1[tamanho];
    int array2[tamanho];

    printf("Digite os elementos do primeiro array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array1[i]);
    }
    printf("Digite os elementos do segundo array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array2[i]);
    }
    int* resultado = merge_and_sort(array1, tamanho, array2, tamanho);

    if (resultado != NULL) {
        printf("Array combinado e ordenado: ");
        for (int i = 0; i < 2 * tamanho; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");

        free(resultado);


    }



    return 0;




}

