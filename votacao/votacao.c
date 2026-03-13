#include <stdio.h>

int main(void){
    
    int candidato1 = 0, candidato2 = 0, voto = 0;

    printf("Votação!\n\n");
    
    while(voto != 9){

        printf("\nCandidatos:\n[1] Baleado | [2] Polvo\n[9] para sair\n\nEm quem você deseja votar:");
        scanf("%d", &voto);
    
        switch (voto) {
            case 1:
            printf("\n==========================================\n");
            candidato1++;
            break;

            case 2:
            printf("\n==========================================\n");
            candidato2++;
            break;
            
            case 9:
            printf("\n==========================================\n");
            printf("\n==========================================\n");
            break;
            
            default:
            printf("\nEscolha um dos candidatos!\n");
        }
    }

    printf("\n\nFIM DA VOTAÇÃO");
    printf("\nRESULTADO:\n\nBaldeado: %d\n\nPolvo: %d\n\n", candidato1, candidato2);

    if (candidato1 == candidato2){
        printf("EMPATE! :(\n");
    } else if(candidato1 > candidato2){
        printf("PARABENS BALEADO, VOCÊ GANHOU!!\n");
    }else {
        printf("PARABENS POLVO, VOCÊ É O NOVO CAMPEÃO\n");
    }
}
