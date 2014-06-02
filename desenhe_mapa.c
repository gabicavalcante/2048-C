#include <stdio.h>  
#include "desenhe_mapa.h"
#include "mova.h"  
#include "carregar_estado.h"

/*
 * Esta função imprime o mapa, junto com um menu, menor pontuação, jogador que conseguiu maior pontuação e a pontuação atual
 * @param int ult_pontuacao - valor da ultima maior pontuação conquistada
 * @param int tamanho_grid - tamanho da matriz do jogo 
 * @nome - nome do jogador que consegui a maior pontuação
 */

void desenhe_mapa(int ult_pontuacao, int tamanho_grid, char* nome) {
    printf("\n");
	printf("| MAIOR PONTUAÇÃO: %.4d |\n", ult_pontuacao);
    printf("| CAMPEÃO: %.4s         |\n", nome);
    printf("| PONTUAÇÃO: %.4d       |\n", pontuacao);  
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

    printf("\n");
    printf("        ←,↑,→,↓ ou q        \n");
    printf("        a,w,d,s ou q        \n");
    printf("        r - voltar jogada   \n");
}

