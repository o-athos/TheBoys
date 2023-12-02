struct conjunto {
    int max;    /* tamanho maximo do vetor    */
    int card;   /* tamanho do conjunto  */
    int *v;     /* vetor de inteiros  */
};

/* cria conjunto com tamanho delimitado por max*/
struct conjunto *cria_cjt (int max);

/* libera o espaço do conjunto*/
struct conjunto *destroi_cjt (struct conjunto *c);

/*verifica se conjunto vazio*/
int vazio_cjt (struct conjunto *c);

/*retorna o tamanho do conjunto*/
int cardinalidade_cjt (struct conjunto *c);

/*insere elemento no conjunto se não for repetido. insere ordenado*/
int insere_cjt (struct conjunto *c, int elemento);

/*remove o elemento do conjunto*/
int retira_cjt (struct conjunto *c, int elemento);

/*verifica se o elemento está no conjunto*/
int pertence_cjt (struct conjunto *c, int elemento);

/*verifica se c1 está em c2*/
int contido_cjt (struct conjunto *c1, struct conjunto *c2);

/*verifica se c1 eh igual a c2*/
int sao_iguais_cjt (struct conjunto *c1, struct conjunto *c2);

/*retorna um conjunto intersecção entre c1 e c2*/
struct conjunto *interseccao_cjt (struct conjunto *c1, struct conjunto *c2);

/*retorna conjunto união entre c1 e c2*/
struct conjunto *uniao_cjt (struct conjunto *c1, struct conjunto *c2);

/*imprime conjunto*/
void imprime_cjt (struct conjunto *c);
