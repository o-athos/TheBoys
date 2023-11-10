#include "the_boys.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int aleat (int min, int max){
	return (rand () % (max - min + 1)) + min;
}

struct mundo* cria_mundo() {

	struct mundo *m = malloc(sizeof(struct mundo));
	if (m == NULL)
		return NULL;

	inicializa_herois(m);
	inicializa_bases(m);
	inicializa_missoes(m);
	m->relogio = 0;

	return m;
}

void destroi_mundo(struct mundo *m) {
    // Libere memória alocada para os vetores e, em seguida, para a estrutura mundo
    free(m->herois);
    free(m->bases);
    free(m->missoes);
    // Libere o vetor de habilidades se alocado dinamicamente
    // free(m->habilidades);
    free(m);
}


struct heroi* cria_heroi (int id){
	struct heroi *h = malloc (sizeof(struct heroi));

	if(h == NULL)
		return NULL;
	
	h->id = id;
	h->xp = 0;
	h->paciencia = aleat(0, 100);
	h->velocidade = aleat(50, 5000);
	int num_habilidades = aleat (1,3);
	h->hab = cria_cjt (num_habilidades);
	for (int j = 0; j < num_habilidades; j++)
		insere_cjt (h->hab, aleat(0,9));

	return h;
}

void inicializa_herois (struct mundo *m){

	for (int i = 0; i < N_HEROIS; i++){
		m->herois[i] = cria_heroi(i);
	}
}

void imprime_heroi(struct heroi *h) {
    printf("ID: %d\n", h->id);
    printf("XP: %d\n", h->xp);
    printf("Paciência: %d\n", h->paciencia);
    printf("Velocidade: %d\n", h->velocidade);
    printf("Habilidades: ");
    imprime_cjt(h->hab);
    printf("\n");
}

struct base* cria_base (int id){
	struct base *b = malloc (sizeof(struct base));

	if (b == NULL)
		return NULL;

	b->id = id;
	b->lotacao = aleat (3,10);
	b->presentes = cria_cjt(b->lotacao);
	b->espera = fila_cria();
	b->coord.x = aleat (0, N_TAMANHO_MUNDO);
	b->coord.y = aleat (0, N_TAMANHO_MUNDO);

	return b;
}


void inicializa_bases (struct mundo *m){

	for (int i = 0; i < N_BASES; i++){
		m->bases[i] = cria_base (i);
	}
}

void imprime_base(struct base *b) {
    printf("ID: %d\n", b->id);
    printf("Coordenadas: (%d, %d)\n", b->coord.x, b->coord.y);
    printf("Lotação: %d\n", b->lotacao);
    // Adicione aqui a impressão para presentes e espera
}

struct missao* cria_missao (int id){

	struct missao *m = malloc (sizeof(struct missao));

	if (m == NULL)
		return NULL;

	m->id = id;
	m->coord.x = aleat (0, N_TAMANHO_MUNDO);
	m->coord.y = aleat (0, N_TAMANHO_MUNDO);
	
	int num_habilidades = aleat (6,10);
	m->hab_necessarias = cria_cjt (num_habilidades);
	for (int j = 0; j < num_habilidades; j++)
		insere_cjt (m->hab_necessarias, aleat(0,9));

	return m;
		
}

void inicializa_missoes (struct mundo *m){
	
	for (int i = 0; i < N_MISSOES; i++){
		m->missoes[i] = cria_missao(i);
	}
}

void imprime_missao(struct missao *m) {
    printf("ID: %d\n", m->id);
    printf("Coordenadas: (%d, %d)\n", m->coord.x, m->coord.y);
    printf("Habilidades necessárias: ");
    imprime_cjt(m->hab_necessarias);
    printf("\n");
}

void imprime_mundo(struct mundo *m) {
    printf("Heróis:\n");
    for (int i = 0; i < N_HEROIS; i++) {
        printf("Herói %d:\n", i + 1);
        imprime_heroi(m->herois[i]);
    }

    printf("------------------------\n");

    printf("Bases:\n");
    for (int i = 0; i < N_BASES; i++) {
        printf("Base %d:\n", i + 1);
        imprime_base(m->bases[i]);
    }

    printf("------------------------\n");
/*
    printf("Missões:\n");
    for (int i = 0; i < N_MISSOES; i++) {
        printf("Missão %d:\n", i + 1);
        imprime_missao(m->missoes[i]);
    }

    printf("------------------------\n");
*/
}


/*
void eventos_inicias (struct mundo *m){
	
	for (int i = 0; i < N_HEROIS; i++){
		int base = aleat(0, 8);
		int tempo = aleat(0, 4320);
		
		evento_t *evento_chega = chega(tempo, m->&herois[i], base);

		insere_lef(LEF, evento_chega);
	}

	for (int i = 0; i < N_MISSOES; i++){
		int tempo = aleat (0, T_FIM_DO_MUNDO);
		
		evento_t *evento_missao = missao(tempo, m->&missoes[i]);
		insere_lef (LEF, evento_missao);
	}

	evento_t *eventoFIM = fim(T_FIM_DO_MUNDO);
	insere_lef (LEF, eventoFIM);
}

void chega (int tempo, struct* heroi, struct* base){

	heroi->id_base = base->id;

	bool espera = (fila_tamanho(base->espera) > 0) ? (heroi->paciencia > 10 * fila_tamanho(base->espera)) : true;

	if (espera){
		Evento *evento_espera = cria_evento (tempo, heroi, base);
		insere_lef (LEF, evento_espera);
	}
	else {
		cria_evento desiste (tempo, heroi, base);
		Evento *evento_desiste = cria_evento (tempo, heroi, base);
	}
}

void espera (int tempo, struct* heroi, struct* base){

	insere_fila(base->espera, heroi->id);

	Evento* evento_avisa = cria_evento (tempo, base);

	insere_lef (LEF, evento_avisa);
}

void desiste (int tempo, struct* heroi, struct* base){

	int id_base = aleat (0, N_BASES - 1);

	Evento* evento_viaja = cria_evento (tempo, heroi, id_base);

	insere_lef (LEF, evento_viaja);

}

void avisa (int tempo, struct* base){

*/	
		
		
	
	
	
