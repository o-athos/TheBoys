#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

/*cria conjunto. retorna NULL se falhar*/
struct conjunto *cria_cjt (int max){
	struct conjunto *c = malloc (sizeof(struct conjunto));

	if (!c)
		return NULL;

	//inicializa componentes
	c->card = 0;
	c->max = max;
	c->v = (int *) malloc(max * sizeof(int));
	if (!c->v){
		free(c);
		return NULL;
	}

	return c;
}

/*destroi conjunto liberando espaço*/
struct conjunto *destroi_cjt (struct conjunto *c){
	free (c->v);
	free(c);
	return NULL;
}

/*verifica se conjunto vazio*/
int vazio_cjt (struct conjunto *c){
    return (cardinalidade_cjt(c) == 0);   	
}

/*devolve o tamanho do conjunto*/
int cardinalidade_cjt (struct conjunto *c){
	return c->card;
}

/*insere no conjunto ordenado*/
int insere_cjt (struct conjunto *c, int elemento){

	if (c->card >= c->max)
		return 0;

	if (pertence_cjt(c, elemento))
			return 1;
	
	//acha a posição para colocar o elemento
	int i = 0;
    while (i < c->card && c->v[i] < elemento)
        i++;
    
	//abre espaço
    for (int j = c->card; j > i; j--) 
        c->v[j] = c->v[j - 1];
    
	//insere e incrementa o tamanho do conjunto
    c->v[i] = elemento;
    c->card++;
    return 1; 
}

/*retira o elemento passado na chamada do conjunto*/
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

/*verifica se um elemento está num conjunto c*/
int pertence_cjt (struct conjunto *c, int elemento){
	
	if (vazio_cjt(c))
		return 0;
	
	for (int i = 0; i < c->card; i++){
		if (c->v[i] == elemento) 
			return 1;
	}
	return 0;
}

/*verifica se conjunto c1 está contido no c2*/
int contido_cjt (struct conjunto *c1, struct conjunto *c2){

	for (int i = 0; i < c1->card; i++){
		if (!pertence_cjt(c2, c1->v[i]))
			return 0;
	}
	return 1;

}

/*verifica se o conjunto c1 eh igual ao c2*/
int sao_iguais_cjt (struct conjunto *c1, struct conjunto *c2){

	if (cardinalidade_cjt(c1) != cardinalidade_cjt(c2))
		return 0;

	for (int i = 0; i < c1->card; i++){
		if (!pertence_cjt (c2, c1->v[i]))
			return 0;
	}
	return 1;
}

/*retorna um conjunto intersecção entre os conjuntos c1 e c2*/
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
	

/*retorna um conjunto união entre c1 e c2*/
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

/*imprime o conjunto no formato [ a b c d ]*/
void imprime_cjt(struct conjunto *c){
	
	printf("[");
	for (int i = 0; i < c->card; i++) {
		printf(" %d", c->v[i]);
		if (i < c->card - 1)
			printf(" ");
	}
	printf(" ]\n");
}	
