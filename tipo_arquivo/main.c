#include <stdio.h>

int main(){

    char nome[255];
    FILE *arq;
    unsigned char header[4];

    printf("Insira o nome do seu arquivo:");
    scanf(" %s", nome);

    arq = fopen(nome, "rb");
    if (arq == NULL){
        perror("Arquivo desconhecido");
        return 1;
    }
    fread(header, sizeof(unsigned char), 4, arq);

    if (header[0] == 0xff && header[1] == 0xd8 && header[2] == 0xff){
        printf("isso é um jpg\n");
    } else if(header[0] == 0x25 && header[1] == 0x50){
        printf("Isso é um pdf\n");
    } else if(header[0] == 0x89 && header[1] == 0x50){
        printf("Isso é um png\n");
    }else{
        printf("não consegui ler\n");
    }

    fclose(arq);
    return 0;
}
