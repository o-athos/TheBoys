#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void insere (int x, Lista **l){

	Lista *novo = (Lista *) malloc (sizeof(Lista));
	novo -> conteudo = x;
	novo -> prox = *l;
	*l = novo;
}

void imprime (Lista *l){

	if (l != NULL) {
		printf("%d ", l->conteudo);
		imprime(l->prox);
	}
}

int existe (Lista *l, int x){
	
	Lista *temp = l;

	while (temp != NULL){
		if (temp->conteudo == x)
			return 1;
		temp = temp->prox;
	}
	return 0;
}

int contem (Lista *la, Lista *lb){
	
	Lista *temp1 = la;
	Lista *temp2 = lb;

	while (temp2 != NULL){
		if (!existe(la, temp2->conteudo))
			return 0;
		temp2 = temp2->prox;
		temp1 = temp1->prox;
	}
	
	if (temp1 == NULL && temp2 != NULL)
		return 0;
	
	return 1;
}		

int igual (Lista *la, Lista *lb){
	
	Lista *temp1 = la;
	Lista *temp2 = lb;

	while (temp1 != NULL && temp2 != NULL){
		if (!existe(lb, temp1->conteudo))
			return 0;
		temp1 = temp1->prox;
		temp2 = temp2->prox;
	}
	
	if ((temp1 == NULL) ^ (temp2 == NULL))
		return 0;
	
	return 1;
}

// int duplicado (Lista *l){
	
	

	



int uniao (Lista *la, Lista *lb, Lista **lu){

	Lista *temp1 = la;

	while (temp1 != NULL){
		if (!existe (*lu, temp1->conteudo)){
			insere(temp1->conteudo, lu);
		}
		temp1 = temp1->prox;
	}

	Lista *temp2 = lb;
	
	while (temp2 != NULL){
		if (!existe(*lu, temp2->conteudo)){
			insere (temp2->conteudo, lu);
		}
		temp2 = temp2->prox;
	}
	
	return 1;
}

int interseccao (Lista *la, Lista *lb, Lista **li){
	
	Lista *temp1 = la;
	Lista *temp2 = lb;

	if (igual(la, lb)){
		*li = temp1;
		return 1;
	}

	if (contem (la, lb)){
		*li = temp2;
		return 1;
	}

	if (contem(lb, la)){
		*li = temp1;
		return 1;
	}	

	while ((temp1 != NULL) && (temp2 != NULL)){
		if (existe(temp1, temp2->conteudo)){
			if (!existe(*li, temp2->conteudo))
				insere (temp2->conteudo, li);
		}
		
		temp2 = temp2->prox;
	}

	return 1;
}


void libera_lista (Lista *l){
	
	Lista* atual = l;
	Lista* proximo;

	while (atual != NULL){
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
}
	
