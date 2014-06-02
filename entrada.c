#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "entrada.h" 
#include "desenhe_mapa.h"
#include "recuperar_usuario.h"
#include "acrescentar_usuario.h"
#include "gerar_aleatoriamente.h"
#include "copiar.h"

/*
 * Esta função funciona como "entrada", imprimindo um menu inicial, com a opção de começar novo jogo, recuperar estado de algum
 * último jogo, ou sair. Além de pegar o nome do jogador e acrescentar ele na lista de usuário ou recuperar o histórico dele
 * @param int ult_pontuacao - valor da última maior pontuação
 * @param char* nome - variável no nome do jogador, como ela é um ponteiro, quando for modificada, a alteração vai permanecer 
 * fora da função
 * @param int tamanho_grid - tamanho da matriz do jogo 
 */

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
	//scanf("%[^\n]", &digito);
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
        	strcat(file_estado, nome); //concatenando o string que há em file_estado com o nome do usuário
									   //correspondendo ao caminho para o arquivo onde há o última estado e última pontuação
        	
        	int i;
        	for (i = 0; i < 2; i++) {
        		gerar_aleatoriamente(ult_pontuacao, tamanho_grid);
            }
            copiar(tamanho_grid);
            break;  

        case 2: 
        	printf("|~~~~~~~~~~~~~~~~~Digite seu nome~~~~~~~~~~~~~~~|\n"); 
        	scanf("%s", nome); 

        	strcat(file_estado, nome); //concatenando o string que há em file_estado com o nome do usuário
									   //correspondendo ao caminho para o arquivo onde há o última estado e última pontuação
			int flag; 
			recuperar_usuario(nome); 
			if (flag == 0) {
				for (i = 0; i < 2; i++) {
					gerar_aleatoriamente(ult_pontuacao, tamanho_grid);
                }
			} 
            copiar(tamanho_grid);

            break;

        case 3: 
        case 'q': 
        	/*        	/*printf("Tem certeza que quer sair do jogo? (y/n)\n");
        	char c;
        	c = getchar();
			if ((c == 'y') || (c == 'Y')) {
 				exit(EXIT_SUCCESS); 
 			}
 			else if ((c == 'n') || (c == 'N')) { */
        	system("clear");
        	//goto inicio;
        	//}*/
            exit(EXIT_SUCCESS); 
    } 
}
