#include <stdio.h>
#include <stdlib.h> 
#include "funcoes.h"

int main(){

	LISTA* lista = (LISTA*)malloc(sizeof(LISTA)); // Aloca memória para a lista

    if (lista == NULL) {
        printf("Erro: Falha na alocação de memória para a lista.\n");
        return 1;
    }

	inicializa_lista (lista);

	printf("\n\t digite 1: inserir novo compromisso\t\n");
	printf("\t digite 2: remover compromisso passado\t\n");
	
	int op;
	int data;
	scanf("%d", &op);
	
	while (op != 0){
			switch (op){
				case 1:
						printf("\t digite uma data: ");
						scanf("%d", &data);
						insere_ordenado (&lista, data);
						printf(" seus compromisso estao ordenados\n");
						imprime(lista);
						printf("\n");
						break;
				case 2:
						printf("\t compromisso ja passou, removendo de sua agenda\n");
						retira_da_agenda (&lista);
						imprime(lista);
						printf("\n");
						break;
				default:
						printf("opção invalida\n");

			}

			printf("\n\t digite 0: encerrar\t\n");
			printf("\t digite 1: adicionar novo compromisso\t\n");
			printf("\t digite 2: remover compromisso que já passou\t\n");
			scanf("%d", &op);

	}

	libera_lista (lista);

	return 0;
}

						
