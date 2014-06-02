#include <stdio.h>   
#include "mova.h"
#include "copiar.h"

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