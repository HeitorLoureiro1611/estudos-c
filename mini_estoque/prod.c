#include <stdio.h>

const int MAX_ESTOQUE = 3;

typedef struct
{
    char nome[100];
    int quantidade;
    double preco;
}produtos;

int main (void)
{

    float valor_total_geral = 0;

    produtos lista[MAX_ESTOQUE];
    
    printf("=============CADASTRANDO PRODUTOS=============");

    for(int i = 0; i < MAX_ESTOQUE; i++)
    {
        printf("\nInsira o nome do %d produto: ", i+1);
        scanf("%s", lista[i].nome);
    
        printf("\nInsira a quantidade em estoque do %d produto: ", i+1);
        scanf("%d", &lista[i].quantidade);

        printf("\nInsira o preço do %d produto: ", i+1);
        scanf("%lf", &lista[i].preco);

        printf("\n==================================================\n");
    }

    printf("=============MOSTRANDO PRODUTOS==============\n");
    
    for(int i = 0; i < MAX_ESTOQUE; i++)
    {
        printf("%s | %d | %.2f\n", lista[i].nome, lista[i].quantidade, lista[i].preco);
        valor_total_geral += (lista[i].quantidade * lista[i].preco);

    }
    printf("\nValor total do que temos em estoque: %.2f\n", valor_total_geral);
}
