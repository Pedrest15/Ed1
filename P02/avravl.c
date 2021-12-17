#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avravl.h" //inclui os Protótipos

ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
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

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int altura_NO(struct NO* no){
    if(no == NULL){
        return -1;
    } else {
        return no->altura;
    }
}

int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y){
    if(x > y){
        return x;
    } else {
        return y;
    }
}

int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d %d %s %s\n", (*raiz)->info.cep_ini, (*raiz)->info.cep_fin, 
                                (*raiz)->info.cidade, (*raiz)->info.estado);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("%d %d %s %s\n",(*raiz)->info.cep_ini,(*raiz)->info.cep_fin,
                               (*raiz)->info.cidade, (*raiz)->info.estado);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d %d %s %s\n", (*raiz)->info.cep_ini, (*raiz)->info.cep_fin,
                                (*raiz)->info.cidade, (*raiz)->info.estado);
    }
}

void consulta_cep_ArvAVL(ArvAVL *raiz, int cep){
    if(raiz == NULL)
        return;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(cep >= atual->info.cep_ini && cep <= atual->info.cep_fin){
            printf("%d %d %s %s\n", atual->info.cep_ini, atual->info.cep_fin,
                                    atual->info.cidade, atual->info.estado);
            return;
        }
        if(cep > atual->info.cep_ini && cep > atual->info.cep_fin){
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }
    }
    printf("FAIL\n");
}

void RotacaoLL(ArvAVL *A){//LL
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(ArvAVL *A){//RR
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(ArvAVL *A){//LR
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A){//RL
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL *raiz, tipo_dado valor, int *flag){
    int res;
    if(*raiz == NULL){//árvore vazia ou nó folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo->info.cep_ini = valor.cep_ini;
        novo->info.cep_fin = valor.cep_fin;
        strcpy(novo->info.cidade, valor.cidade);
        strcpy(novo->info.estado, valor.estado);
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(valor.cep_ini < atual->info.cep_ini && valor.cep_fin < atual->info.cep_fin){
        if((res = insere_ArvAVL(&(atual->esq), valor, flag)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(valor.cep_ini < (*raiz)->esq->info.cep_ini && valor.cep_ini < (*raiz)->esq->info.cep_fin){
                    RotacaoLL(raiz);
                } else {
                    RotacaoLR(raiz);
                }
            }
        }
    } else {
        if(valor.cep_ini > atual->info.cep_ini && valor.cep_fin > atual->info.cep_fin){
            if((res = insere_ArvAVL(&(atual->dir), valor, flag)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if((*raiz)->dir->info.cep_ini < valor.cep_ini && (*raiz)->dir->info.cep_fin < valor.cep_fin){
                        RotacaoRR(raiz);
                    } else {
                        RotacaoRL(raiz);
                    }
                }
            }
        } else { //valor duplicado ou sobreposto
            printf("ERROR\n");
            *flag = 0;
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}

struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}