#include "conjunto.h"
#include "fila.h"
#include "lef.h"

#define T_INICIO 0
#define T_FIM_DO_MUNDO 525600
#define N_TAMANHO_MUNDO 20000
#define N_HABILIDADES 10
#define N_HEROIS (N_HABILIDADES * 5)
#define N_BASES (N_HEROIS / 6)
#define N_MISSOES (T_FIM_DO_MUNDO / 100)


#define CHEGA 1
#define ESPERA 2
#define DESISTE 3
#define AVISA 4
#define ENTRA 5
#define SAI 6
#define VIAJA 7
#define MISSAO 8
#define FIM 9


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

    int relogio;
        
    int cumpridas;
        
    int tentativas;
        
	struct heroi* herois[N_HEROIS];

	struct base* bases[N_BASES];

	struct missao* missoes[N_MISSOES];

	struct coordenadas mundo;
};


int aleat (int min, int max);

//inicializações
struct mundo* cria_mundo ();
void destroi_mundo (struct mundo *m);
void inicializa_mundo (struct mundo *m);
void imprime_mundo (struct mundo *m);
struct heroi* cria_heroi (int id);
void inicializa_herois (struct mundo *m);
void destroi_herois (struct mundo *m);
void imprime_heroi (struct heroi *h);
struct base* cria_base (int id);
void inicializa_bases (struct mundo *m);
void destroi_bases (struct mundo *m);
void imprime_base (struct base *b);
struct missao* cria_missao (int id);
void inicializa_missoes (struct mundo *m);
void destroi_missoes (struct mundo *m);
void imprime_missao (struct missao *m);
void eventos_iniciais (struct mundo *m, struct lef_t *LEF);

//eventos
void chega (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF);
void espera (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF);
void desiste (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF);
void avisa (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF);
void entra (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF);
void sai (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF);
void viaja (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF);
void missao (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF);
void fim (int tempo, struct mundo *m);
