#include "the_boys.h"
#include <stdio.h>
#include <stdbool.h>

int aleat (int min, int max){
	return (rand () % (max - min + 1)) + min;
}


void inicializa_herois (struct mundo m){

	for (int i = 0; i < m->n_herois; i++){
		herois[i].id = i;
		herois[i].xp = 0;
		herois[i].paciencia = aleat(0, 100);
		herois[i].velocidade = aleat(50, 5000);

		int num_habilidades = aleat (1, 3);
		for (int j = 0; j < num_habilidades; j++)
			herois[i].hab[j] = aleat(0, 9);
	}
}

void inicializa_bases (struct mundo *m){

	for (int = 0; i < m->n_bases; i++){
		bases[i]->id = i;
		bases[i]->coordenada.x = aleat(0, N_TAMANHO_MUNDO-1);
	    bases[i]->coordenada.y = aleat(0, N_TAMANH_MUNDO-1);	
		bases[i]->lotacao = aleat(3, 10);
		bases[i]->presentes = cria_conjunto(bases[i]->lotacao);
		bases[i]->espera = cria_fila ();
	}

void inicializa_missoes (struct mundo *m){
	
	for (int i = 0; i < m->n_missoes; i++){
		missoes[i]->id = i;
		missoes[i]->coordenada.x = aleat(0, N_TAMANHO_MUNDO-1);                             
 	    missoes[i]->coordenada.y = aleat(0, N_TAMANHO_MUNDO-1);
		missoes[i]->hab_necessarias = 


void eventos_inicias (struct mundo *m){
	
	for (int i = 0; i < m->n_herois; i++){
		int base = aleat(0, 8);
		int tempo = aleat(0, 4320);
		
		Evento *evento_chega = chega(tempo, &herois[i], base);

		insere_lef(LEF, evento_chega);
	}

	for (int i = 0; i < m->n_missoes; i++){
		int tempo = aleat (0, T_FIM_DO_MUNDO);
		
		Evento *evento_missao = missao(tempo, &missoes[i]);
		insere_lef (LEF, evento_missao);
	}

	Evento *eventoFIM = fim(T_FIM_DO_MUNDO);
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


		
		
	
	
	
