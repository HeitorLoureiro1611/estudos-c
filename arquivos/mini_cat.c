// cat simplificado

#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *arq = fopen(argv[1], "r");
    if (arq == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char nbuffer[1024];

    while (fgets(nbuffer, 1024, arq) != NULL) {
        printf("%s", nbuffer);
    }

    fclose(arq);
    return 0;
}
