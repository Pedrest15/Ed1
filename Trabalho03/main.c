#include <stdio.h>
#include <string.h>
#include "arvbin.h"

void menssagem_erro(){
    printf("CIRCUIT ERROR\n");
}

int main(){
    ArvBin *arv = cria_ArvBin();
    FILE *arq;
    tipo_dado aux;
    int flag = 1;
    char entrada[30];
    int flag2 = 1;
    int x = 1;

    arq = fopen("circuit.txt", "rt");
    while(flag){
        fscanf(arq, "%s %s %s", aux.nome, aux.posicao, aux.pai);
        if (strncmp("$", aux.nome, 1) == 0){
            break;
        }
        insere_circuito(arv, aux, &flag);
    }
    fclose(arq);

    if(flag && verifica_arvore(arv, x)){
        while(1){
            fgets(entrada, 25, stdin);
            if(strncmp(entrada, "INP", 3) != 0){
                break;
            }
            sscanf(entrada,"%s %d", aux.nome, &aux.bit);
            insere_bit(arv, aux.nome, aux.bit, &flag2);
        }
        if(flag2){
            printf("%d\n", calcula_bit(arv));
        } else { 
            menssagem_erro();    
        }
    } else {
        menssagem_erro();
    }

    libera_ArvBin(arv);
    return 0;
}
