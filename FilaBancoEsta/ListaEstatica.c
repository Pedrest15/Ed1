#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.h"

struct lista{
    int qtd;
    struct pessoa dados[MAX];
};

Lista* cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL){
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista *li){
    free(li);
}

int insere_lista_final(Lista *li, struct pessoa p){
    if (li == NULL){ //erro na hora de criar a lista
        return ERRO;
    }
    li->dados[li->qtd] = p;
    li->qtd++;
    return OK;
}

void consulta_lista_pos(Lista *li, int pos){
    if (li == NULL || pos <= 0 || pos > li->qtd){
        printf("Posição inválida.\n");
        return;
    }
    printf("A pessoa na posição %d é %s\n", pos, li->dados[pos-1].nome);
}

void remove_lista_inicio(Lista*li){ //copia os valores da lista um indice a menos
    for (int i = 0; i < (li->qtd - 1); i++){
        li->dados[i] = li->dados[i + 1];
        li->dados[i].pos--;
    }
    li->qtd--; //incrementa a qtd, assim, fica impossivel acessar o indice mais alto
}

void imprime_lista(Lista *li){
    if (li == NULL){ //erro na hora de criar a lista
        return;
    }
    for(int i = 0; i < li->qtd; i++){
        printf("Nome: %s\n", li->dados[i].nome);
        printf("Posição: %d\n", li->dados[i].pos);
    }
    printf("---------------------------------\n");
}