#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *dados; // lista em sí de dados guardados na memoria "lista = []"
    int tamanho; // tamanho atual da lista
    int capacidade; // capacidade total da lista
}array_t;

// função responsável por criar a struct e setar os valores iniciais
array_t* criar() // função com retorno do ponteiro da estrutura
{
    array_t *array = malloc(sizeof(array_t)); // sizeof(array_t) pra eu receber a quantidade necessaria de bytes pra criação de todas as informações
    array->capacidade = 2; // define a capacidade atual
    array->tamanho = 0;  // define o tamanho atual
    array->dados = malloc(array->capacidade*sizeof(int)); // define a lista que é um tipo inteiro, por isso sizeof(int)
    return array; // retorna a estrutura completa que foi definida
}

// função responsável por pegar um numero e inserir na lista
void inserir(array_t* array, int num) // recebe o ponteiro da estrutura, e o numero a ser inserido
{
    if (array->capacidade == array->tamanho){  // dobra o tamanho da memoria se precisar de mais espaço

        // array->dados é um tipo inteiro, logo é neceesario criar uma variável do tipo inteiro
        int *tmp = realloc(array->dados, sizeof(int)*(2*array->capacidade)); // variável temporaria de realocação do tamanho da lista
        if (tmp == NULL){
            free(array->dados);
            free(array);
            return;
        }
        array->capacidade *= 2; // dobra a capacidade
        array->dados = tmp; // recebe o realloc
    }
    array->dados[array->tamanho] = num; // insere o numero no tamanho atual da lista
    array->tamanho++; // adiciona 1 no tamanho da lista
}

int main(void)
{
    array_t *array = criar();

    inserir(array, 10);
    inserir(array, 11);

    for (int i = 0; i < array->tamanho; i++){
        printf("%d -> %d\n", i+1, array->dados[i]);
    }

    free(array->dados);
    free(array);
    array->dados = NULL;
    array = NULL;
    return 0;
}
