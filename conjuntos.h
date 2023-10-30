typedef struct lista{
	int conteudo;
	struct lista* prox;
} Lista;

void insere (int x, Lista **l);

void imprime (Lista* l);

int existe (Lista *l, int x);

int contem (Lista *la, Lista *lb);

int igual (Lista *la, Lista *lb);

int duplicado (Lista *la, Lista *lb);

int uniao (Lista *la, Lista *lb, Lista **lu);

int interseccao (Lista *la, Lista *lb, Lista **li);

void libera_lista(Lista *l);
