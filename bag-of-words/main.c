#include <stdio.h>
#include <string.h>
#include "avravl.h"
#include "ldes.h"

int main(){
    ArvAVL *avl = cria_ArvAVL();
    FILE *arq;
    char text[20];
    char str[20];
    int res;
    Lista* li = cria_lista();

    printf(">>>Gerador de Bag-of-Words<<<\n\n");
    printf(">>Qual arquivo será lido? ");
    scanf("%s", text);
    arq = fopen(text, "r");
    while((fscanf(arq, "%s", str) != EOF)){
        insere_ArvAVL(avl, str);
    }
    fclose(arq);
    printf("\n>>Arquivo lido e AVL criada<<\n\n");

    printf(">>Listando todas as palavras da AVL em ordem:\n");
    emOrdem_ArvAVL(avl);

    printf("\n>>Listando todas as palavras da AVL em pré-ordem:\n");
    preOrdem_ArvAVL(avl);

    printf("\n>>Altura da AVL: %d níveis\n", altura_ArvAVL(avl));

    printf(">>Total de nodos da AVL: %d nodos\n\n", totalNO_ArvAVL(avl));

    printf(">> Gerando lista ordenada de ocorrências\n\n");
    printf(">>Qual o número mínimo de ocorrências a ser listado? ");
    scanf("%d", &res);   
 
    transfere_dados(li, avl);
    imprime_lista(li, res);

    libera_ArvAVL(avl);
    libera_lista(li);

    return 0;
}
