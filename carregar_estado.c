#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include "mova.h"  
#include "desenhe_mapa.h"
#include "carregar_estado.h"

void carregar_estado(char* jogador) {
	FILE *doc;
	int i = 0, j = 0, a, b, c, d;  
	//char caminho[100] = "/historico/";
	//strcat(caminho, jogador);
	doc = fopen(".ult_estado", "r");
	while(fscanf(doc, "%i %i %i %i", &a, &b, &c, &d) != EOF) {
		g[i][j] = a; j+=1;
		g[i][j] = b; j+=1;
		g[i][j] = c; j+=1;
		g[i][j] = d;
		i+=1;
		j = 0;
	} 
	fclose(doc);
}
