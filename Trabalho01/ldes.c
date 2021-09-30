#include <stdio.h>
#include <stdlib.h>

#include "ldes.h" 

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

void insere_lista_final(Lista* li, tipo_lista x){
    if(li == NULL)
        return;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return;
    no->dado = x;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere inicio
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
}

int insere_lista_ordenada(Lista* li, tipo_lista x){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dado = x;
    if((*li) == NULL){//lista vazia: insere inicio
        no->prox = NULL;
        *li = no;
        return 1;
    } else {
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dado < x){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    int aux = no->dado;
    if (aux == no->dado){ //lista de inteiros
        while(no != NULL){
            printf("%0.0f ", no->dado);
            no = no->prox;
        }   
    } else { //lista de decimais
        while(no != NULL){
            no->dado *= 10; //contas para truncar (sem arredondamento)
            no->dado = (int) no->dado;
            no->dado /= 10;  
            
            printf("%0.1f ", no->dado);
            no = no->prox;
        }
    }
}

int insere_lista_ordenada_inversa(Lista* li, tipo_lista x){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dado = x;
    if((*li) == NULL){//lista vazia: insere inicio
        no->prox = NULL;
        *li = no;
        return 1;
    } else {
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dado > x){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}
