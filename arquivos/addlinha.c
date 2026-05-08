#include <stdio.h>
#include <string.h>

int main(){

    FILE *arq;
    char nmsg[255] = "Nova linha add";
    // abre o arquivo em modo Append (adiciona linhas sem apagar o programa)
    arq = fopen("Teste.txt", "a");
    if (arq == NULL){
        perror("Erro ao abrir o arquivo");
    }
    // escreve uma linha ao fim do arquivo
    fwrite(nmsg, sizeof(char), strlen(nmsg), arq);

    fclose(arq);
    return 0;
}
