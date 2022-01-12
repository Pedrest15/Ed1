#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvbin.h" //inclui os Protótipos

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%s %d\n",(*raiz)->info.nome, (*raiz)->info.bit);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void insere_circuito(ArvBin* raiz, tipo_dado valor, int *flag){
    if(raiz == NULL)
        return;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL){
        *raiz = novo;
    } else {
        struct NO** atual = raiz;
        int achou = 0;
        atual = Procura_preOrdem_ArvBin(raiz, novo->info.pai, &achou);
        
        if(achou){
            if(strcmp(novo->info.posicao, "L") == 0){
                if((*atual)->esq == NULL){
                    (*atual)->esq = novo;
                } else { //nodo ja tava preenchido
                    *flag = 0;
                }
            } else if(strcmp(novo->info.posicao, "U") == 0){
                if((*atual)->dir == NULL){
                    (*atual)->dir = novo;
                } else { //nodo ja tava preenchido
                    *flag = 0;
                }
            } else if(strcmp(novo->info.posicao, "R") == 0){
                if((*atual)->dir == NULL){
                    (*atual)->dir = novo;
                } else { //nodo ja tava preenchido
                    *flag = 0;
                }
            }
        }else{ //nodo pai nao encontrado
            *flag = 0;
        }
    }
    return;
}

struct NO** Procura_preOrdem_ArvBin(ArvBin *raiz, char pai[], int *achou){
    if(raiz == NULL)
        return NULL;
    
    struct NO** retornar;

    if(*raiz != NULL){
        if (!strcmp(pai, (*raiz)->info.nome)){
            *achou=1;
            return raiz;
        }
        retornar = Procura_preOrdem_ArvBin(&((*raiz)->esq), pai, achou);
        if(*achou) return retornar;
        retornar = Procura_preOrdem_ArvBin(&((*raiz)->dir), pai, achou);
        if(*achou) return retornar;
    }
}

void insere_bit(ArvBin* raiz, char entrada_nome[], int entrada_bit, int *flag2){
    struct NO** atual = raiz;
    int achou = 0;
    atual = Procura_preOrdem_ArvBin(raiz, entrada_nome, &achou);
    if(achou){
        (*atual)->info.bit = entrada_bit;
    } else { // caso o usuario digite um INP que nao tem no circuito
        *flag2 = 0;
    }
}

int calcula_bit(ArvBin *raiz){
    if(*raiz != NULL){
        if (!strncmp("OUT", (*raiz)->info.nome, 3)){
            (*raiz)->info.bit = calcula_bit(&(*raiz)->dir);
            return (*raiz)->info.bit;
        }else if (!strncmp("AND", (*raiz)->info.nome, 3)){
            (*raiz)->info.bit = calcula_bit(&(*raiz)->esq) && calcula_bit(&(*raiz)->dir);
            return (*raiz)->info.bit;
        } else if(!strncmp("OR", (*raiz)->info.nome, 2)){
            (*raiz)->info.bit = calcula_bit(&(*raiz)->esq) || calcula_bit(&(*raiz)->dir);
            return (*raiz)->info.bit;
        } else if(!strncmp("XOR", (*raiz)->info.nome, 3)){
            (*raiz)->info.bit = calcula_bit(&(*raiz)->esq) ^ calcula_bit(&(*raiz)->dir);
            return (*raiz)->info.bit;
        } else if(!strncmp("NOT", (*raiz)->info.nome, 3)){
            (*raiz)->info.bit = !calcula_bit(&(*raiz)->dir);
            return (*raiz)->info.bit;
        } else if(!strncmp("INP", (*raiz)->info.nome, 3)){
            return (*raiz)->info.bit;
        }
    }
}

int verifica_arvore(ArvBin *raiz, int x){//olha se a arvore ficou incompleta
     if(*raiz != NULL){
        if (!strncmp("OUT", (*raiz)->info.nome, 3)){
            if ((*raiz)->dir == NULL){
                return 0;
            } else {
                return (x && verifica_arvore(&(*raiz)->dir, x));
            }
        }else if (!strncmp("AND", (*raiz)->info.nome, 3)){
            if ((*raiz)->esq == NULL || (*raiz)->dir == NULL){
                return 0;
            } else {
                x = x && verifica_arvore(&(*raiz)->esq, x);
                x = x && verifica_arvore(&(*raiz)->dir, x);
                return x;
            }
        } else if(!strncmp("OR", (*raiz)->info.nome, 2)){
            if((*raiz)->esq == NULL || (*raiz)->dir == NULL){
                return 0;
            } else {
                x = x && verifica_arvore(&(*raiz)->esq, x);
                x = x && verifica_arvore(&(*raiz)->dir, x);
                return x;
            }
        } else if(!strncmp("XOR", (*raiz)->info.nome, 3)){
            if((*raiz)->esq == NULL || (*raiz)->dir == NULL){
                return 0;
            } else {
                x = x && verifica_arvore(&(*raiz)->esq, x);
                x = x && verifica_arvore(&(*raiz)->dir, x);
                return x;
            }
        } else if(!strncmp("NOT", (*raiz)->info.nome, 3)){
            if ((*raiz)->dir == NULL){
                return 0;
            } else {
                return (x && verifica_arvore(&(*raiz)->dir, x));
            }
        } else if(!strncmp("INP", (*raiz)->info.nome, 3)){
            return 1;
        }
    }
}