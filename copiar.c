#include <stdio.h>   
#include "mova.h"
#include "copiar.h"

/*
 * Esta função copiar a matriz atual em uma matriz cópia, que será usada posteriormente na função comparar()
 * @param int d - dígito teclado pelo usuário
 * @param int tamanho_grid - tamanho da matriz do jogo 
 */

void copiar(int tamanho_grid) {
	int i = 0;
	int j = 0; 
	for (i = 0; i < tamanho_grid; i++)
	{   
		for (j = 0; j < tamanho_grid; j++)
		{
			gcopia[i][j] = g[i][j];
		}
	}
}