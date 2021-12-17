#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avravl.h"

int main(){
    ArvAVL *avl = cria_ArvAVL();
    FILE *arq;
    tipo_dado aux;
    char linha[100];
    int flag = 1;
    int console;
    int cep_entr;

    arq = fopen("cepdata.txt", "r");
    while(1){
        fgets(linha, 100, arq);
        sscanf(linha, "%d %d %s %s", &aux.cep_ini, &aux.cep_fin, 
                                      aux.cidade, aux.estado);
        if(aux.cep_ini == 0 && aux.cep_fin == 0){
            break;
        }
        insere_ArvAVL(avl, aux, &flag);
    }
    fclose(arq);

    if(flag){
        scanf("%d", &console);
        switch (console){
            case 1: 
                printf("%d\n", totalNO_ArvAVL(avl));
                break;
            case 2:
                printf("%d\n", altura_ArvAVL(avl));
                break;
            case 3:
                scanf("%d", &cep_entr);
                consulta_cep_ArvAVL(avl, cep_entr);
                break;
            case 4:
                preOrdem_ArvAVL(avl);
                break;
            case 5:
                emOrdem_ArvAVL(avl);
                break;
        }
    }
    
    libera_ArvAVL(avl);
    return 0;
}
