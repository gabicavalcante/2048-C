#include <stdio.h>  
#include <stdlib.h> /* calloc,exit */
#include <termios.h>/*             */
#include <time.h>   /* for rand    */
#include <unistd.h> /* for getopts */ 
#include <string.h>

#include "carregar_pontos.h"
#include "salvar_pontos.h"
#include "mova.h"
#include "soma.h"
#include "gerar_aleatoriamente.h"
#include "validacao.h" 
#include "desenhe_mapa.h" 
#include "salvar_estado.h"
#include "entrada.h"
#include "recuperar_usuario.h"
#include "carregar_estado.h"
#include "comparar.h"
#include "copiar.h"
#include "voltar_jogada.h"
#include "verificar.h"

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
	 * - Por fim, chamamos salvar_estado() para guardar a pontuação e o estado da matriz;

	 * * A função mover chame 2 outras funções
	 	- mova: passando a tecla digitada e o tamanho do grid para que os números sejam movidos
	 	- soma: passando a tecla digitada e o tamanho do grid para que depois dos valores movidos, eles sejam somados

	 * * Função criar_matriz como #define 
	 	- Essa função foi baseado no código 2048 http://goo.gl/ZkLLoI
	*/

//Funçao que chama a função de movimento e soma dos números
void mover(int tecla, int tamanho_grid) {
    mova(tecla, tamanho_grid);
    soma(tecla, tamanho_grid);
    mova(tecla, tamanho_grid);
}				
	

#define criar_matriz(grid, sz)\
    do {\
        int i;\
        grid = calloc(sz, sizeof(*grid));\
        for (i = 0; i < sz; i++)\
            grid[i] = calloc(sz, sizeof(*grid));\
    } while (0)

int **g; //matriz (alocação dinâmica)

int **gcopia; //matriz copia da original

int **gtemp; //matriz que será usada para guardar os valores da matriz original para que possa ser verificada

int pontuacao = 0; //pontuação do jogador

char *file = ".ult_pontuacao"; //arquivo com a última pontuação

char file_estado[50]; //guarda o último estado do jogador

char *file_user = ".user"; //lista usuário que já jogaram

typedef struct {
	char nome[50];
	int pontos;
} Jogador;

int main(int argc, char **argv) {  

	Jogador jogador; //jogador criado com base no struct

    int tamanho_grid;
	tamanho_grid = 4;
	
	int ult_pontuacao;  
	char campeao[100];
	criar_matriz(g, tamanho_grid);
 	criar_matriz(gcopia, tamanho_grid);
    criar_matriz(gtemp, tamanho_grid);

	ult_pontuacao = carregar_pontos(ult_pontuacao, campeao);
	enum movimentos { Esquerda = 1, Direita = 2, Cima = 3, Baixo = 4};
	
	srand((unsigned)time(NULL)); 

	int i = 0; 
	char caminho[50] = "historico/";
	strcat(file_estado, caminho); //concatenando a string "historico/" com o que tiver no file_estado

	entrada(ult_pontuacao, jogador.nome, tamanho_grid);  
	//printf("%s\n", jogador.nome);
	//mando desenhar o mapa, passando a última pontuação e o tamanho definido da tabela
	desenhe_mapa(ult_pontuacao, tamanho_grid, campeao);
    
    //struct usado para escoder o que for digitado pelo usuário
    struct termios tattr; //vc precisa de uma estrutura terminos
    tcgetattr(STDIN_FILENO, &tattr); //int tcgetattr(int fildes, struct termios *termios_p);
    //para obter uma cópia de configurações 'termios struct' do tattr atual
    tattr.c_lflag &= ~(ICANON | ECHO); //atravez do atributo .c_lflag, desabilitamos o buffering e inibimos o eco do teclado para a tela
    tcsetattr(STDOUT_FILENO, TCSANOW, &tattr); // restaurar o terminal para suas configurações padrão originais
    
	int tecla;
	
	while(1) {
		repita:;  //ponto base para retornar logo depois que o usuário digitar algo
        tecla = getchar();
        
        switch (tecla) { 
            case 'a':
            case 68:
            	copiar(tamanho_grid); 
                mover(Esquerda, tamanho_grid);  
                break; 
            case 'd':
            case 67:
            	copiar(tamanho_grid); 
                mover(Direita, tamanho_grid);  
                break;
            case 's': 
            case 66:
            	copiar(tamanho_grid); 
                mover(Baixo, tamanho_grid);  
                break;
            case 'w':
            case 65:
            	copiar(tamanho_grid); 
                mover(Cima, tamanho_grid); 
                break;
            case 'r': 
                voltar_jogada(tamanho_grid);
                break;
            case 'q':
                salvar_pontos(ult_pontuacao, tamanho_grid, jogador.nome);
                exit(EXIT_SUCCESS);
            default:
                goto repita;
        } 
        system("clear"); 
        //sistem(pauser);
        if (comparar(tamanho_grid)) { 
        	gerar_aleatoriamente(ult_pontuacao, tamanho_grid); 
        } 
        
        desenhe_mapa(ult_pontuacao, tamanho_grid, campeao);
        salvar_estado(tamanho_grid);
        verificar(ult_pontuacao, tamanho_grid);
	} 
}
