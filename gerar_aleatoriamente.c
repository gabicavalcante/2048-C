#include <stdio.h>  
#include <stdlib.h> /* calloc, exit  */
#include "gerar_aleatoriamente.h"
#include "carregar_pontos.h"
#include "mova.h"
#include "desenhe_mapa.h"

void gerar_aleatoriamente(int ult_pontuacao, int tamanho_grid) {
	if (espaco_esquerda(tamanho_grid)) {
		int x, y;
		while(g[x = rand() % tamanho_grid][y = rand() % tamanho_grid]);
		g[x][y] = (rand() & 3) ? 2 : 4;
	}
	else {
        printf("\n"
               "Você perdeu, mané.\n"
               "Sua pontuação foi: %i \n", pontuacao);
        salvar_pontos(ult_pontuacao, file);
        exit(EXIT_SUCCESS);
    }
}
