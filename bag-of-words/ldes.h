#ifndef __LDES_H__
#define __LDES_H__

#include "avravl.h"

typedef struct{
    char palavra[20];
    int cont;
} Tipo_Dado;

//Definição do tipo lista
struct elemento{
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
void insere_lista_ord_decres(Lista* li, tipo_dado info);
void imprime_lista(Lista* li, int res);
void transfere_dados(Lista* li, ArvAVL* raiz);

#endif