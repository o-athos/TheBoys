#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila *fila_cria (){

	struct fila *nova = (struct fila *) malloc (sizeof (struct fila ));

	if (!nova)
		return NULL;

	nova->ini = NULL;
	nova->fim = NULL;
	nova->tamanho = 0;
	
	return nova;
}

void fila_destroi (struct fila **f){
	
	 while ((*f)->ini != NULL) {
        struct nodo *temp = (*f)->ini;
        (*f)->ini = (*f)->ini->prox;
        free(temp);
	 }
     free(*f);
     *f = NULL;
}

int enqueue (struct fila *fila, int dado){
	
	struct nodo *novo = (struct nodo *)malloc(sizeof(struct nodo));

	if (!novo)
		return 0;

	novo->chave = dado;
	novo->prox = NULL;

	if (fila->fim == NULL){
		fila->ini = novo;
		fila->fim = novo;
	} 
	else {
		fila->fim->prox = novo;
		fila->fim = novo;
	}

	fila->tamanho++;
	return 1;
}

int dequeue (struct fila *fila, int *dado){
	
	if (fila_vazia(fila))
		return 0;

	*dado = fila->ini->chave;
	struct nodo *temp = fila->ini;
	fila->ini = fila->ini->prox;
	free(temp);

	if (fila->ini == NULL)
		fila->fim = NULL;

	fila->tamanho--;
	return 1;
}

int fila_tamanho (struct fila *fila){
	return fila->tamanho;
}

int fila_vazia (struct fila *fila){
	return fila->ini == NULL;
}

void fila_imprime (struct fila *fila){

	struct nodo *aux = fila->ini;

	printf("[ ");
	while (aux != NULL){
		printf("%d ", aux->chave);
		aux = aux->prox;
	}
	printf("]\n");
}

















