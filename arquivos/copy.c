#include <stdio.h>

//       recebe argumentos do terminal
int main(int argc, char *argv[]){

    // seleciona dois arquivos que recebe do terminal
    FILE *arqorigem = fopen(argv[1], "rb");
    FILE *arqcopia = fopen(argv[2], "wb");

    // bytes sempre positivos (unsigned)
    unsigned char buffer;

    // enquanto estiver lendo byte a byte do arquivo de origem e não encontrar o final:
    // buffer = byte lido no arquivo de origem -> escreve o que estiver em buffer no arquivo de copia
    while (fread(&buffer, sizeof(buffer), 1, arqorigem) != 0){
        // copie o que estiver no buffer pro arquivo de copia
        fwrite(&buffer, sizeof(buffer), 1, arqcopia);
    }

    // fecha os arquivos
    fclose(arqorigem);
    fclose(arqcopia);
}
