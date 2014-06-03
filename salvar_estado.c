#include <stdio.h>  
#include "salvar_estado.h"
#include "carregar_pontos.h"
#include "salvar_pontos.h"
#include "mova.h"  
#include "carregar_estado.h"

/*
  * Essa função salva os valores da matriz do jogo e a pontuação alcançada 
  * @params int tamanho - variavel com tamanho da tabela
*/

void salvar_estado(int tamanho_grid) {
	int i, j;
	remove(file_estado);
	FILE *fd; 
	fd = fopen(file_estado, "a"); 
	for (i = 0; i < tamanho_grid; i ++) {
		for (j = 0; j < tamanho_grid; j++) {
			fprintf(fd, "%d ", g[i][j]);
		}
		fprintf(fd, "\n");
	}

	fprintf(fd, "%i\n", pontuacao);
	fclose(fd); 
} 