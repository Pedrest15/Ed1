#include <stdio.h>
#include <stdlib.h>

#include "ldes.h"

void merge_listas(int num_listas, Lista* li, Lista* lista_final){ //transfere os valores das listas de entrada	
	while((*li)->dado != 0.0){                                    //dos tipos 1 e 2 para a lista final                          
		insere_lista_ordenada(lista_final, (*li)->dado);
		remove_lista_inicio(li);
	}
	libera_lista(li);
}

void merge_inverso_listas(int num_listas, Lista* li, Lista* lista_final){ //transfere os valores das listas de                                 
	while((*li)->dado != 0.0){                                            //entrada do tipo 3 para a lista final                               
		insere_lista_ordenada_inversa(lista_final, (*li)->dado);
		remove_lista_inicio(li);
	}
	libera_lista(li);
}

int main(void){
    int tipo_entrada;
    int num_listas;
	float valores_entrada;

    Lista* li[4];
    Lista* lista_final;

    scanf("%d", &tipo_entrada);
    scanf("%d", &num_listas);

    for(int i = 0; i < num_listas; i++){
        li[i] = cria_lista();
    }
    lista_final = cria_lista();

    if (tipo_entrada == 1){ //valores ja ordenados
        for(int i = 0; i < num_listas; i++){ //recebe os valores das listas
            while(1){
                scanf("%f", &valores_entrada);
                insere_lista_final(li[i], valores_entrada);
                if (valores_entrada == 0.0){ //0 demarca o fim da lista
                    break;
                }
            }
        }
    } else if(tipo_entrada == 2){ //valores precisam ser ordenados
        for(int i = 0; i < num_listas; i++){ //recebe os valores das listas
            while(1){
                scanf("%f", &valores_entrada);
                if (valores_entrada != 0){
                    insere_lista_ordenada(li[i], valores_entrada);
                } else {
                    insere_lista_final(li[i], valores_entrada);
					break;
                }
            }
        }
    } else if(tipo_entrada == 3){ //valores precisam ser ordenados de forma inversa
		for(int i = 0; i < num_listas; i++){ //recebe os valores das listas
            while(1){
                scanf("%f", &valores_entrada);
                if (valores_entrada != 0){
                    insere_lista_ordenada_inversa(li[i], valores_entrada);
                } else {
                    insere_lista_final(li[i], valores_entrada);
					break;
                }
            }
        }
    }

	for(int i = 0; i < num_listas; i++){
		if (tipo_entrada == 1 || tipo_entrada == 2){
			merge_listas(num_listas, li[i], lista_final);
		} else if (tipo_entrada == 3){
			merge_inverso_listas(num_listas, li[i], lista_final);
		}
	}

    imprime_lista(lista_final);
    libera_lista(lista_final);

    return 0;
}