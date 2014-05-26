#include <stdio.h>  
#include "salvar_pontos.h"
#include "carregar_pontos.h"

void salvar_pontos(int ult_pontuacao, int tamanho_grid) {
	if ((pontuacao > ult_pontuacao) && (tamanho_grid == tamanho_grid)) {
		ult_pontuacao = pontuacao;
		FILE *fd;
		fd = fopen(file, "w+");
		fprintf(fd, "%d", ult_pontuacao);
        fclose(fd);
	} 
}
