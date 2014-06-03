#include <stdio.h>  
#include "validacao.h"
#include "mova.h"
#include "copiar.h"
#include "comparar.h"
#include "voltar_jogada.h"
#include "copiar.h"
#include "desenhe_mapa.h"


/*
 * Este documento agrupa 4 pequenas funções que tem por objetivo fazer a validação da matriz
 * func conferir_vazio() - a função verifica se há espaço vazio
 * @param int tamanho_grid - tamanho da matriz do jogo 
 * @return se ainda tiver espaço vazio a função irá retornar 1, caso controário retornará 0
 * func possibilidade_movimento() - a função vai copiar a matriz atual do jogo para um outras matriz, realizará todos os 
 * possíveis movimentos, e no fim, irá compará a matriz cópia com a matriz depois das modificações feitas, caso haja alguma
 * diferença é por que é possível ainda fazer movimentos, caso sejam identicas, é pq não é possível mover nenhum dos números. 
 * Depois do processo, a matriz do jogo será resetada para o estado original
 * @params int tamanho_grid - tamanho da matriz do jogo 
 * @return a função irá retorno 1 caso hoja diferença entre as matrizes (ou seja, há movimentos que podem ser feitos), e 
 * retornará 0 caso não haja diferença
 * func resetar() - vai deixar a matriz do jogo com os valores iniciais
 * @params int tamanho_grid - tamanho da matriz do jogo 
 * func ver_se_ganhou() - Verifica se há algum valor 2048 na matriz
 * @params int tamanho_grid - tamanho da matriz do jogo 
 * @return caso haja, vai retornar 1, caso contrário retornará 0
 */

int conferir_vazio(int tamanho_grid) {
	int i, j;
    for (i = 0; i < tamanho_grid; i++) {
        for (j = 0; j < tamanho_grid; j++) {
            if (g[i][j] == 0) { //verificar se estão vazias
                return 1; 
            }
        }
    }
    return 0;
}

/*int ver_par(int tamanho_grid) {
    int i, j;
    for (i = 0; i < tamanho_grid-1; i++)  {
        for (j = 0; j < tamanho_grid-1; j++) { 
            if ((j < tamanho_grid-1) && (i < tamanho_grid-1) && (g[i][j] == g[i][j+1]) || (g[i][j] == g[i+1][j])) {
                return 1;
            }
        }
    }
    return 0;
}*/

int possibilidade_movimento(int tamanho_grid) {
    int flag = 0;
    int i = 0, j = 0; 
    int pot_temp = pontuacao;
    for (i = 0; i < tamanho_grid; i++)
    {   
        for (j = 0; j < tamanho_grid; j++)
        {
            gtemp[i][j] = g[i][j];
        }
    }

    mover(1, tamanho_grid);
    mover(2, tamanho_grid);
    mover(3, tamanho_grid);
    mover(4, tamanho_grid);

    pontuacao = pot_temp;
    for (i = 0; i < tamanho_grid; i++)
    {
        for (j = 0; j < tamanho_grid; j++)
        {
           if (gtemp[i][j] != g[i][j]) {
                resetar(tamanho_grid);
                return 1;
            }
        }
    }
    return 0;
}

void resetar (int tamanho_grid) {
    int i = 0, j = 0;
    for (i = 0; i < tamanho_grid; i++)
    {   
        for (j = 0; j < tamanho_grid; j++)
        {
            g[i][j] = gtemp[i][j];
        }
    }
}

int ver_se_ganhou(int tamanho_grid) {
    int i, j;
    for (i = 0; i < tamanho_grid; i++) {
        for (j = 0; j < tamanho_grid; j++) {
            if (g[i][j] == 2048) { //se a casa tem 2048
                return 1; 
            }
        }
    }
    return 0;
}


