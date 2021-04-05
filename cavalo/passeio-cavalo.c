/*
Repositório: Victor Hugo Santos

Passeio do cavalo: por: Nivio Ziviani, Ph. D.
Professor Emérito do Departamento de Ciência da Computação
Universidade Federal de Minas Gerais
Membro da Academia Brasileiroas de Ciências

fonte: http://www2.dcc.ufmg.br/livros/algoritmos/cap2/codigo/c/2.6-2.7-passeiocavalo.c

Para execução de outros parâmetros, altere n e a posição inicial do cavalo

*/

#include <stdio.h>
#include <stdlib.h>

#define n 8 /* Tamanho do lado do tabuleiro */
#define FALSE 0
#define TRUE 1

int i, j;
int t[n][n];
short q;
int a[n], b[n];

void Tenta(int i, int x, int y, short *q)
{
    int u, v;
    int k = -1;
    short q1;
    /* inicializa selecao de movimentos */
    do
    {
        ++k;
        q1 = FALSE;
        u = x + a[k];
        v = y + b[k];
        if (u >= 0 && u < n && v >= 0 && v < n)
            if (t[u][v] == 0)
            {
                t[u][v] = i;
                if (i < n * n)
                {                            /* tabuleiro nao esta cheio */
                    Tenta(i + 1, u, v, &q1); /* tenta novo movimento */
                    if (!q1)
                        t[u][v] = 0; /* nao sucedido apaga registro anterior */
                }
                else
                    q1 = TRUE;
            }
    } while (!(q1 || k == 7));
    /* nao existem mais casas a visitar a partir de x,y */
    *q = q1;
}

int main(int argc, char *argv[])
{ /* programa principal */
    a[0] = 2;
    a[1] = 1;
    a[2] = -1;
    a[3] = -2;
    b[0] = 1;
    b[1] = 2;
    b[2] = 2;
    b[3] = 1;
    a[4] = -2;
    a[5] = -1;
    a[6] = 1;
    a[7] = 2;
    b[4] = -1;
    b[5] = -2;
    b[6] = -2;
    b[7] = -1;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            t[i][j] = 0;
    t[0][0] = 1; /* escolhemos uma casa do tabuleiro */
    Tenta(2, 0, 0, &q);
    if (!q)
    {
        printf("Sem solucao\n");
        return 0;
    }
    puts("Os numeros indicam o indice que aquela posicao foi acessada!");
    puts("Solucao:");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf(" %4d", t[i][j]);
        putchar('\n');
    }
    return 0;
}
