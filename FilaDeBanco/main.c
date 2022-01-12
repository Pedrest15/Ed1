#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.h"

int main(void){
    struct pessoa p[MAX];
    Lista *li = cria_lista();
	char ch;    
	int pos;
	int flag = 1;

    printf(">>> Fila de Banco!!! <<<\n\n");
    printf("Escreva o nome de 10 integrantes da fila:\n");
    
    for(int i = 0; i < MAX; i++){
        p[i].pos = i + 1;
        scanf("%s", p[i].nome);
        if (!insere_lista_final(li, p[i])){
            printf("\nNão foi possível inserir o nome.\n");
        };
    }

	printf("\nVocê deseja consultar quem está em uma certa posição da fila?[s/n]\n");
	while(flag){
		scanf("%c", &ch);
		if (ch == 's'){
			printf("Qual posição você deseja consultar?\n");
			scanf("%d", &pos);
			consulta_lista_pos(li, pos);
		} else if (ch == 'n'){
			break;
		}
	}
	printf("---------------------------------\n");

	printf("Os mesários do banco começaram o atendimento!");
	for (int i = MAX - 1; i >= 0; i--){
		printf("\nUm integrante da fila foi chamado.\n");
		remove_lista_inicio(li);
		if (i > 1){
			printf("Restam %d pessoas na fila.\n", i);
		} else if (i == 1){
			printf("Resta %d pessoa na fila.\n", i);
		} else if (i == 0){
			printf("Todos os integrantes da fila foram atendidos!\n");
			break;
		}
		printf("Deseja ver como está a fila?[s/n]\n");
		while(1){
			ch = getchar();
			if (ch == 's'){
				printf("\n");
				imprime_lista(li);
				break;
			} else if (ch == 'n'){
				break;
			}
		}
	}
	libera_lista(li);
}
