#include <stdio.h>
#include <stdlib.h>

// pilha é um tipo abstrato de dado e estrutura de dados baseado no princípio de Last In First Out (LIFO)

typedef struct
{
    int *dados;
    int tamanho;
    int capacidade;

} pilha_t;

// inicialização de uma pilha
pilha_t* cria()
{
    pilha_t *pilha = malloc(sizeof(pilha_t));
    pilha->tamanho = 0;
    pilha->capacidade = 2;
    pilha->dados = malloc(pilha->capacidade*sizeof(int));
    return pilha;
}

// push vai sempre colocar um novo valor no ultimo indice da pilha
void push(pilha_t *pilha, int numero)
{
    //  caso a pilha fique cheia, dobra ela de tamanho
    if (pilha->tamanho == pilha->capacidade){
        int *tmp = realloc(pilha->dados, (pilha->capacidade*2)*sizeof(int));
        if (tmp == NULL){
            perror("Erro na alocação temporaria");
            free(pilha->dados);
            free(pilha);
            return;
        }
        pilha->dados = tmp;
        pilha->capacidade*=2;
    }
    // coloca o numero no ultimo item da lista e aumenta o tamanho dela
    pilha->dados[pilha->tamanho] = numero;
    pilha->tamanho++;
}

// remove sempre o ultimo indice da lista
void pop(pilha_t *pilha)
{
    // se a lista estiver vazia, n reduz o tamanho de nada
    if(pilha->tamanho > 0){
        pilha->tamanho--;
    } else{
        printf("Pilha vazia");
    }
}

int main()
{
    pilha_t *pilha = cria();
    printf("Tamanho: %d\n", pilha->tamanho);
    printf("Capacidade: %d\n", pilha->capacidade);


    printf("===============\n");

    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    push(pilha, 4);
    push(pilha, 5);

    for(int i = pilha->tamanho-1; i >= 0; i--){
        printf("%d -> %d\n", i, pilha->dados[i]);
    }

    printf("===============\n");

    pop(pilha);

    for(int i = pilha->tamanho-1; i >= 0; i--){
        printf("%d -> %d\n", i, pilha->dados[i]);
    }

    printf("===============\n");

    pop(pilha);

    for(int i = pilha->tamanho-1; i >= 0; i--){
        printf("%d -> %d\n", i, pilha->dados[i]);
    }

    printf("===============\n");

    free(pilha->dados);
    free(pilha);
    return 0;
}
