#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int capacidade = 2;
    int *array = malloc(capacidade*sizeof(int));
    if (array == NULL){
        perror("Erro malloc");
    }

    // Inicializa
    for (int i = 0; i < capacidade; i++){
        array[i] = i;
    }

    // Lê
    printf("Memoria 1:\n");
    for (int i = 0; i < capacidade; i++){
        printf("%d -> %d | ",i, array[i]);
    }

    int *n_array = realloc(array, (capacidade*capacidade)*sizeof(int));
    if (n_array == NULL){
        free(array);
        perror("Erro malloc");
    }

    array = n_array;

    for (int i = 0; i < capacidade*capacidade; i++){
        array[i] = i;
    }

    printf("\nMemoria 1.2:\n");
    for (int i = 0; i < capacidade*capacidade; i++){
        printf("%d -> %d | ",i, array[i]);
    }


    // libera
    free (array);
    array = NULL; // dangling point
    return 0;
}
