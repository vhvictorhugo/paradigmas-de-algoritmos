// Victor Hugo
// Adaptação Nivio Ziviani
// AEDS 2

#include <stdio.h>
#include <stdlib.h>

typedef int TipoRegistro;
typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
    TipoRegistro registro;
    TipoApontador esq, dir;
} TipoNo;

typedef TipoApontador TipoDicionario;

// principais funcoes

void inicializa(TipoApontador *no);
void insere(TipoApontador *no, TipoRegistro x);
int pesquisa(TipoApontador *no, TipoRegistro x);
void retira(TipoApontador *no, TipoRegistro reg);

// funcoes auxiliares

void percorre_preOrdem(TipoApontador *no);
void percorre_Ordem(TipoApontador *no);
void percorre_posOrdem(TipoApontador *no);
void percorre_decrescente(TipoApontador *no);
int calcula_altura(TipoApontador no);
void antecessor(TipoApontador q, TipoApontador *r);
int numeroNos(TipoApontador no);
int maiorElemento(TipoApontador no);
int profundidadeNo(TipoApontador no, TipoRegistro x);
