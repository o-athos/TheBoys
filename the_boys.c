#include "the_boys.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int aleat (int min, int max){
	return (rand () % (max - min + 1)) + min;
}


void inicializa_herois (struct mundo *m){

	for (int i = 0; i < N_HEROIS; i++){
		m->herois[i].id = i;
		m->herois[i].xp = 0;
		m->herois[i].paciencia = aleat(0, 100);
		m->herois[i].velocidade = aleat(50, 5000);

		int num_habilidades = aleat (1, 3);
		for (int j = 0; j < num_habilidades; j++)
			m->herois[i].hab[j] = aleat(0, 9);
	}
}

void inicializa_bases (struct mundo *m){

	for (int i = 0; i < N_BASES; i++){
		m->bases[i].id = i;
		m->bases[i].coord.x = aleat(0, N_TAMANHO_MUNDO-1);
	    m->bases[i].coord.y = aleat(0, N_TAMANHO_MUNDO-1);	
		m->bases[i].lotacao = aleat(3, 10);
		m->bases[i].presentes = cria_cjt(m->bases[i].lotacao);
		m->bases[i].espera = fila_cria ();
	}
}

void inicializa_missoes (struct mundo *m){
	
	for (int i = 0; i < N_MISSOES; i++){
		m->missoes[i].id = i;
		m->missoes[i].coord.x = aleat(0, N_TAMANHO_MUNDO-1);                             
 	    m->missoes[i].coord.y = aleat(0, N_TAMANHO_MUNDO-1);
		//m->missoes[i].hab_necessarias = 

	}
}

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
/*
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
		
		
	
	
	
