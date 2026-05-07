#include <stdio.h>
#include <string.h>

int main(){

    // nome do arquivo que eu quero utilizar (Facilitação de processo)
    char nome[] = "Teste.txt";
    // String da menságem que eu pretendo Iniciar meu programa
    char msg[] = "Hello world!\n";

    // Ponteiro do tipo FILE
    // Utilizo para manipular o arquivo
    FILE *arq;

    // Arquivo sendo aberto com o nome desejado e a forma de manipulação
    arq = fopen(nome,"w");
    // lidando com erros
    if (arq == NULL){
        // caso tenha um erro, printar essa mensagem
        perror("Erro ao abrir o arquivo");
        return 1;
    }else{
       printf("O arquivo foi aberto\n");
    }

    // escreve a menságem no arquivo
    // fwrite(o_que_escrever, tamanho_de_cada_elemento, quantos_elementos, arquivo)
    fwrite(msg, sizeof(char), strlen(msg) ,arq);

    // fecha o arquivo (processo importante pós utilização do arquivo, evita vulterabilidades)
    fclose(arq);
    return 0;
}
