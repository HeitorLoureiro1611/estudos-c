#include <stdio.h>

int main(){

    FILE *arq;
    // Variável que deve receber o conteúdo de dentro do arquivo
    char data[255];

    // Abrindo o arquivo especifico em modo de leitura
    arq = fopen("Teste.txt", "r");
    if (arq == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // fgets(nessa_variável, com_esse_tamanho, arquivo) até acabar
    // fgets faz a leitura das linhas do arquivo
    while (fgets(data, 255, arq) != NULL){
        // printa as informações linha por linha
        printf("%s\n", data);
    }

    fclose(arq);
    return 0;
}
