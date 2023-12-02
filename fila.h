struct nodo {
    int chave;
    struct nodo *prox;
};

struct fila {
    struct nodo *ini;
    struct nodo *fim;
    int tamanho;
};

/*cria uma nova fila vazia*/
struct fila *fila_cria ();

/* libera a memoria da fila */
void fila_destroi (struct fila **fila);

/* insere na fila no fim (FIFO)*/
int enqueue (struct fila *fila, int dado);

/* retira da fila o primeiro (FIFO)*/
int dequeue (struct fila *fila, int *dado);

/*devolve o tamanho da fila*/
int fila_tamanho (struct fila *fila);

/* verifica se fila vazia */ 
int fila_vazia (struct fila *fila);

/*imprime fila */
void fila_imprime (struct fila *fila);
