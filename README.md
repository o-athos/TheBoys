# The Boys

Simulador de um mundo com herois, habilidades, bases, missoes, viagens e bases.

Feito na linguagem C, implementado usando Estruturas de Dados Conjunto, Fila, Lista Encadeada.

## Funcionamento geral

O mundo eh criado com as bases e os herois com suas habilidades e velocidade.<br>
No decorrer do tempo, missoes aparecem no mapa, cada missao requer determinados poderes que alguns herois possuem, dessa forma, os herois que possuem as habilidades necessarias para aquela missao devem viajar para a base da missao.<br>
Essa viagem tem um tempo de travessia que depende da velocidade do personagem, alem disso, ao chegar na base pode haver uma fila de espera para entrar, dependendo da paciencia do personagem ele espera ou desiste.

Apos a missao ser feita, os herois que realizaram ganham um acrescimo de XP e a missao eh considerada feita.<br>
Pode haver missoes nao cumpridas ou que precisem de mais de uma tentativa.

## Executar

Depois de clonar o repositorio e estar nele.

Comando `make`

e finalmente, `./the_boys`
