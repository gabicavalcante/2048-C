#include <stdio.h>  
#include "espaco_esquerda.h"
#include "mova.h"

/*
 * Esta função verifica se ainda é possivel mover, vendo se há espaço vazio e se ainda tem valores que possam ser somados 
 * @param int tamanho_grid - tamanho da matriz do jogo 
 * @return se ainda tiver espaço vazio a função irá retornar 1 e se ainda tiver valores que possam ser somados, também retornará
 * 1, já se nenhum desses casos fossem obedecidos, seria retornado 0
 */

int espaco_esquerda(int tamanho_grid) {
	int i, j;
    for (i = 0; i < tamanho_grid; i++) {
        for (j = 0; j < tamanho_grid; j++) {
            if (!g[i][j]) { //verificar se estão vazias
                return 1; 
            }
        }
    }
    return 0;
}

int ver_par(int tamanho_grid) {
    int i, j;
    for (i = 0; i < tamanho_grid-1; i++)  {
        for (j = 0; j < tamanho_grid-1; j++) { 
            if ((j <= tamanho_grid-1) && (i <= tamanho_grid-1) && (g[i][j] == g[i][j+1]) || (g[i][j] == g[i+1][j])) {
                return 1;
            }
        }
    }
    return 0;
}

int ver_se_ganhou(tamanho_grid) {
    int i, j;
    for (i = 0; i < tamanho_grid; i++) {
        for (j = 0; j < tamanho_grid; j++) {
            if (g[i][j] == 2048) { //verificar se estão vazias
                return 1; 
            }
        }
    }
    return 0;
}