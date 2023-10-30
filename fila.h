#define MAX 100
#include <stdbool.h>

struct fila {
	int fim;
	int v[MAX];
};


void enfileira (struct fila *f, int membro);

int desenfileira (struct fila *f, int *membro);

bool fila_cheia (struct fila *f);

bool fila_vazia (struct fila *f);

bool ve_inicio (struct fila *f, int *membro);

void inverter_fila (struct fila *f);

