// calculadora de linha de comando

#include <stdio.h>
#include <stdlib.h>

float soma(float n1, float n2){ return n1 + n2; }
float sub(float n1, float n2){ return n1 - n2; }
float mult(float n1, float n2){ return n1 * n2; }
float divs(float n1, float n2){
    if (n2 == 0){
        printf("Divisão por 0...\n");
        return 0;
    }
    return n1 / n2;
}

int main(int argc, char *argv[]){

    if (argc < 4){
        printf("Você precisa inserir uma equação '%s x + y'\n", argv[0]);
        return 1;
    }

    float n1 = atof(argv[1]);
    char *op = argv[2];
    float n2 = atof(argv[3]);

    switch (*op) {
        case '+':{
            printf("O resultado é: %.1f\n",soma(n1,n2));
            break;
        }
        case '-': {
            printf("O resultado é: %.1f\n",sub(n1,n2));
            break;
        }
        case 'x': {
            printf("O resultado é: %.1f\n",mult(n1,n2));
            break;
        }
        case '/':{
            printf("O resultado é: %.2f\n", divs( n1, n2));
            break;
        }
        default:{
            printf("Operação inválida, tente + - x /\n");
        }
    }

    return 0;
}
