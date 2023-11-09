#include "the_boys.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    srand(0);
    
    struct mundo m;
 
    struct lef_t *LEF = cria_lef();
 
    inicializa_herois(&m);
    printf("Heróis:\n");
    for (int i = 0; i < N_HEROIS; i++) {
        printf("Herói %d:\n", i + 1);
        printf("ID: %d\n", m.herois[i].id);
        printf("XP: %d\n", m.herois[i].xp);
        printf("Paciência: %d\n", m.herois[i].paciencia);
        printf("Velocidade: %d\n", m.herois[i].velocidade);
        printf("Habilidades: ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", m.herois[i].hab[j]);
        }
        printf("\n");
        printf("------------------------\n");
    }

    inicializa_bases(&m);
    printf("Bases:\n");
    for (int i = 0; i < N_BASES; i++) {
        printf("Base %d:\n", i + 1);
        printf("ID: %d\n", m.bases[i].id);
        printf("Coordenadas: (%d, %d)\n", m.bases[i].coord.x, m.bases[i].coord.y);
        printf("Lotação: %d\n", m.bases[i].lotacao);
        // Adicione aqui a impressão para presentes e espera
        printf("------------------------\n");
    }

    inicializa_missoes(&m);
    printf("Missões:\n");
    for (int i = 0; i < N_MISSOES; i++) {
        printf("Missão %d:\n", i + 1);
        printf("ID: %d\n", m.missoes[i].id);
        printf("Coordenadas: (%d, %d)\n", m.missoes[i].coord.x, m.missoes[i].coord.y);
        printf("Habilidades necessárias: %d\n", m.missoes[i].hab_necessarias);
        // Adicione aqui outras informações necessárias para missões
        printf("------------------------\n");
    }

    return 0;
}



