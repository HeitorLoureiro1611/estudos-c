// wc simplificado
// contador de linhas, palavras e bytes
// 69 420 5890 arquivo.txt

#include <stdio.h>

int main(int argc, char *argv[]){

    char c;
    int linhascont = 0;
    int palavrascont = 0;
    int flag = 1;

    FILE *arq = fopen(argv[1], "r");
    if (arq == NULL) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    // bytes totais
    fseek(arq, 0, SEEK_END);
    int bytes = ftell(arq);
    fseek(arq, 0, SEEK_SET);

    while (fread(&c, sizeof(char), 1, arq)){
        if (c == '\n'){ linhascont++; }
    }

    rewind(arq);

    while (fread(&c, sizeof(char), 1, arq)){
        if (c == ' ' || c == '\n' || c == '\t'){
            flag = 0;

        }else {
            if(flag == 0){
                palavrascont++;
            }
            flag = 1;
        }
    }

    printf("%d %d %d %s\n",linhascont, palavrascont+1, bytes, argv[1]);
    fclose(arq);
    return 0;
}
