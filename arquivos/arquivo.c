#include<stdio.h>
#include <string.h>

void criar(FILE *arq, char *nome){
    arq = fopen(nome, "w");
    if (arq == NULL){
        perror("Erro ao criar arquivo");
    }
    printf("Arquivo criado!\n\n");

    fclose(arq);
}

void ler(FILE *arq, char *nome){
    char info[1024];
    arq = fopen(nome, "r");
    if (arq == NULL){
        printf("Arquivo não existente, Crie o arquivo primeiro!\n");
        return;
    }
    while (fgets(info, 1024, arq) != NULL){
        printf("%s", info);
    }
    fclose(arq);
}

void add(FILE *arq, char *nome, char *msg){
    arq = fopen(nome, "a");
    if (arq == NULL){
        perror("Erro ao adicionar linha");
    }

    fwrite(msg, sizeof(char), strlen(msg), arq);
    fwrite("\n", sizeof(char), 1, arq);

    fclose(arq);
}

int main(){
    FILE *arq;
    char *nome = "Arquivo.txt";
    char msg[1024];

    int op;

    while(op != 9){
        printf("\n[1]Criar\n[2]Ler\n[3]Adicionar\n\n[9]Sair!\n\n");

        scanf("%d", &op);

            switch (op){
            case 1: {
                criar(arq, nome);
                break;

            } case 2:{
                ler(arq, nome);
                break;

            } case 3: {
                printf("Insira sua menságem: ");
                scanf(" "); // bufer
                fgets(msg, sizeof(msg), stdin);
                msg[strcspn(msg, "\n")] = '\0';

                add(arq, nome, msg);
                break;

            } case 9:{
                printf("Até logo!\n");
                break;

            }
            default:{
                printf("Operação inválida\n");
            }
        }
    }

}
