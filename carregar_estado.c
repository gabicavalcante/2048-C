#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include "mova.h"  
#include "entrada.h"                 
#include "desenhe_mapa.h"
#include "carregar_estado.h"
#include "salvar_estado.h" 
#include "salvar_pontos.h" 

/*
 * Esta função carrega o estado do último jogo, tanto a matriz como a pontuação do jogador:
 * @param int jogador - nome do jogador atual  
 */

void carregar_estado(char* jogador) {
	FILE *doc;
	int i = 0, j = 0, a, b, c, d;   
	int y = 0; 
	printf("%s\n", file_estado);
	doc = fopen(file_estado, "r");    
	if(doc == NULL) {
      perror("Error opening file"); 
   	}
   	else {
		int pont; 
		while(y <= 4) {
			if (y < 4)  { 
				fscanf(doc, "%i %i %i %i", &a, &b, &c, &d);
				g[i][j] = a; j+=1;
				g[i][j] = b; j+=1;
				g[i][j] = c; j+=1;
				g[i][j] = d;
				i+=1;
				j = 0;
				y+=1;
			}
			else if (y == 4) {
				fscanf(doc, "%i", &pont);  
				y+=1;
			}
		} 
		pontuacao = pont;
	}
	fclose(doc);
}
 