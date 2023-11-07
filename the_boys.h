#include "conjuntos.h"
#include "fila.h"
#include "lista_encadeada.h"

#define T_INICIO 0
#define T_FIM_DO_MUNDO 525600
#define N_TAMANHO_MUNDO 20000
#define N_HABILIDADES 10
#define N_HEROIS 50
#define N_BASES 8
#define N_MISSOES 5256


struct coordenadas {
	int x;
	int y;
}

struct heroi {
	int id;
	struct conjuntos hab;
	int paciencia;
	int velocidade;
	int xp;
	int id_base;
}

struct base {
	int id;
	int lotacao;
	struct lista presentes;
	struct fila espera;
	struct coordenadas base;
}

struct missao {
	int id;
	struct conjuntos hab_necessarias;
	struct coordenadas missao;
}

struct mundo {

	int n_herois;
	struct lista herois;

	int n_bases;
	struct lista bases;

	int n_missoes;
	struct lista missoes;

	int n_habilidades;
	struct coordenadas mundo;
}

typedef struct {
	int tempo;
	void *evento;
} Evento;

int aleat (int min, int max);

//inicializações
void inicializa_herois (struct mundo *m);
void incializa_bases (struct mundo *m);
void incializa_missoes (struct mundo *m);
void eventos_iniciais (struct mundo *m);

//eventos
void chega (int *tempo, struct* heroi, struct* base);
void espera (int *tempo, struct* heroi, struct* base);
void desiste (int *tempo, struct* heroi, struct* base);
void avisa (int *tempo, struct* base);
void entra (int *tempo, struct* heroi, struct* base);
void sai (int *tempo, struct* heroi, struct* base);
void viaja (int *tempo, struct* heroi, struct* base);
void missao (int *tempo, struct* mundo);
void fim (int *tempo);


















