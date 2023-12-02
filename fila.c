#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*cria fila vazia. se falhar retorna NULL*/
struct fila *fila_cria (){

	struct fila *nova = (struct fila *) malloc (sizeof (struct fila ));

	if (!nova)
		return NULL;

	nova->ini = NULL;
	nova->fim = NULL;
	nova->tamanho = 0;
	
	return nova;
}

/*destroi fila, liberando espaço dos componentes*/
void fila_destroi (struct fila **f){
	
      while ((*f)->ini != NULL) {
        struct nodo *temp = (*f)->ini;
        (*f)->ini = (*f)->ini->prox;
        free(temp);
      }
      free(*f);
      *f = NULL;
}

/*insere FIFO*/
int enqueue (struct fila *fila, int dado){
	
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

	if (!novo)
		return 0;

	novo->chave = dado;
	novo->prox = NULL;

	//se fila esta vazia
	if (fila->fim == NULL){
		fila->ini = novo;
		fila->fim = novo;
	} 
	//insere no fim
	else {
		fila->fim->prox = novo;
		fila->fim = novo;
	}

	(fila->tamanho)++;
	return 1;
}

/*retira FIFO*/
int dequeue (struct fila *fila, int *dado){
	
	if (fila == NULL || fila_vazia(fila))
		return 0;

	//devolve elemento retirado. atualiza inicio da fila. libera espaço do nodo
	struct nodo *temp = fila->ini;
	*dado = temp->chave;
	fila->ini = fila->ini->prox;
	free(temp);

	if (fila->ini == NULL)
		fila->fim = NULL;

	(fila->tamanho)--;
	return 1;
}

/*devolve tamanho da fila*/
int fila_tamanho (struct fila *fila){
	return fila->tamanho;
}

/*verifica fila vazia*/
int fila_vazia (struct fila *fila){
	return fila->ini == NULL;
}

/*imprime fila no formato pedido*/
void fila_imprime (struct fila *fila){

	struct nodo *aux = fila->ini;

	printf("[ ");
	while (aux != NULL){
		printf("%d ", aux->chave);
		aux = aux->prox;
	}
	printf("]\n");
}
