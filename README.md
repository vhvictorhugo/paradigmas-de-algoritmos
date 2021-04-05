# paradigmas-de-algoritmos

Repositório criado com o intuito de auxiliar nos estudos da disciplina CCF 330 - Projeto e Análise de Algoritmos na Universidade Federal de Viçosa - campus Florestal, lecionada pelo professor [Daniel Mendes Barbosa](http://lattes.cnpq.br/7748886713666472) na [UFV - campus Florestal](https://www.ufv.br/campus-florestal/).



# Objetivo

<p> Neste repositório serão disponibilizados alguns algoritmos que trabalham alguns dos principais paradigmas de projeto de algoritmos, são eles:
</p>

* Backtracking
  * Passeio do cavalo
* Divisão e Conquista
  * Binary Search Tree
* Programação Dinâmica
  * Ordem da multiplicação de n matrizes



Agradecimentos ao Professor Emérito Nivio Ziviani do [Departmento de Ciência da Computação](http://www.dcc.ufmg.br/) da [UFMG](http://www.ufmg.br/) pela disponibilização das implementações e também ao professor Daniel Mendes pelos ensinamentos.



# Execução

​    

#### Requisitos:

1. Make
2. Compilador C



#### Passo a passo:

1. Abra o terminal na pasta do algoritmo escolhido
   * /BST
   * /cavalo
   * /ordem-multiplicacao-matrizes

2. $ make
3. $ make run



### BST

"Em Ciência da computação, uma **árvore binária de busca** (binary search tree) é uma estrutura de dados baseada em nós, onde todos os nós da subárvore esquerda possuem um valor numérico inferior ao nó raiz e todos os nós da subárvore direita possuem um valor superior ao nó raiz." - [Wikipédia](https://pt.wikipedia.org/wiki/%C3%81rvore_bin%C3%A1ria_de_busca)



A implementação conta com as operações de: inserir, pesquisar, apresentar quantidade de nós, maior elemento inserido, profundidade do nó, pré-ordem, etc.



### Passeio do Cavalo

"O **problema do cavalo**, ou **passeio do cavalo**, é um problema matemático envolvendo o movimento da peça do cavalo no tabuleiro de xadrez. O cavalo é colocado no tabuleiro vazio e, seguindo as regras do jogo, precisa passar por todas as casas exatamente uma vez em movimentos consecutivos." - [Wikipédia](https://pt.wikipedia.org/wiki/Problema_do_cavalo)



A implementação recebe o parâmetro n que cria uma matriz n x n e também a posição inicial do cavalo. A partir destes, a implementação informa se há ou não solução. Se existir, apresenta a matriz com as posições marcadas pelo índice da movimentação do cavalo nas n x n posições.



### Ordem da multiplicação de n matrizes

"Considere o produto de uma maitrz p x q por outra matriz q x r cujo algoritmo requer O(pqr) operações. Considere o produto:

M = M1[10,20] x M2[20,50] x M3[50,1] x M4[1,100],

em que as dimensões de cada matriz são mostradas entre colchetes. A avaliação de M na ordem M = M1 x (M2 x (M3 x M4)) requer 125.000 operações, enquanto a avaliação de M na ordem M = (M1 x (M2 x M3)) x M4 requer apenas 2.200 operações." - ZIVIANI, Nivio, et al. Projeto de Algoritmos com Implementações em Pascal e C. 2011.



Pensando no problema, o algoritmo obtém o custo mínimo para multiplicar as n matrizes, assumindo que são necessárias pqr operações para multiplicar uma matriz p x q por outra matriz q x r.





### Autor: Victor Hugo Santos







