/*
Repositório: Victor Hugo Santos

Binary Search Tree feita com o auxílio das implementações do professor Nivio Ziviani, Ph. D.

fonte: http://www2.dcc.ufmg.br/livros/algoritmos/cap5/codigo/c/5.4a5.10-arvorebinaria.c
*/

#include "BST.h"

void inicializa(TipoApontador *no)
{
    *no = NULL;
    printf("Arvore inicializada com sucesso.\n");
    return;
}

void insere(TipoApontador *no, TipoRegistro x)
{
    if (*no == NULL)
    {
        *no = (TipoApontador)malloc(sizeof(TipoNo));
        (*no)->registro = x;
        (*no)->esq = NULL;
        (*no)->dir = NULL;
        return;
    }
    if (x < (*no)->registro)
    {
        insere(&((*no)->esq), x);
        return;
    }
    if (x > (*no)->registro)
        insere(&((*no)->dir), x);
    else
        printf("Erro: Registro j� existe na arvore.\n");
}

int pesquisa(TipoApontador *no, TipoRegistro x)
{

    if ((*no) == NULL)
    {
        return 0;
    }
    else if ((*no)->registro == x)
    {
        return 1;
    }
    else if ((*no)->registro > x)
    {
        pesquisa(&(*no)->esq, x);
    }

    else if ((*no)->registro < x)
    {
        pesquisa(&(*no)->dir, x);
    }
}

void percorre_preOrdem(TipoApontador *no)
{
    if (*no == NULL)
        return;
    if (*no != NULL)
    {
        printf("%d\n", (*no)->registro);
        percorre_preOrdem(&(*no)->esq);
        percorre_preOrdem(&(*no)->dir);
    }
}

void percorre_Ordem(TipoApontador *no)
{
    if (*no == NULL)
        return;
    if (*no != NULL)
    {
        percorre_Ordem(&(*no)->esq);
        printf("%d\n", (*no)->registro);
        percorre_Ordem(&(*no)->dir);
    }
}

void percorre_posOrdem(TipoApontador *no)
{
    if (*no == NULL)
        return;
    if (*no != NULL)
    {
        percorre_posOrdem(&(*no)->esq);
        percorre_posOrdem(&(*no)->dir);
        printf("%d\n", (*no)->registro);
    }
}

int calcula_altura(TipoApontador no)
{
    if (no == NULL)
        return -1; //altura de uma arvore vazia
    else
    {
        int he = calcula_altura(no->esq);
        int hd = calcula_altura(no->dir);

        if (he < hd)
            return hd + 1;
        else
            return he + 1;
    }
}

void antecessor(TipoApontador q, TipoApontador *r)
{
    if ((*r)->dir != NULL)
    {
        antecessor(q, &(*r)->dir); // chamada recursiva para encontrar o antecessor (maior na subarvore a esquerda)
        return;
    }
    q->registro = (*r)->registro;
    q = *r;
    *r = (*r)->esq;
    free(q);
}

void retira(TipoApontador *no, TipoRegistro reg)
{

    TipoApontador Aux;

    // caso base
    if (*no == NULL)
    {
        printf("Erro: Arvore vazia ou registro ausente.\n");
        return;
    }

    // chamada recursiva

    if (reg < (*no)->registro)
    {
        retira(&(*no)->esq, reg);
        return;
    }

    if (reg > (*no)->registro)
    {
        retira(&(*no)->dir, reg);
        return;
    }

    // tratando os 3 casos de remocao

    if ((*no)->dir == NULL)
    {
        Aux = *no;
        *no = (*no)->esq;
        free(Aux);
        return;
    }

    if ((*no)->esq != NULL)
    {
        antecessor(*no, &(*no)->esq);
        return;
    }

    Aux = *no;
    *no = (*no)->dir;
    free(Aux);
}

int numeroNos(TipoApontador no)
{

    if (no == NULL)
    {
        return 0;
    }

    int cont = 1; // se arvore nao e nula, entao pelo menos ela possui o no raiz

    cont += numeroNos(no->dir); // a cada chamada recursiva com sucesso, soma 1
    cont += numeroNos(no->esq);

    return cont;
}

int maiorElemento(TipoApontador no)
{ // o maior elemento estara mais a direita na subarvore direita
    if (no == NULL)
    {
        return 0;
    }
    if (no->dir != NULL)
        return maiorElemento(no->dir);

    return no->registro;
}

int profundidadeNo(TipoApontador no, int x)
{
    if (no == NULL)
        return -2;
    int cont = 1;
    if (x < no->registro)
    {
        return cont += profundidadeNo(no->esq, x);
    }
    if (x > no->registro)
    {
        return cont += profundidadeNo(no->dir, x);
    }
    return cont - 1;
}

void percorre_decrescente(TipoApontador *no)
{
    if (*no == NULL)
    {
        return;
    }
    if (*no != NULL)
    {
        percorre_decrescente(&(*no)->dir);
        printf("%d\n", (*no)->registro);
        percorre_decrescente(&(*no)->esq);
    }
}
