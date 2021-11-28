#include <stdio.h>
#include <string.h>
#include "ldes.h"

void ler_arquivo(FILE *arq, Lista *li_ordx, Lista *li_ordy, Lista *li_ordz, Lista *li_ini, Lista *li_fin, int *custox, int *custoi, int *custof){
    tipo_dado aux;
    char linha[50];

    while(1){
        fgets(linha, 50, arq);
        sscanf(linha, "%f %f %f %hd %hd %hd %d", &aux.x, &aux.y, &aux.z, &aux.r, &aux.g, &aux.b, &aux.id);
        if (aux.id == -1){
            break;
        }
        insere_lista_ordx(li_ordx, aux, custox);
        insere_lista_ordy(li_ordy, aux);
        insere_lista_ordz(li_ordz, aux);
        insere_lista_inicio(li_ini, aux, custoi);
        insere_lista_final(li_fin, aux, custof);
    }
}

void libera_todas_listas(Lista *li_ordx, Lista *li_ordy, Lista *li_ordz, Lista *li_ini, Lista *li_fin){
    libera_lista(li_ordx);
    libera_lista(li_ordy);
    libera_lista(li_ordz);
    libera_lista(li_ini);
    libera_lista(li_fin);
}

void imprime_custo(int custox, int custoi, int custof){
    printf("LX:%d LI:%d LF:%d", custox, custoi, custof);
}

int main(){
    Lista *li_ordx = cria_lista();
    Lista *li_ordy = cria_lista();
    Lista *li_ordz = cria_lista();
    Lista *li_ini = cria_lista();
    Lista *li_fin = cria_lista();
    FILE *arq;
    char comando[50];
    char str[10];
    float num[6];
    int custox = 0;
    int custoi = 0;
    int custof = 0;

    arq = fopen("dados3d.txt", "rt");
    ler_arquivo(arq, li_ordx, li_ordy, li_ordz, li_ini, li_fin, &custox, &custoi, &custof);
    fclose(arq);

    fgets(comando, 50, stdin);
    sscanf(comando, "%s %f %f %f %f %f %f", str, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    if (strcmp("LX", str) == 0){
        imprime_lista(li_ordx);
    } else if (strcmp("LY", str) == 0){
        imprime_lista(li_ordy);
    } else if (strcmp("LZ", str) == 0){
        imprime_lista(li_ordz);
    } else if (strcmp("LI", str) == 0){
        imprime_lista(li_ini);
    } else if (strcmp("LF", str) == 0){
        imprime_lista(li_fin);
    } else if (strcmp("TOT", str) == 0){
        imprime_custo(custox, custoi, custof);
    } else if (strcmp("PZ", str) == 0){
        imprime_pz(li_ordz);
    } else if (strcmp("PI", str) == 0){
        imprime_pi(li_ini, li_ordz);
    } else if (strcmp("ID", str) == 0){
        imprime_id(li_ordx, num[0]);
    } else if (strcmp("CUT", str) == 0){
        imprime_cut(li_ordx, num);
    } else if (strcmp("SAVE", str) == 0){
        salva_em_disco(li_ordx);
    }

    libera_todas_listas(li_ordx, li_ordy, li_ordz, li_ini, li_fin);
}