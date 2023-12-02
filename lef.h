#ifndef _LEF_H
#define _LEF_H

/* evento_t abrange os dados que caracterizam o evento*/
struct evento_t {
    int tempo;  /* tempo logico do evento */
    int tipo;   /* inteiro para diferenciar os diferentes tipos de evento */
    int dado1;  /* um inteiro para guardar dados do evento */
    int dado2;  /* um inteiro para guardar dados do evento */
};

/*nodo da lef com ponteiro pro prox e pro evento na posição*/
struct nodo_lef_t {
    struct evento_t   *evento;
    struct nodo_lef_t *prox;
} ;

/* a lef em si*/
struct lef_t {
    struct nodo_lef_t *primeiro;
};

/*cria evento com os parâmetros passados*/
struct evento_t *cria_evento (int tempo, int tipo, int dado1, int dado2);

/* Destroi um evento*/
struct evento_t *destroi_evento (struct evento_t *e);

/*cria uma LEF vazia*/ 
struct lef_t *cria_lef ();

/*destroi a lef e tudo que ela abrange*/
struct lef_t *destroi_lef (struct lef_t *l);

/*insere o evento na lef baseando-se no seu tempo*/
int insere_lef (struct lef_t *l, struct evento_t *e);

/*retira o primeiro evento da lef.*/
struct evento_t *retira_lef (struct lef_t *l);

/*verifica se lef vazia*/ 
int vazia_lef (struct lef_t *l);

/*imprime a lef em ordem com seus atributos*/ 
void imprime_lef (struct lef_t *l);

#endif
