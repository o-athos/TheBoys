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
	
	if (e != NULL)
		free(e);
	return NULL;
}

struct *cria_lef (){
	
	struct lef_t *l = malloc (sizeof (struct lef_t));
	
	if (!l)
		return NULL;
	
	l->primeiro = NULL;
	return l;
}

struct lef_t *destroi_lef (struct lef_t *l){
	
	if (l != NULL) {
        while (l->primeiro != NULL) {
            struct nodo_lef_t *temp = l->primeiro;
            l->primeiro = l->primeiro->prox;
            destroi_evento(temp->evento);
            free(temp);
        }
        free(l);
    }
    return NULL;


}

int insere_lef (struct lef_t *l, struct evento_t *e){

	struct nodo_lef_t *novo = malloc (sizeof struct nodo_lef_t);

	if (novo == NULL)
		return;
	
	novo->evento = e;
	novo->prox = NULL;

	if (l->primeiro == NULL || novo->tempo < l->primeiro->evento->tempo){
		novo->prox = l->primeiro;
		l->primeiro = novo;
	}
	else {
		struct nodo_lef_t *aux = l->primeiro;
		while (aux->prox != NULL && novo->tempo >= aux->evento->tempo){
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}


struct evento_t *retira_lef (struct lef_t *l){
	
	    if (l == NULL || l->primeiro == NULL) {
                return NULL;
    }

    struct nodo_lef_t *primeiroNodo = l->primeiro;
    struct evento_t *eventoRetirado = primeiroNodo->evento;

    
    l->primeiro = primeiroNodo->prox;

    
    free(primeiroNodo);

    return eventoRetirado;
}	

int vazia_lef (struct lef_t *l){
	
	return (l == NULL || l->primeiro == NULL);

}

void imprime_lef (struct lef_t *l){
	
	struct nodo_lef_t *aux = l->primeiro;

	int total_eventos = 0;

	while (aux != NULL && aux->prox != NULL){
		printf("%d %d %d %d\n", aux->evento->tempo, aux->evento->tipo, aux->evento->dado1, aux->evento->dado2);
		aux = aux->prox;
		total_eventos++;
	}
	
	printf("%d ", total_eventos);
}





















		



	









			

	
