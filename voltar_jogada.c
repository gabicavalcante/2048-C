#include <stdio.h>   
#include "mova.h"
#include "copiar.h"

/*
 * Essa função volta a jogada, ele vai atribuir a matriz oficial os valores da matriz cópia, que sempre tem os valores da jogada
 * anterior
 * @param int tamanho_grid - variavel com tamanho da tabela 
*/

void voltar_jogada(int tamanho_grid) {
	int i = 0;
	int j = 0; 
	for (i = 0; i < tamanho_grid; i++)
	{   
		for (j = 0; j < tamanho_grid; j++)
		{
			g[i][j] = gcopia[i][j];
		}
	}
}