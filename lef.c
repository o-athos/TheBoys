#include <stdio.h>
#include <stdlib.h>
#include "lef.h"

struct evento_t *cria_evento (int tempo, int tipo, int dado1, int dado2){

	//cria novo evento	
	struct evento_t *novo = (struct evento_t *)malloc (sizeof (struct evento_t));

	//retorna se erro na alocaação
	if (!novo)
		return NULL;

	//inicializa atributos do evento
	novo->tempo = tempo;
	novo->tipo = tipo;
	novo->dado1 = dado1;
	novo->dado2 = dado2;
	
	return novo;
}

struct evento_t *destroi_evento (struct evento_t *e){
	
	if (e != NULL)
		free(e);
	return NULL;
}

struct lef_t *cria_lef (){
	
	//aloca espaço para a lef
	struct lef_t *l = (struct lef_t *)malloc (sizeof (struct lef_t));
	
	//trata erro de alocação
	if (!l)
		return NULL;
	
	//inicializa lista
	l->primeiro = NULL;
	return l;
}

struct lef_t *destroi_lef (struct lef_t *l){
	
		//destro os eventos da lef e posteriormente, a lef
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

/*insere ordenado na lef*/
int insere_lef (struct lef_t *l, struct evento_t *e){

	struct nodo_lef_t *novo = (struct nodo_lef_t *)malloc (sizeof (struct nodo_lef_t));

	if (novo == NULL)
		return 0;
	
	novo->evento = e;
	novo->prox = NULL;
	
	//se insere no inicio
	if (l->primeiro == NULL || novo->evento->tempo < l->primeiro->evento->tempo){
		novo->prox = l->primeiro;
		l->primeiro = novo;
	}
	//acha a posição correta seguindo a ordenação
	else {
		struct nodo_lef_t *aux = l->primeiro;
		while (aux->prox != NULL && novo->evento->tempo >= aux->prox->evento->tempo){
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
	return 1;
}

/*retira da lef e libera espaço do retirado*/
struct evento_t *retira_lef (struct lef_t *l){
	
	if (l == NULL || l->primeiro == NULL) {
                return NULL;
    }

    struct nodo_lef_t *primeiroNodo = l->primeiro;
    struct evento_t *eventoRetirado = primeiroNodo->evento;

    
    l->primeiro = l->primeiro->prox;

    
    free(primeiroNodo);

    return eventoRetirado;
}	

/*verifica se lef vazia*/
int vazia_lef (struct lef_t *l){
	
	return (l == NULL || l->primeiro == NULL);

}

/*imprime os elementos da lef ordenado*/
void imprime_lef (struct lef_t *l){
	
	struct nodo_lef_t *aux = l->primeiro;

	int total_eventos = 0;

	while (aux != NULL){
		printf("%d %d %d %d\n", aux->evento->tempo, aux->evento->tipo, aux->evento->dado1, aux->evento->dado2);
		aux = aux->prox;
		total_eventos++;
	}
	
	printf("%d \n", total_eventos);
}	
