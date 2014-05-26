#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
 
struct Jogador {
	char nome[50];
	int pontos;
};

char entrada(int ult_pontuacao) {
	struct Jogador jogador;
	printf("|-----------------------------------------------|\n");
	printf("|-----------------------------------------------|\n");
	printf("|-----------------------------------------------|\n");
	printf("|------------          2048         ------------|\n");
	printf("|-----------------------------------------------|\n");
	printf("|-----------------------------------------------|\n");
	printf("|-----------------------------------------------|\n");
	//printf("|-----|  USER  |----------------|  SCORE  |-----|\n");
	//printf("|-----|  USER  |----------------|  SCORE  |-----|\n"); 
	//printf("|-----|  USER  |----------------|  SCORE  |-----|\n");
	//printf("|-----|  USER  |----------------|  SCORE  |-----|\n");
	printf("\n");
	printf("|                Who are you? '-'               |\n");
	fgets(jogador.nome, sizeof(jogador.nome), stdin);
	jogador.nome[strlen(jogador.nome)-1] = '\0'; 
	int flag = 1;//recuperar_usuario(jogador.nome); 
	int i;
	if (!flag) {
		for (i = 0; i < 2; i++) 
			gerar_aleatoriamente(ult_pontuacao, 4);
	}
	return jogador.nome;
}
