#include <stdio.h>
#include "CONJUNTO.h"

struct conjunto *cria_conjunto (int max){
	struct conjunto *c = malloc (sizeof(struct conjunto));

	if (!c)
		return NULL;

	c->card = 0;
	c->ptr = 0;
	c->max = max;
	c->v = (int *) malloc(max * sizeof(int));
	if (c->v == NULL){
		free(c);
		return NULL;
	}

	return c;
}

struct conjunto *destroi_conjunto (struct conjunto *c){
	free (c->v);
	free(c);
	return NULL;
}

int vazio_conjunto (struct conjunto *c){
    return (cardinalidade_conjunto(c) == 0);   	
}

int cardinalidade_conjunto (struct conjunto *c){
	return c->card;
}

int insere_conjunto (struct conjunto *c, int elemento){

	if (c->card >= c->max)
		return 0;

	if (pertence_conjunto(c, elemento))
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

int retira_conjunto (struct conjunto *c, int elemento){

	if (vazio_conjunto(c))
		return;
	
	for (int i = 0; i < c->card; i++){
		if (c->v[i] = elemento){
			for (int j = i; j < c->card - 1; j++){
				c->v[j] = c->v[j+1];
			}
			c->card--;
			return 1;
		}
	}
	return 0
}	

int pertence_conjunto (struct conjunto *c, int elemento){
	
	if (vazio_conjunto(c))
		return 0;
	
	for (int i = 0; i < c->card; i++){
		if (c->v[i] == elemento) 
			return 1;
	}
	return 0;
}

int contido_conjunto (struct conjunto *c1, struct conjunto *c2){

	for (int i = 0; i < c->car; i++){
		if (!pertence_conjunto(c2, c1->v[i]))
			return 0;
	}
	return 1;

}

int iguais_conjunto (struct conjunto *c1, struct conjunto *c2){

	if (cardinalidade_conjunto(c1) != cardinaldiade_conjunto(c2))
		return 0;

	for (int i = 0; i < c1->card){
		if (!pertence_conjunto (c2, c1->v[i]))
			return 0;
	}
	return 1;
}

struct conjunto *diferenca_conjunto(struct conjunto *c1, struct conjunto *c2) {
    struct conjunto *resultado = cria_conjunto(c1->max);
    if (resultado == NULL) {
        return NULL; 
    }

    for (int i = 0; i < c1->card; i++) {
        if (!pertence_conjunto(c2, c1->v[i])) {
            insere_conjunto(resultado, c1->v[i]);
        }
    }

    return resultado;
}

struct conjunto *interseccao_conjunto(struct conjunto *c1, struct conjunto *c2) {
    struct conjunto *resultado = cria_conjunto(c1->max);
    if (resultado == NULL) {
        return NULL; 
    }

    for (int i = 0; i < c1->card; i++) {
        if (pertence_conjunto(c2, c1->v[i])) {
            insere_conjunto(resultado, c1->v[i]);
        }
    }

    return resultado;
}
	

struct conjunto *uniao_conjunto(struct conjunto *c1, struct conjunto *c2) {
    struct conjunto *resultado = cria_conjunto(c1->max + c2->max);
    if (resultado == NULL) {
        return NULL; // Falha na alocação de memória para o conjunto resultado
    }

    for (int i = 0; i < c1->card; i++) {
        insere_conjunto(resultado, c1->v[i]);
    }

    for (int i = 0; i < c2->card; i++) {
        insere_conjunto(resultado, c2->v[i]);
    }

    return resultado;
}

struct conjunto *copia_conjunto(struct conjunto *c) {
    struct conjunto *copia = cria_conjunto(c->max);
    if (copia == NULL) {
        return NULL; // Falha na alocação de memória para o conjunto cópia
    }

    for (int i = 0; i < c->card; i++) {
        insere_conjunto(copia, c->v[i]);
    }

    return copia;
}

struct conjunto *cria_subconjunto (struct conjunto *c, int n){






}

void imprime_conjunto (struct conjunto *c){
	
	printf("[");
	for (int i = 0; i < c->card; i++) {
		printf(" %d", c->v[i]);
		if (i < c->card - 1)
			printf(" ");
	}
	printf(" ]\n");
}

void inicia_iterador_conjunto (struct conjunto *c){




}

int incrementa_iterador_conjunto (struct conjunto *c, int *ret_iterador){




}

int retira_um_elemento_conjunto (struct conjunto *c){









}
	
	
