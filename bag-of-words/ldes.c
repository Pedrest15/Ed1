#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ldes.h"  //inclui os Protótipos

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

void insere_lista_ord_decres(Lista* li, tipo_dado info){ 
    if(li == NULL){
        return;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return;
    }
    no->dado.cont = info.cont;
    strcpy(no->dado.palavra, info.palavra);
    if((*li) == NULL){ //lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return;
    } else {
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dado.cont > info.cont){
            ant = atual;
            atual = atual->prox;
        }
        while(atual != NULL && atual->dado.cont == info.cont && strcmp(atual->dado.palavra, info.palavra) < 0){
            ant = atual;
            atual = atual->prox;
        }
        
        if(atual == *li){ //insere início
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = atual;
            ant->prox = no;
        }
        return;
    }
}

void imprime_lista(Lista* li, int res){
    if(li == NULL){
        return;
    }
    Elem* no = *li;
    while(no != NULL && no->dado.cont >= res){
        printf("%s %d\n",no->dado.palavra,no->dado.cont);
        no = no->prox;
    }
}

void transfere_dados(Lista* li, ArvAVL* raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        transfere_dados(li, &((*raiz)->esq));
        insere_lista_ord_decres(li, (*raiz)->info);
        transfere_dados(li, &((*raiz)->dir));
    }
    return;
}