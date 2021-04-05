/*
Repositório: Victor Hugo Santos

Binary Search Tree feita com o auxílio das implementações do professor Nivio Ziviani, Ph. D.

fonte: http://www2.dcc.ufmg.br/livros/algoritmos/cap5/codigo/c/5.4a5.10-arvorebinaria.c
*/

#include "BST.h"

int main()
{
    TipoDicionario arvore;
    inicializa(&arvore);

    TipoRegistro valor, valor_remov, pesq;

    int opcao, resultadoPesq, numero_nos, maior, no_profundidade;

    do
    {
        printf("Selecione a opcao:\n");
        printf("\n1 - Inserir\n2 - Pesquisar\n3 - Numero de Nos\n4 - Maior Elemento\n5 - Profundidade No\n6 - Pre-Ordem\n7 - Ordem\n8 - Pos-Ordem\n9 - Remover\n10 - Altura\n11 - Decrescente\n0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 0:

            printf("Ate logo!\n");
            exit(1);

        case 1:

            printf("Insira o valor:\n");
            scanf("%d", &valor);
            insere(&arvore, valor);
            break;

        case 2:

            printf("Pesquisar chave:\n");
            scanf("%d", &pesq);

            resultadoPesq = pesquisa(&arvore, pesq);

            if (resultadoPesq == 1)
                printf("Registro presente.\n");
            else
                printf("Pesquisa sem sucesso.\n");
            break;

        case 3:

            numero_nos = numeroNos(arvore);
            printf("Quantidade de nos: %d\n", numero_nos);
            break;

        case 4:

            maior = maiorElemento(arvore);
            printf("Maior Elemento: %d\n", maior);
            break;

        case 5:

            printf("Qual no?\n");
            scanf("%d", &no_profundidade);
            printf("Profundidade no: %d\n", profundidadeNo(arvore, no_profundidade));
            break;

        case 6:

            printf("Pre Ordem:\n");
            percorre_preOrdem(&arvore);
            break;

        case 7:

            printf("Em Ordem:\n");
            percorre_Ordem(&arvore);
            break;

        case 8:

            printf("Pos Ordem:\n");
            percorre_posOrdem(&arvore);
            break;

        case 9:

            printf("Digite o valor a ser removido:\n");
            scanf("%d", &valor_remov);

            retira(&arvore, valor_remov);
            break;

        case 10:

            printf("Altura: %d\n", calcula_altura(arvore));
            break;

        case 11:

            printf("Ordem decrescente:\n");
            percorre_decrescente(&arvore);
            break;

        default:
            puts("Entre com um valor valido!");
            break;
        }
        puts("");
        system("pause");

    } while (opcao != 0);

    return 0;
}
