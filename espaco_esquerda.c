#include <stdio.h>  
#include "espaco_esquerda.h"
#include "mova.h"

int espaco_esquerda(int tamanho_grid) {
	int i, j;
    for (i = 0; i < tamanho_grid; i++) {
        for (j = 0; j < tamanho_grid; j++) {
            if (!g[i][j]) //verificar se estão vazias
                return 1;
            else if (j + 1 < tamanho_grid && ((g[i][j] == g[i][j++]) || (g[j][i] == g[j++][i]))) 
				return 1;
		}
	}
    return 0;
	
}
