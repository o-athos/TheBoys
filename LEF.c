#include <stdio.h>
#include "LEF.h"

struct evento_t *cria_evento (int tempo, int tipo, int dado1, int dado2){
	
	struct evento_t *novo = malloc (sizeof evento_t);

	if (!novo)
		return NULL;

	novo.tempo = tempo;
	novo.tipo = tipo;
	novo.dado1 = dado1;
	novo.dado2 = daod2;
	
	return novo;
}

struct evento_t *destroi_evento (struct evento_t *e){

	free(e);
	return NULL;
}

struct *cria_lef (){
	
	struct lef_t *l = malloc (sizeof lef_t);
	
	if (!l)
		return NULL;
	
	return l;
}

struct lef_t *destroi_lef (struct lef_t *l){
	
	struct nodo_lef_t *aux = l->primeiro;

	while (aux != NULL){
		free(


}

int insere_lef (struct lef_t *l, struct evento_t *e){

	

	
	

