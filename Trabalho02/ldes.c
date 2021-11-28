#include <stdio.h>
#include <stdlib.h>
#include "ldes.h"  //inclui os Protótipos

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
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

void insere_lista_final(Lista* li, tipo_dado dt, int *custo){
    Elem *no;

    if (li == NULL) return;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return;

    no->dado = dt;
    no->prox = NULL;
    (*custo)++;
    if ((*li) == NULL) { //lista vazia: insere início
        *li = no;
    } else {
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
            (*custo)++;
        }
        aux->prox = no;
        (*custo)++;
    }
}

void insere_lista_inicio(Lista* li, tipo_dado dt, int *custo){
    Elem* no;

    if (li == NULL) return;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return;

    no->dado = dt;
    no->prox = (*li);
    *li = no;
    (*custo)++;
}

void insere_lista_ordx(Lista* li, tipo_dado dt, int *custo){
    if (li == NULL) return;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return;

    no->dado = dt;
    if ((*li) == NULL) { //lista vazia: insere início
        no->prox = NULL;
        *li = no;
        (*custo)++;
        return;
    } else {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dado.x < dt.x) {
            ant = atual;
            atual = atual->prox;
            (*custo)++;
        }
        while (atual != NULL && atual->dado.x == dt.x && atual->dado.y < dt.y) {
            ant = atual;
            atual = atual->prox;
            (*custo)++;
        }
        while (atual != NULL && atual->dado.x == dt.x && atual->dado.y == dt.y && atual->dado.z < dt.z) {
            ant = atual;
            atual = atual->prox;
            (*custo)++;
        }
        if (atual == *li) { //insere início
            no->prox = (*li);
            *li = no;
            (*custo)++;
        } else {
            no->prox = atual;
            ant->prox = no;
            (*custo)++;
        }
    }
}

void insere_lista_ordy(Lista* li, tipo_dado dt){
    if (li == NULL) return;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return;

    no->dado = dt;
    if ((*li) == NULL) { //lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return;
    } else {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dado.y < dt.y) {
            ant = atual;
            atual = atual->prox;
        }
        while (atual != NULL && atual->dado.y == dt.y && atual->dado.x < dt.x) {
            ant = atual;
            atual = atual->prox;
        }
        while (atual != NULL && atual->dado.y == dt.y && atual->dado.x == dt.x && atual->dado.z < dt.z) {
            ant = atual;
            atual = atual->prox;
        }
        
        if (atual == *li) { //insere início
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = atual;
            ant->prox = no;
        }
    }
}

void insere_lista_ordz(Lista* li, tipo_dado dt){
    if (li == NULL) return;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return;

    no->dado = dt;
    if ((*li) == NULL) { //lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return;
    } else {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dado.z < dt.z){
            ant = atual;
            atual = atual->prox;
        }
        while (atual != NULL && atual->dado.z == dt.z && atual->dado.x < dt.x){
            ant = atual;
            atual = atual->prox;
        }
        while (atual != NULL && atual->dado.z == dt.z && atual->dado.x == dt.x && atual->dado.y < dt.y){
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li) { //insere início
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = atual;
            ant->prox = no;
        }
    }
}

Elem* busca_lista_menorz(Lista* li, Lista* liz, int* cont){ 
    if(li == NULL)              
        return 0;
    Elem *no = *li;
    Elem *noz = *liz;
    (*cont)++;
    while(no != NULL){
        (*cont)++;
        if (no->dado.z == noz->dado.z && no->dado.x == noz->dado.x && no->dado.y == noz->dado.y){
            (*cont)++;
            return no;
        }
        no = no->prox;
    }
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("%0.5f, %0.5f, %0.5f, %hd, %hd, %hd, %d", no->dado.x, no->dado.y, no->dado.z, no->dado.r, 
                                          no->dado.g, no->dado.b, no->dado.id);
        printf("\n");
        no = no->prox;
    }
}

void imprime_pz(Lista *li_ordz){
    if(li_ordz == NULL){
        return;
    }
    Elem* no = *li_ordz;
    printf("%0.5f %0.5f %0.5f TOTAL:1", no->dado.x, no->dado.y, no->dado.z);
}

void imprime_pi(Lista *li_ini, Lista *li_ordz){
    int cont = 0;
    Elem* no = busca_lista_menorz(li_ini, li_ordz, &cont);
    printf("%0.5f %0.5f %0.5f TOTAL:%d", no->dado.x, no->dado.y, no->dado.z, cont);
}

void imprime_id(Lista *li, float id){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        if (no->dado.id == (int) id){
            printf("%0.5f, %0.5f, %0.5f, %hd, %hd, %hd, %d", no->dado.x, no->dado.y, no->dado.z, no->dado.r, 
                                                    no->dado.g, no->dado.b, no->dado.id);
            printf("\n");
        }
        no = no->prox;
    }
}

void imprime_cut(Lista *li, float num[]){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        if (no->dado.x >= num[0] && no->dado.x <= num[3] && no->dado.y >= num[1] 
         && no->dado.y <= num[4] && no->dado.z >= num[2] && no->dado.z <= num[5]){
            printf("%0.5f, %0.5f, %0.5f, %hd, %hd, %hd, %d", no->dado.x, no->dado.y, no->dado.z, no->dado.r, 
                                                    no->dado.g, no->dado.b, no->dado.id);
            printf("\n");
        }
        no = no->prox;
    }
}

void salva_em_disco(Lista *li){
    FILE *arq;
    arq = fopen("coordenadas3D.txt", "a");
    if(li == NULL){
        return;
    }
    printf("Salvando dados em disco.");
    Elem* no = *li;
    while(no != NULL){
        fprintf(arq, "%0.5f, %0.5f, %0.5f, %hd, %hd, %hd, %d", no->dado.x, no->dado.y, no->dado.z, no->dado.r, 
                                          no->dado.g, no->dado.b, no->dado.id);
        fprintf(arq,"\n");
        no = no->prox;
    }
    fclose(arq);
}