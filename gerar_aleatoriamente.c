#include <stdio.h>  
#include <stdlib.h> /* calloc, exit  */
#include "gerar_aleatoriamente.h"
#include "carregar_pontos.h"
#include "mova.h"
#include "desenhe_mapa.h"
#include "validacao.h"

/*
 * Esta função gera os valores aleatórios para as casas aleatórias.
 * @param int tamanho_grid - tamanho da matriz do jogo 
 * @param int ult_pontuacao - valor a última maior pontuação
 */

void gerar_aleatoriamente(int ult_pontuacao, int tamanho_grid) {
	if (conferir_vazio(tamanho_grid)) {
		int x, y;  
		while(g[x = rand() % tamanho_grid][y = rand() % tamanho_grid]); //gerar posições aleatórias até o tamanho limite do grid
		g[x][y] = (rand() & 3) ? 2 : 4; //aqui, ele vai gerar um número "aleatório", vai fazer um & com o 3 e se for true (111) 
										//vai imprimir um 2 na casa, e não, será um 4. O & foi feito com o 3 para gerar mais 2 que 4
										//assim, vamos ter cerca de 60% de casas com 2 e 40% de casas com 4
	}
}
