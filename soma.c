#include <stdio.h>  
#include "soma.h"
#include "mova.h"
#include "salvar_pontos.h"

/*
 * Esta função realiza a soma dos valores vizinhos que são iguais, recebe:
 * @param int d - dígito teclado pelo usuário
 * @param int tamanho_grid - tamanho da matriz do jogo 
 */
void soma(int d, int tamanho_grid) {
	if (d == 1 || d == 2) {
		int i, j;
		for (i = 0; i < tamanho_grid; i++) {
			for (j = 0; j < tamanho_grid; j++) {
				if (j + 1 < tamanho_grid && g[i][j] == g[i][j+1] && g[i][j]) { 
				    //enquanto estiver dentro matriz E a posição for igual a próxima E a posição tiver algum valor diferente de 0
					//g[i][j] <<= 1; vai mover o bit 1 a esquerda, dobrando o valor da casa
					g[i][j] *= 2;
					pontuacao += g[i][j];
					g[i][j++ + 1] = 0;
				}
			}
		}
	}
	else {
		int i, j;
		for (i = 0; i < tamanho_grid; i ++) {
			for (j = 0; j < tamanho_grid; j++) {
				if (j + 1 < tamanho_grid && g[j][i] == g[j+1][i] && g[j][i]) {
					g[j][i] *= 2;
					pontuacao += g[j][i];
					g[j++ + 1][i] = 0;
				}
			}
		}
	}

}
