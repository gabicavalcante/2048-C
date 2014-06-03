#include <stdio.h>  
#include "mova.h"

/*
Esse código tem como função somente mover, por isso a ação só é feita enquanto há casas com valor 0 ao lado da casa
que esta sendo movida.
A função recebe como parâmetro a tecla digitada e o tamanho do grid.
*/

void mova(int tecla, int tamanho_grid) {
	if (tecla == 1) {
		//printf("Esquerda\n");
		int i, j;
		for (i = 0; i < tamanho_grid; i++) {
			for (j = 0; j < tamanho_grid - 1; j++) {
				if (g[i][j]) {continue;} //verifica se na casa tem algo na casa, se tive ele "pula o for"
				int a = 1;
				while (j + a < tamanho_grid && !g[i][j + a]) a++; 
				//ele vai contar quantas casas há vazias até se esbarrar em um número (!g[i][j + a]) ou até
				//se chegar no limite da matriz j + a < tamanho_grid
				if (j + a < tamanho_grid) { //se o j mais a contagem feita for menor que o tamanho da matriz   
                g[i][j] = g[i][j + a];		//a posição do momento vai receber o valor do número mais próximo
                g[i][j + a] = 0;			//essa casa que teve o valor movido recebe 0
                }
			}
		} 
	}
	else if (tecla == 3) {
		//printf("Cima\n");
		int i, j;
		for (i = 0; i < tamanho_grid; i ++) {
			for (j = 0; j < tamanho_grid - 1; j++) {
				if (g[j][i]) continue; 
				int a = 1;
				while (j + a < tamanho_grid && !g[j + a][i]) a++; 
				if (j + a < tamanho_grid) {
                g[j][i] = g[j + a][i];
                g[j + a][i] = 0;
                }
			}
		} 
	}
	else if (tecla == 2) {
		//printf("Direita\n");
		int i, j;
		for (i = 0; i < tamanho_grid; i ++) {
			for (j = tamanho_grid-1; j > 0; j--) {
				if (g[i][j]) continue;  
				int a = 1;
				while (j - a >= 0 && !g[i][j - a]) a++;  
				if (j - a >= 0) {
                g[i][j] = g[i][j - a];
                g[i][j - a] = 0;
                }
			}
		} 
	}
	else if (tecla == 4) {
		//printf("Baixo\n");
		int i, j;
		for (i = 0; i < tamanho_grid; i ++) {
			for (j = tamanho_grid - 1; j > 0; j--) {
				if (g[j][i]) continue; 
				int a = 1;
				while (j - a >= 0 && !g[j - a][i]) a++; 
				if (j - a >= 0) {
					g[j][i] = g[j - a][i];
					g[j - a][i] = 0;
                }
			}
		} 
	}
}
