/*
Repositório: Victor Hugo Santos

Ordem de multiplicação de n matrizes: por: Nivio Ziviani, Ph. D.
Professor Emérito do Departamento de Ciência da Computação
Universidade Federal de Minas Gerais
Membro da Academia Brasileiroas de Ciências

fonte: http://www2.dcc.ufmg.br/livros/algoritmos/cap2/codigo/c/2.10-avalia-mult-matrizes.c

*/

#include <stdio.h>
#include <limits.h>

#define MAXN 10

int main(int argc, char *argv[])
{
    int i, j, k, h, n, temp;
    int d[MAXN + 1];
    int m[MAXN][MAXN];
    printf("Numero de matrizes n:");
    scanf("%d%*[^\n]", &n);
    printf("Dimensoes das matrizes:");

    for (i = 0; i <= n; i++)
        scanf("%d", &d[i]);
    for (i = 0; i < n; i++)
        m[i][i] = 0;
    for (h = 1; h <= n - 1; h++)
    {
        for (i = 1; i <= n - h; i++)
        {
            j = i + h;
            m[i - 1][j - 1] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                temp = m[i - 1][k - 1] + m[k][j - 1] + d[i - 1] * d[k] * d[j];
                if (temp < m[i - 1][j - 1])
                    m[i - 1][j - 1] = temp;
            }
            printf(" m[ %d, %d]= %d", i - 1, j - 1, m[i - 1][j - 1]);
        }
        putchar('\n');
    }
    return 0;
}