#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void inicializa_lista (LISTA *l){
	
	l->primeiro = NULL;
	l->ultimo = NULL;
}


int cria_evento (NODO **novo, int data){
	

	if ((*novo = (NODO*) malloc (sizeof (NODO))) == NULL){
			printf("erro ao alocar memoria \n");
			return 1;
	}

	(*novo)->tempo = data;
	(*novo)->prox = NULL;
	
	return 0;
}

void insere_ordenado (LISTA **l, int data_evento){

	NODO *novo, *aux, *anterior;
	
	if (cria_evento (&novo, data_evento))
		return;
	

	aux = (*l)->primeiro;
	anterior = NULL;

	while (aux != NULL && novo->tempo > aux->tempo) {
		anterior = aux;
		aux = aux->prox;
	}

	novo->prox = aux;	
	if (anterior == NULL){    //se a lista eh vazia
		(*l)->primeiro = novo;
	}
	else{
		anterior->prox = novo;
	}

	if (novo->prox == NULL){
		(*l)->ultimo = novo;
	}

}


	
void retira_da_agenda (LISTA **l){

	if ((*l)->primeiro == NULL){
		printf("erro: retirar de pilha vazia???\n");
		return;
	}

	NODO* temp = (*l)->primeiro;

	(*l)->primeiro = temp->prox;

	if ((*l)->primeiro == NULL)
		(*l)->primeiro = NULL;

	free(temp);
}

void imprime(LISTA *l){
	
	NODO *aux = l->primeiro;

	while (aux != NULL){
		printf("%d ", aux->tempo);
		aux = aux->prox;
	}
}


void libera_lista (LISTA *l){
	
	NODO* aux = l->primeiro;
	
	while (aux != NULL){
		free(aux);
		aux = aux->prox;
	}
}


	
	

