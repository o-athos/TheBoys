typedef struct nodo {
	int tempo;
	struct nodo* prox;
} NODO;

typedef struct lista {
	struct nodo* primeiro;
	struct nodo* ultimo;
} LISTA;

void inicializa_lista (LISTA *l);

int cria_evento (NODO **novo, int data);
	
void insere_ordenado (LISTA **l, int data_evento);

void retira_da_agenda (LISTA **l);

void imprime (LISTA *l);

void libera_lista (LISTA *l);

