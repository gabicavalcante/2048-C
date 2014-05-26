#include <stdio.h>  
#include <stdlib.h> /* calloc,exit */
#include <termios.h>/*             */
#include <time.h>   /* for rand    */
#include <unistd.h> /* for getopts */ 
#include "carregar_pontos.h"
#include "salvar_pontos.h"
#include "mova.h"
#include "soma.h"
#include "gerar_aleatoriamente.h"
#include "espaco_esquerda.h" 
#include "desenhe_mapa.h" 
#include "salvar_estado.h"
#include "entrada.h"
#include "recuperar_usuario.h"
#include "carregar_estado.h"

	/* 
	 * No main 
	 * - Definimos o tamanho do grid (tamanho_grid);
	 * - Criamos uma variável que armazena o valor da última pontuação (ult_pontuacao);
	 * - Chamamos a função preencher(g, tamanho_grid), passando como parâmetros o grid e o tamanho do grid;
	 * - A variável ult_pontuacao recebe o retorno da função carregar_pontos(ult_pontuacao);
	 * - Criamos uma semente que será usada para criar valores "aleatórios" (srand((unsigned)time(NULL));)
	 * - Chamamos a função entrada(ult_pontuacao); passando a variável última pontuação
	 * - Chamamos a função desenhe_mapa(ult_pontuacao, tamanho_grid), que irá desenhar o mapa com a última pontuação e obedecendo o tamanho do grid
	 * - Depois há o loop que pegará o valor digitado e (a,w,d,s) e chamará a função de mover, passando o sentindo e tamanho do grid;
	 * - Depois de sair do switch que pega a tecla digitada a função gerar_aleatoriamente() é chamada novamente, depois da matriz ter recebido novos valores, o mapa é desenhado chamando a função desenhe_mapa();
	 	 A função que gera números aleatórios em C é a rand(). 
	 * Ela gera números entre 0 e RAND_MAX, onde esse RAND_MAX é um valor que pode variar de máquina pra máquina.
	 * Pra usar a função rand(), temos que adicionar a biblioteca time.h e para saber o valor de RAND_MAX, temos que usar a função stdlib.h.
	 * Para que a sequencia não seja sempre a mesma, usamos a função rand() com uma semente, com um número, que é o tempo atual.
	 * Assim, toda vez que rodarmos o programa, a rand() pega um número de tempo diferente e gera uma seqüencia diferente. 
	 * Para fazer isso, basta usar a função srand(), que será responsável por alimentar a rand().
	 *
	 * calloc é uma função da biblioteca stdlib.h, da linguagem de programação C. 
	 * Seu objetivo é criar um vetor de tamanho dinâmico, ou seja, definido durante a execução do programa. 
	 * Difere da função malloc, também de C, pois além de inicializar os espaços de memória ainda atribui o valor 0 (zero) para cada um deles. 
	 *  útil, pois em C quando se declara um variável o espaço no mapa de memória usado por esta provavelmente contém algum valor lixo.
	 */

void mover(int tecla, int tamanho_grid) {
    mova(tecla, tamanho_grid);
    soma(tecla, tamanho_grid);
    mova(tecla, tamanho_grid);
}				
	
/*  void preencher(int grid, int tamanho) {     																		
	   int i;                                                                                  
	   grid = calloc(tamanho, sizeof(*grid));                                                  
	   for (i = 0; i < tamanho; i++) 														   
		   grid[i] = calloc(tamanho, sizeof(*grid));									   
}*/

#define preencher(grid, sz)\
    do {\
        int i;\
        grid = calloc(sz, sizeof(*grid));\
        for (i = 0; i < sz; i++)\
            grid[i] = calloc(sz, sizeof(*grid));\
    } while (0)

int **g;
 
int pontuacao = 0;

char *file = ".ult_pontuacao";

char *file_estado = "historico/.ult_estado";

char *file_user = ".user";

int main(int argc, char **argv) {  
		
    int tamanho_grid;
	tamanho_grid = 4;
	
	int ult_pontuacao;  
	preencher(g, tamanho_grid);

	ult_pontuacao = carregar_pontos(ult_pontuacao);
	enum movimentos { Esquerda = 1, Direita = 2, Cima = 3, Baixo = 4};
	
	srand((unsigned)time(NULL)); 
	 
	int i = 0; 
	
	char jogador[50];
	jogador = entrada(ult_pontuacao);	
		
	desenhe_mapa(ult_pontuacao, tamanho_grid);
    
    struct termios tattr;
    tcgetattr(STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDOUT_FILENO, TCSANOW, &tattr);
    
	int tecla;
	
	while(1) {
		repita:;   
        tecla = getchar();
        
        switch (tecla) { 
            case 'a':
                mover(Esquerda, tamanho_grid);
                break; 
            case 'd':
                mover(Direita, tamanho_grid);
                break;
            case 's': 
                mover(Baixo, tamanho_grid);
                break;
            case 'w':
                mover(Cima, tamanho_grid);
                break;
            case 'q':
                salvar_pontos(ult_pontuacao, tamanho_grid);
                exit(EXIT_SUCCESS);
            default:
                goto repita;
        } 
        gerar_aleatoriamente(ult_pontuacao, tamanho_grid); 
        desenhe_mapa(ult_pontuacao, tamanho_grid);
        salvar_estado(tamanho_grid);
	} 
}
