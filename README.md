2048 em C
=========

####Código desenvolvido para o projeto de PRÁTICAS DE TÉCNICAS DE PROGRAMAÇÃO da Universidade Federal do Rio Grande do Norte.


O jogo possui uma entrada em que o usuário escolhe por começar um novo jogo, recuperar um jogo anterior ou sair.

1. Caso ele queira começar um novo jogo, e já haja algum registro dele como pontuação e estado do último jogo, eles serão sobrescritos. Se o jogador estiver entrando no jogo pela primeira vez, o nome dele será adicionado na lista de usuário que já usário o 2048, e a pontuação junto com a matriz será salva a cada movimento.
2. Caso ele queira recuperar um jogo anterior, basta digitar o nome do usuário que usou e o estado será recuperado. Caso ele digite um nome ainda não usado, ou seja, sem dados salvos anteriormente, o jogo começará um jogo do início.

Junto com o tabuleiro, o jogo apresenta a melhor última pontuação, junto com o usuário que a conquistou e a pontuação atual do jogador.

O usuário ainda tem a opção de voltar uma jogada durante o jogo clirando na letra 'r'. Não é possível voltar a jogada caso você saia do jogo e recupere seu estado.

Se você fizer movimentos que não desloque números, o jogo não irá gerar outros valores, ele irá aguardar o movimento dos números para isso. 

Caso o jogo perceba a presença do número 2048, ele vai avisar que você ganhou. Mas caso ele perceba que não há mais espaços vazio, nem possbilidades de movimentos, ele irá avisar que você perdeu.

No módulo do jogo no terminal, você não precisa clicar enter a cada comando e nem verá o eco do que digitou na tela, a não ser quando for digitar o seu nome. A biblioteca realacionada a isso é a terminos.h. Com ela, é possível desativas o eco, a necessidade de clicar enter, e até mesmo bloquear comandos como ctrl+c. No código do jogo há comentários explicando exatamente esta parte.

O jogo fez uso de alocação dinâmica, como ensinada pelo professor da disciplina. Criamos um ponteiro de um ponteiro, a para criar os vetores no vetor principal usamos a função calloc. Também utilizamos struct e typedef, eles formam a estrutura que representa o Jogador (com nome e pontuação). O programa está todo modularizado em diferentes arquivos (.c e .h). Seguimos obedecente a identação e tentando deixar o código mais legível possível. No início de cada arquivo há uma descrição do que ele realiza, quais parâmetros recebe e o que ele retorna.

