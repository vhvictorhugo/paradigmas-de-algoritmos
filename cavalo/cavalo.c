#include "cavalo.h"

int cavalo(int m[MAX][MAX], int n, int x, int y)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            m[i][j] = 0;
    m[x][y] = 1;
    return cavaloR(m, n, x, y);
}

void proxima_posicao(int l, int c, int k, int *nl, int *nc)
{
    static int movimentos[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    *nl = l + movimentos[k][0];
    *nc = c + movimentos[k][1];
}

int cavaloR(int m[MAX][MAX], int n, int l, int c)
{
    int k, nl, nc;
    if (m[l][c] == n * n)
        return 1;
    for (k = 0; k < 8; k++)
    {
        proxima_posicao(l, c, k, &nl, &nc);
        if ((nl >= 0) && (nl < n) && (nc >= 0) && (nc < n) && (m[nl][nc] == 0))
        {
            m[nl][nc] = m[l][c] + 1;
            if (cavaloR(m, n, nl, nc))
                return 1;
            m[nl][nc] = 0;
        }
    }
    return 0;
}