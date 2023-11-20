#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

struct conjunto *cria_cjt (int max){
	struct conjunto *c = malloc (sizeof(struct conjunto));

	if (!c)
		return NULL;

	c->card = 0;
	c->ptr = 0;
	c->max = max;
	c->v = (int *) malloc(max * sizeof(int));
	if (!c->v){
		free(c);
		return NULL;
	}

	return c;
}

struct conjunto *destroi_cjt (struct conjunto *c){
	free (c->v);
	free(c);
	return NULL;
}

int vazio_cjt (struct conjunto *c){
    return (cardinalidade_cjt(c) == 0);   	
}

int cardinalidade_cjt (struct conjunto *c){
	return c->card;
}

int insere_cjt (struct conjunto *c, int elemento){

	if (c->card >= c->max)
		return 0;

	if (pertence_cjt(c, elemento))
			return 1;
	
	int i = 0;
    while (i < c->card && c->v[i] < elemento)
        i++;
    
    for (int j = c->card; j > i; j--) 
        c->v[j] = c->v[j - 1];
    

    c->v[i] = elemento;
    c->card++;
    return 1; 
}

int retira_cjt (struct conjunto *c, int elemento){

	if (vazio_cjt(c))
		return 0;
	
	for (int i = 0; i < c->card; i++){
		if (c->v[i] == elemento){
			for (int j = i; j < c->card - 1; j++){
				c->v[j] = c->v[j+1];
			}
			c->card--;
			return 1;
		}
	}
	return 0;
}	

int pertence_cjt (struct conjunto *c, int elemento){
	
	if (vazio_cjt(c))
		return 0;
	
	for (int i = 0; i < c->card; i++){
		if (c->v[i] == elemento) 
			return 1;
	}
	return 0;
}

int contido_cjt (struct conjunto *c1, struct conjunto *c2){

	for (int i = 0; i < c1->card; i++){
		if (!pertence_cjt(c2, c1->v[i]))
			return 0;
	}
	return 1;

}

int sao_iguais_cjt (struct conjunto *c1, struct conjunto *c2){

	if (cardinalidade_cjt(c1) != cardinalidade_cjt(c2))
		return 0;

	for (int i = 0; i < c1->card; i++){
		if (!pertence_cjt (c2, c1->v[i]))
			return 0;
	}
	return 1;
}

struct conjunto *diferenca_cjt(struct conjunto *c1, struct conjunto *c2) {
    struct conjunto *resultado = cria_cjt(c1->max);
    if (resultado == NULL) {
        return NULL; 
    }

    for (int i = 0; i < c1->card; i++) {
        if (!pertence_cjt(c2, c1->v[i])) {
            insere_cjt(resultado, c1->v[i]);
        }
    }

    return resultado;
}

struct conjunto *interseccao_cjt(struct conjunto *c1, struct conjunto *c2) {
    struct conjunto *resultado = cria_cjt(c1->max);
    if (resultado == NULL) {
        return NULL; 
    }

    for (int i = 0; i < c1->card; i++) {
        if (pertence_cjt(c2, c1->v[i])) {
            insere_cjt(resultado, c1->v[i]);
        }
    }

    return resultado;
}
	

struct conjunto *uniao_cjt(struct conjunto *c1, struct conjunto *c2) {
    struct conjunto *resultado = cria_cjt(c1->max + c2->max);
    if (resultado == NULL) {
        return NULL; // Falha na alocação de memória para o conjunto resultado
    }

    for (int i = 0; i < c1->card; i++) {
        insere_cjt(resultado, c1->v[i]);
    }

    for (int i = 0; i < c2->card; i++) {
        insere_cjt(resultado, c2->v[i]);
    }

    return resultado;
}

struct conjunto *copia_cjt(struct conjunto *c) {
    struct conjunto *copia = cria_cjt(c->max);
    if (copia == NULL) {
        return NULL; // Falha na alocação de memória para o conjunto cópia
    }

    for (int i = 0; i < c->card; i++) {
        insere_cjt(copia, c->v[i]);
    }

    return copia;
}

struct conjunto *cria_subcjt_cjt (struct conjunto *c, int n){
	
	  struct conjunto *subcjt = copia_cjt(c);

	  
 	  while (subcjt->card > n) {
    	 int idx = rand() % (subcjt->card);
    	 retira_cjt (subcjt, subcjt->v[idx]);
  	  }

      return subcjt;
}

void imprime_cjt(struct conjunto *c){
	
	printf("[");
	for (int i = 0; i < c->card; i++) {
		printf(" %d", c->v[i]);
		if (i < c->card - 1)
			printf(" ");
	}
	printf(" ]\n");
}

void inicia_iterador_cjt (struct conjunto *c){
	c->ptr = 0;
}

int incrementa_iterador_cjt (struct conjunto *c, int *ret_iterador){
	if (c->ptr >= c->card || c->card == 0)
		return 0;

	*ret_iterador = c->v[c->ptr];
	c->ptr++;
	return 1;
}

int retira_um_elemento_cjt (struct conjunto *c){
	if (!vazio_cjt(c)) {
    	int elemento = c->v[0];
    	retira_cjt(c, elemento);
    	return elemento;
 	}
	return -1; 
}









	
	
