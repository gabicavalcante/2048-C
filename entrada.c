#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "entrada.h" 
#include "desenhe_mapa.h"
#include "recuperar_usuario.h"
#include "acrescentar_usuario.h"

void entrada(int ult_pontuacao, char* nome, int tamanho_grid) { 
	printf("|-----------------------------------------------|\n");
	printf("|-----------------------------------------------|\n");
	printf("|-----------------------------------------------|\n");
	printf("|------------          2048         ------------|\n");
	printf("|-----------------------------------------------|\n");
	printf("|-----------------------------------------------|\n");
	printf("|-----------------------------------------------|\n");
	printf("|--                              ---------------|\n");
	printf("|-- 1 ) Começar novo jogo        ---------------|\n");
	printf("|-- 2 ) Recuperar estado de jogo ---------------|\n");
	printf("|-- 3 ) Sair                     ---------------|\n");
	printf("|--                              ---------------|\n");
	printf("|-----------------------------------------------|\n");
	printf("\n"); 

	int digito;
	scanf("%d", &digito);
	printf("\n");
	switch (digito) { 
        case 1:  
        	/* Caso o usuário escolha a opção 1 do menu, o jogo vai gerar valores aleatórios
        	 * para preencher a matriz, e criar um novo arquivo para salvar o estado e a 
        	 * pontuação do jogador,
        	 */
        	printf("|~~~~~~~~~~~~~~~~~Digite seu nome~~~~~~~~~~~~~~~|\n"); 
        	scanf("%s", nome);   
        	acrescentar_usuario(nome); 
        	int i;
        	for (i = 0; i < 2; i++) 
        		gerar_aleatoriamente(ult_pontuacao, tamanho_grid);
            
            break;  

        case 2: 
        	printf("|~~~~~~~~~~~~~~~~~Digite seu nome~~~~~~~~~~~~~~~|\n"); 
        	scanf("%s", nome); 
        	 
			int flag; 
			recuperar_usuario(nome); 
			if (!flag) {
				for (i = 0; i < 2; i++) 
					gerar_aleatoriamente(ult_pontuacao, tamanho_grid);
			} 

            break;

        case 3: 
        case 'q': 
            exit(EXIT_SUCCESS); 
    } 
}
