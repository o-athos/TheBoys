#include "conjunto.h"
#include "fila.h"
#include "lef.h"

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
};

struct heroi {
	int id;
	struct conjunto *hab;
	int paciencia;
	int velocidade;
	int xp;
	int id_base;
};

struct base {
	int id;
	int lotacao;
	struct conjunto *presentes;
	struct fila *espera;
	struct coordenadas coord;
};

struct missao {
	int id;
	struct conjunto *hab_necessarias;
	struct coordenadas coord;
};

struct mundo {

	int n_herois;
	struct heroi *herois;

	int n_bases;
	struct base *bases;

	int n_missoes;
	struct missao *missoes;

	int n_habilidades;
	struct coordenadas mundo;
};


int aleat (int min, int max);

//inicializações
void inicializa_herois (struct mundo *m);
void inicializa_bases (struct mundo *m);
void inicializa_missoes (struct mundo *m);
void eventos_iniciais (struct mundo *m);

//eventos
void chega (int tempo, struct heroi *h, struct base *b);
void espera (int tempo, struct heroi *h, struct base *b);
void desiste (int tempo, struct heroi *h, struct base *b);
void avisa (int tempo, struct base *b);
void entra (int tempo, struct heroi *h, struct base *b);
void sai (int tempo, struct heroi *h, struct base *b);
void viaja (int tempo, struct heroi *h, struct base *b);
void missao (int tempo, struct mundo *m);
void fim (int tempo);


















