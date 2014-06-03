#include <stdio.h>  
#include <stdlib.h> /* calloc, exit  */
#include "gerar_aleatoriamente.h"
#include "carregar_pontos.h"
#include "mova.h"
#include "desenhe_mapa.h"
#include "validacao.h"

int verificar(int ult_pontuacao, int tamanho_grid) {
  if (ver_se_ganhou(tamanho_grid)) { 
    printf("\n"
      "AÊ campeão, você ganhou.\n"
      "Sua pontuação foi: %i \n", pontuacao);
      salvar_pontos(ult_pontuacao, tamanho_grid, file);
      exit(EXIT_SUCCESS);
  }

  else if (!(possibilidade_movimento(tamanho_grid)) && !(conferir_vazio(tamanho_grid))){ 
    printf("\n"
      "Você perdeu.\n"
      "Sua pontuação foi: %i \n", pontuacao);
      salvar_pontos(ult_pontuacao, tamanho_grid, file);
      exit(EXIT_SUCCESS);
  }
}