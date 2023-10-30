#include <stdio.h>
#include <stdbool.h>
#include "fila.h"

void enfileira (struct fila *f, int membro){

	// verifica se ja esta cheia
	if (fila_cheia(f)){
		printf("ta cheia, n da pra entrar na fila\n");
	}

	// adiciona o membro no final da fila
	f->v[f->fim] = membro;
	f->fim++;
}

int desenfileira (struct fila *f, int* membro){
	
	// verifica se ja esta vazia
	if (fila_vazia(f)){
		printf("ta vazia, n tem oq tirar\n");
		*membro = NULL;
		return 1;
	}
		
	// retira o membro do inicio
	*membro = f->v[0];
	for (int i = 0; i < f->fim-1; i++)
		f->v[i] = f->v[i+1];
	f->fim--;

	return 0;
}

bool fila_cheia (struct fila *f){
	
	if (f->fim == MAX-1)
		return true;
	return false;
}

bool fila_vazia (struct fila *f){

	if (f->fim == 0)
		return true;
	return false;
}

bool ve_inicio (struct fila *f, int* membro){
	
	if (fila_vazia(f)){
		printf("nao tem inicio, fila vazia");
		return false;
	}
		
	*membro = f->v[0];
	return true;
}	

void inverter_fila (struct fila *f){
	struct pilha pilha;
	pilha.topo = 0;
	int elemento;

	//enfileira os elemento da fila na pilha
	while (!fila_vazia(f)){
	 	desenfileira(f, &elemento);
		empilha(&pilha, elemento);
	}

	// desempilha os elementos da pilha na fila
	while (pilha.topo > 0){
		int elemento = desempilha(&pilha);
		enfileira(f, elemento);
	}
}

