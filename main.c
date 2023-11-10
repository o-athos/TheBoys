#include "the_boys.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    srand(0);

    struct mundo *m = cria_mundo();

    imprime_mundo(m);

    destroi_mundo(m);
    // Libere a memória alocada dinamicamente, se necessário

    return 0;
}



