#include <stdio.h>  
#include "carregar_pontos.h"

/*
 * Esta função carrega a última maior pontuação, assim como o jogador que a conquistou:
 * @param int ult_pontuacao - variável que armazena a pontuação recuperada
 * @param char campeao - variável que armazena nome do jogado que obteve a pontuação
	
 * @return ult_pontuacao - retorno o valor da pontuação
 */

int carregar_pontos (int ult_pontuacao, char* campeao) {
	FILE *fd;
	fd = fopen (file, "r");
	if (fd == NULL) { fd = fopen (".ult_pontuacao", "w+"); }
	if (fscanf(fd, "%d %s", &ult_pontuacao, campeao) == EOF) ult_pontuacao = 0;
    fclose(fd);
    
    return ult_pontuacao;
}
