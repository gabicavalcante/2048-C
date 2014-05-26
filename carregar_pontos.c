#include <stdio.h>  
#include "carregar_pontos.h"

int carregar_pontos (int ult_pontuacao) {
	FILE *fd;
	fd = fopen (file, "r");
	if (fd == NULL) { fd = fopen (".ult_pontuacao", "w+"); }
	if (fscanf(fd, "%d", &ult_pontuacao) == EOF) ult_pontuacao = 0;
    fclose(fd);
    
    return ult_pontuacao;
}
