#include <stdio.h>   
#include "mova.h"
#include "copiar.h"
#include "validacao.h"
/*
 * Esta função compara a matriz anterior ao movimento com a resultante 
 * @param int tamanho_grid - tamanho da matriz do jogo 

 * @return caso as matrizes sejam iguais, a função retorna 0, caso tenha alguma diferença, retorna 1
 */

int comparar(int tamanho_grid) {
	int i = 0;
	int j = 0; 
	for (i = 0; i < tamanho_grid; i++)
	{
		for (j = 0; j < tamanho_grid; j++)
		{
			if (gcopia[i][j] != g[i][j]) {
				return 1;
			}
		}
	}
	return 0;
}