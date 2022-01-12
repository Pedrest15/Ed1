#ifndef __LISTAESTATICA_H__
#define __LISTAESTATICA_H__

#define MAX 10
#define OK 1
#define ERRO 0

struct pessoa{
    char nome[30];
    int pos;
};

typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista *li);
int insere_lista_final(Lista *li, struct pessoa p);
void consulta_lista_pos(Lista *li, int pos);
void remove_lista_inicio(Lista *li);
void imprime_lista(Lista *li);
void consulta_nome(Lista *li, int pos);

#endif