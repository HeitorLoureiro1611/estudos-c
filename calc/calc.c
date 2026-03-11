#include <stdio.h>
#include <stdlib.h>

float soma (float n1, float n2){return n1 + n2;}
float sub (float n1, float n2){return n1 - n2;}
float mult (float n1, float n2){return n1 * n2;}
float  divs (float n1, float n2){
    if (n2 == 0){
        printf("DIVISÃO POR 0, ERRO");
        return 0;
    }
    return n1 / n2;
}

int main(void){
    
    int rvalido = 1;
    char op = ' ';
    float n1, n2, resultado;

    while(op != 'q'){
        
        printf("\n\ncalculadora!\n\n");

        //menu
        printf("[ + ] Soma\n[ - ] Subtração\n[ / ] Divisão\n[ * ] Multiplicação\n[q para sair]\n\n");

        printf("Insira a operação: ");
        scanf(" %c", &op);
            if (op == 'q'){break;}
         
        printf("Escolha dois numeros: ");
        scanf("%f %f", &n1, &n2);

       //switch das escolhas
        switch (op) {
            case '+': resultado = soma(n1, n2); break;
            case '-': resultado = sub(n1, n2); break;
            case '/': resultado = divs(n1, n2); break;
            case '*': resultado = mult(n1, n2); break;
            default:
                printf("\n\nOPERAÇÃO INVALIDA!!!! O RESULTADO NÃO SERÁ MOSTRADO DE FORMA CORRETA\n\n");
                rvalido = 0; 
                break;
            }
        if (rvalido == 1){
            printf("\n========================================================");
            printf("\nO resultado da operação é %.2f", resultado);
            printf("\n========================================================");
        }
    }
    printf("\nObrigado por usar!\n");
    return 0;
}
