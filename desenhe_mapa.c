#include <stdio.h>  
#include "desenhe_mapa.h"
#include "mova.h"  
#include "carregar_estado.h"

void desenhe_mapa(int ult_pontuacao, int tamanho_grid) {
	printf("MAIOR PONTUAÇÃO: %d |", ult_pontuacao);
    printf("| PONTUAÇÃO: %d ", pontuacao); 
    printf("-\n");
    int i = 0;
	for (i = 0; i < tamanho_grid; i++) 
		printf("------");
    printf("-\n");
    
    int j;
    for (i = 0; i < tamanho_grid; i ++) {
		printf("|");
		for (j = 0; j < tamanho_grid; j++){
			if (g[i][j])
                printf("%*d |", 4, g[i][j]);
            else
                printf("     |");
        }
        printf("\n");
	}
	for (i = 0; i < tamanho_grid; i++) 
		printf("------");
    printf("-\n"); 
}

