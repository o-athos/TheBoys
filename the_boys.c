#include "the_boys.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
	m->cumpridas = 0;
	m->tentativas = 0;

	return m;
}

void destroi_mundo(struct mundo *m) {
    // Libere memória alocada para os vetores e, em seguida, para a estrutura mundo
    destroi_herois(m);

    destroi_bases(m);

    destroi_missoes (m);

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

void destroi_herois (struct mundo *m){
	
	for (int i = 0; i < N_HEROIS; i++){
		destroi_cjt(m->herois[i]->hab);
		free(m->herois[i]);
		m->herois[i] = NULL;
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

void destroi_bases (struct mundo *m){
	for (int i = 0; i < N_BASES; i++){
		destroi_cjt(m->bases[i]->presentes);
		fila_destroi (&(m->bases[i]->espera));
		free(m->bases[i]);
	}
}


void imprime_base(struct base *b) {
    printf("ID: %d\n", b->id);
    printf("Coordenadas: (%d, %d)\n", b->coord.x, b->coord.y);
    printf("Lotação: %d\n", b->lotacao);
	fila_imprime (b->espera);
	printf("\n");
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

void destroi_missoes (struct mundo *m){

	for (int i = 0; i < N_MISSOES; i++){
		destroi_cjt(m->missoes[i]->hab_necessarias);
		free(m->missoes[i]);
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

   /* printf("------------------------\n");

    printf("Missões:\n");
    for (int i = 0; i < N_MISSOES; i++) {
        printf("Missão %d:\n", i + 1);
        imprime_missao(m->missoes[i]);
    }

    printf("------------------------\n");
*/
}



void eventos_iniciais (struct mundo *m, struct lef_t *LEF){
	
	for (int i = 0; i < N_HEROIS; i++){
		int base = aleat(0, 7);
		int tempo = aleat(0, 4320);
		
		struct evento_t *evento_chega = cria_evento(tempo, CHEGA, m->herois[i]->id, base);

		insere_lef(LEF, evento_chega);
	}

	for (int i = 0; i < N_MISSOES; i++){
		int tempo = aleat (0, T_FIM_DO_MUNDO);
		
		struct evento_t *evento_missao = cria_evento (tempo, MISSAO, m->missoes[i]->id, 0);
		insere_lef (LEF, evento_missao);
	}
	

	struct evento_t *eventoFIM = cria_evento (T_FIM_DO_MUNDO, FIM, 0, 0);
	insere_lef (LEF, eventoFIM);
}



void chega (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF){

	m->herois[evento->dado1]->id_base = evento->dado2;

	int espera = 0;
   	if ((cardinalidade_cjt(m->bases[evento->dado2]->presentes) < m->bases[evento->dado2]->lotacao) && (fila_vazia(m->bases[evento->dado2]->espera)))
		espera = 1;
	else
		espera = (m->herois[evento->dado1]->paciencia) > (10 * fila_tamanho(m->bases[evento->dado2]->espera));

	// bool espera = (fila_tamanho(m->bases[evento->dado2]->espera) > 0) ? (m->herois[evento->dado1]->paciencia > 10 * fila_tamanho(m->bases[evento->dado2]->espera)) : true;

	if (espera){
		struct evento_t *evento_espera = cria_evento (tempo, ESPERA, evento->dado1, evento->dado2);
		insere_lef (LEF, evento_espera);
		printf("%6d: CHEGA HEROI %2d BASE %d (%2d/%2d) ESPERA\n", tempo, evento->dado1, evento->dado2, cardinalidade_cjt(m->bases[evento->dado2]->presentes), m->bases[evento->dado2]->lotacao);
	}
	else {
		struct evento_t *evento_desiste = cria_evento (tempo, DESISTE, evento->dado1, evento->dado2);
		insere_lef (LEF, evento_desiste);
		printf("%6d: CHEGA HEROI %2d BASE %d (%2d/%2d) DESISTE\n", tempo, evento->dado1, evento->dado2, cardinalidade_cjt(m->bases[evento->dado2]->presentes), m->bases[evento->dado2]->lotacao);
	}
}


void espera (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF){

	enqueue(m->bases[evento->dado2]->espera, m->herois[evento->dado1]->id);

	struct evento_t *evento_avisa = cria_evento (tempo, AVISA, evento->dado1, evento->dado2);
	insere_lef (LEF, evento_avisa);

	printf("%6d: ESPERA HEROI %2d BASE %d (%2d)\n", tempo, evento->dado1, evento->dado2, fila_tamanho(m->bases[evento->dado2]->espera)-1);
}


void desiste (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF){

	int id_base = aleat (0, N_BASES - 1);

	struct evento_t *evento_viaja = cria_evento (tempo, VIAJA, evento->dado1, id_base);
	
	insere_lef (LEF, evento_viaja);

	printf("%6d: DESISTE HEROI %2d BASE %d\n", tempo, evento->dado1, evento->dado2);

}


void avisa (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF){

	printf("%6d: AVISA PORTEIRO BASE %d (%2d/%2d) FILA ", tempo, evento->dado2, cardinalidade_cjt(m->bases[evento->dado2]->presentes), m->bases[evento->dado2]->lotacao);
   	fila_imprime (m->bases[evento->dado2]->espera);	
	while (cardinalidade_cjt(m->bases[evento->dado2]->presentes) < m->bases[evento->dado2]->lotacao && !fila_vazia(m->bases[evento->dado2]->espera)){
		int *heroi_entra = malloc (sizeof(int));
		dequeue(m->bases[evento->dado2]->espera, heroi_entra);
		insere_cjt(m->bases[evento->dado2]->presentes, *heroi_entra);

		struct evento_t *evento_entra = cria_evento (tempo, ENTRA, *heroi_entra, evento->dado2);
		insere_lef (LEF, evento_entra);

		printf("%6d: AVISA PORTEIRO BASE %d ADMITE %2d\n", tempo, evento->dado2, *heroi_entra);

		free(heroi_entra);
	}
}

void entra (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF){

	insere_cjt (m->bases[evento->dado2]->presentes, evento->dado1);

	int TPB = 15 + m->herois[evento->dado1]->paciencia * aleat(1, 20);

	struct evento_t *evento_sai = cria_evento (tempo + TPB, SAI, evento->dado1, evento->dado2);
	insere_lef (LEF, evento_sai);

	printf("%6d: ENTRA HEROI %2d BASE %d (%2d/%2d) SAI %d\n", tempo, evento->dado1, evento->dado2, cardinalidade_cjt(m->bases[evento->dado2]->presentes), m->bases[evento->dado2]->lotacao, tempo+TPB);
}

void sai (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF){

	retira_cjt (m->bases[evento->dado2]->presentes, evento->dado1);

	int base_destino = aleat (0, N_BASES - 1);

	struct evento_t *evento_viaja = cria_evento (tempo, VIAJA, evento->dado1, base_destino);
	insere_lef (LEF, evento_viaja);

	struct evento_t *evento_avisa = cria_evento (tempo, AVISA, evento->dado1, evento->dado2);
	insere_lef (LEF, evento_avisa);

	printf("%6d: SAI HEROI %2d BASE %d (%2d/%2d)\n", tempo, evento->dado1, evento->dado2, cardinalidade_cjt(m->bases[evento->dado2]->presentes), m->bases[evento->dado2]->lotacao);

}

void viaja (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF){

	int x_base_atual = m->bases[m->herois[evento->dado1]->id_base]->coord.x;
	int y_base_atual = m->bases[m->herois[evento->dado1]->id_base]->coord.y;

	int x_base_destino = m->bases[evento->dado2]->coord.x;
	int y_base_destino = m->bases[evento->dado2]->coord.y;

	int a = (x_base_atual - x_base_destino) * (x_base_atual - x_base_destino);
	int b = (y_base_atual - y_base_destino) * (y_base_atual - y_base_destino);

	int distancia = sqrt(a + b);

	int duracao = distancia / m->herois[evento->dado1]->velocidade;

	struct evento_t *evento_chega = cria_evento (tempo + duracao, CHEGA, evento->dado1, evento->dado2);
   	insere_lef (LEF, evento_chega);

	printf("%6d: VIAJA HEROI %2d BASE %d BASE %d DIST %d VEL %d CHEGA %d\n", tempo, evento->dado1, m->herois[evento->dado1]->id_base, evento->dado2, distancia, m->herois[evento->dado1]->velocidade, tempo + duracao);
}

void missao (int tempo, struct mundo *m, struct evento_t *evento, struct lef_t *LEF){

	//imprime o id da missão e quais habilidades necessárias para cumpri-la.
	printf("%6d: MISSSAO %d HAB REQ: ", tempo, evento->dado1);
	imprime_cjt (m->missoes[evento->dado1]->hab_necessarias);
	
	//recebe a coordenada x e y da missão.
	int x_missao = m->missoes[evento->dado1]->coord.x;
	int y_missao = m->missoes[evento->dado1]->coord.y;	

	//lef auxiliar para ordenar as bases por proximidade.
	struct lef_t *ordem_bases = cria_lef();

	//looping para calcular as distancia de todas as bases do mundo até a missão.
	for (int i = 0; i < N_BASES; i++){
		int x_base = m->bases[i]->coord.x;
		int y_base = m->bases[i]->coord.y;

		int a = (x_base - x_missao)*(x_base - x_missao);
		int b = (y_base - y_missao)*(y_base - y_missao);

		int distancia = sqrt(a + b);

		//cria um evento e insere na lef. cada evento representa um base.
		struct evento_t *base = cria_evento (distancia, -1, i, 0);

		insere_lef(ordem_bases, base);
	}
	
	int j = 0;
	int cumpri = 0;
	struct evento_t *b = NULL;

	//enquanto a base mais proxima nao for capaz de cumrprir a missao e ainda houver bases, passar para outra base e ver se ela cumpri.
	while (!cumpri && j != N_BASES){

		//retira da lef a base mais proxima.
		b = retira_lef (ordem_bases);
		
		//conjunto para acumular as habilidades dos herois presentes na base.
		struct conjunto *hab_na_base = cria_cjt(N_HABILIDADES);

		//looping para armazenar no conj hab_na_base as habilidades de todos os herois presentes na base.
		for (int i = 0; i < m->bases[b->dado1]->presentes->card; i++){
			int id_heroi = m->bases[b->dado1]->presentes->v[i];

			struct conjunto *temp_uniao = uniao_cjt (hab_na_base, m->herois[id_heroi]->hab);

			destroi_cjt (hab_na_base);

			hab_na_base = temp_uniao;

           /* hab_na_base = uniao_cjt(hab_na_base, m->herois[id_heroi]->hab);
            printf("Habilidades do Herói %d na Base: ", id_heroi);
            imprime_cjt(m->herois[id_heroi]->hab);
            printf("Habilidades acumuladas: ");
            imprime_cjt(hab_na_base);*/

		}

		printf("%6d: MISSAO %d HAB BASE %d: ", tempo, evento->dado1, b->dado1);
		imprime_cjt (hab_na_base);

		//se as habilidades necessárias está contida no conj de habilidades presentes na base, a base cumpri a missão.
		if (contido_cjt(m->missoes[evento->dado1]->hab_necessarias, hab_na_base))
			cumpri = 1;
		else{
			cumpri = 0;
			// se nao cumpri descartamos a base b, para retirar a proxima.
			free(b);
		}
		
		//destroi conj de hab_na_base que não será mais usado. ou por ja ter cumprido ou para montar o conj de habilidades de outra base.
		j++;
		destroi_cjt(hab_na_base);
	}

	//se a base cumpri incrementa o numero de missoes cumpridas e o xp dos herois da base que cumpriu. e descarta a base b.
	if (cumpri){
		
		m->cumpridas++;
		printf("%6d: MISSAO %d CUMPRIDA BASE %d HEROIS: ", tempo, evento->dado1, b->dado1);
	   	imprime_cjt(m->bases[b->dado1]->presentes);

		for (int h = 0; h < m->bases[b->dado1]->presentes->card; h++){
			int id_heroi = m->bases[b->dado1]->presentes->v[h];

			m->herois[id_heroi]->xp++;
		}
		free(b);
	}
	//se nao cumpriu, a missao eh impossivel e adiada 24h. incrementa a tentativa.
	else{
		m->tentativas++;
		printf("%6d: MISSAO %d IMPOSSIVEL\n", tempo, evento->dado1);
		struct evento_t *evento_missao = cria_evento (tempo + 24*60, MISSAO, evento->dado1, 0);
		insere_lef (LEF, evento_missao);
	}
	destroi_lef (ordem_bases);
}
	
void fim (int tempo, struct mundo *m){

	printf("%6d: FIM\n", tempo);
	for (int i = 0; i < N_HEROIS; i++){
		printf("HEROI %2d PAC %3d VEL %4d  EXP %4d HABS ", i, m->herois[i]->paciencia, m->herois[i]->velocidade, m->herois[i]->xp);
		imprime_cjt(m->herois[i]->hab);
	}

	printf("%d/%d MISSOES CUMPRIDAS (%.2f%%), MEDIA %.2f TENTATIVAS/MISSAO\n", m->cumpridas, N_MISSOES, (float) m->cumpridas/N_MISSOES * 100 , (float)m->tentativas / m->cumpridas);
	

	destroi_mundo(m);
}

	
	




	
		
		
	
	
	
