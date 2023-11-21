#include "the_boys.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    srand(8);
    struct lef_t *LEF = cria_lef();
    
    struct mundo *m = cria_mundo();
    
    eventos_iniciais (m, LEF);
    
    int relogio = 0;
    
    
    while (relogio != T_FIM_DO_MUNDO){
      
      struct evento_t *ev = retira_lef(LEF);
      
      relogio = ev->tempo;
      
      switch (ev->tipo){
        case CHEGA:
          chega (relogio, m, ev, LEF);
          break;
        case ESPERA:
          espera (relogio, m, ev, LEF);
          break;
		case DESISTE:
		  desiste (relogio, m, ev, LEF);
		  break;
        case AVISA:
          avisa (relogio, m, ev, LEF);
          break;
        case ENTRA:
          entra (relogio, m, ev, LEF);
          break;
        case SAI:
          sai (relogio, m, ev, LEF);
          break;
        case VIAJA:
          viaja (relogio, m, ev, LEF);
          break;
        case MISSAO:
          missao (relogio, m, ev, LEF);
          break;
      }
      
     free(ev); 
    } 
    fim (relogio, m);
    destroi_lef(LEF);

    return 0;
}



