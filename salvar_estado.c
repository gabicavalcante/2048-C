#include <stdio.h>  
#include "salvar_estado.h"
#include "carregar_pontos.h"
#include "mova.h"  

void salvar_estado(int tamanho_grid) {
	int i, j;
	remove("historico/.ult_estado");
	FILE *fd; 
	fd = fopen(file_estado, "a");
	for (i = 0; i < tamanho_grid; i ++) {
		for (j = 0; j < tamanho_grid; j++) {
			fprintf(fd, "%d ", g[i][j]);
		}
		fprintf(fd, "\n");
	}
	fclose(fd); 
}
