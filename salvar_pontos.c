#include <stdio.h>  
#include "salvar_pontos.h"
#include "carregar_pontos.h"

/*
 * Essa função salvará a pontuação do jogo caso seja a maior do que a salva até o momento
 * @param int tamanho_grid - variavel com tamanho da tabela
 * @param int ult_pontuacao - valor a última maior pontuação
 * @param char* nome - guarda o valor do nome do jogador
*/

void salvar_pontos(int ult_pontuacao, int tamanho_grid, char* nome) {
	if ((pontuacao > ult_pontuacao) && (tamanho_grid == tamanho_grid)) {
		ult_pontuacao = pontuacao;
		FILE *fd;
		fd = fopen(file, "w+");
		fprintf(fd, "%d %s", ult_pontuacao, nome);
        fclose(fd);
	} 
}
