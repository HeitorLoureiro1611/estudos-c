#include <stdio.h>
#include <stdlib.h>

int main(void){

    int total = 0;
    int nbuffer = 0;
    // Lista vazia com alocação manual de memoria
    int *list = malloc(4*sizeof(int));
    if (list == NULL){ // checagem padrão
        return 1;
    }

    // definindo o tamanho total da lista
    printf("Insira quantos numeros você quer colocar na lista: ");
    scanf(" %d", &total);

    // caso o tamanho total for maior que o tamanho original
    if (total > 4){
        // realocar pra um tamanho adequado
        int *temp = realloc(list, total*sizeof(int));
        if (temp == NULL){
            free(list);
            return 1;
        }
        // agora a lista aponta pro novo espaço de memória
        list = temp;
    } // temp para de existir aqui

    for (int i = 0; i < total; i++){
        printf("Insira o numero que ficará na %d posição", i+1);
        scanf(" %d", &nbuffer);
        list[i] = nbuffer;
    }

    for (int i = 0; i < total; i++){
        printf("%d\n",list[i]);
    }

    free(list);
    return 0;
}
