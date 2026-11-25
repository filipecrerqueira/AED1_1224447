/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Filipe Siqueira e Cerqueira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1191
Data        : 26/08/2026
Objetivo    : Construir uma arvore e dominar a notação infixa pre fixa e pos fixa
Dificuldade : Medio
Uso de IA   : Auxilio no entendimento e para a organização das ideias, e explicar os ponteiros 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prefixo: raíz, sub-árvore esquerda, sub-árvore direita
// Infixo;  sub-árvore esquerda, raíz, sub-árvore direita

struct cel
{ // definindo a estutura de dados de uma arvore binaria e seus respectivos apelidos
    char conteudo;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel no;
typedef struct cel *arvore;

// Funcao para criar um novo no

no *criarNo(char conteudoNovo)
{
    no *novo;
    novo = malloc(sizeof(no));

    if (novo != NULL)
    {
        novo->conteudo = conteudoNovo;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    else
    {
        printf("Falha ao alocar um novo Nó \n");
        return NULL;
    }
}

arvore MontarArvore(char pre[], char in[], int inicio, int fim, int *idxPre)
{

    int pos;

    if (inicio > fim)
    {
        return NULL;
    }
    char LetraAtual = pre[*idxPre];
    *idxPre += 1;

    no *novo = criarNo(LetraAtual);

    for (size_t i = inicio; i <= fim; i++)
    {
        if (in[i] == LetraAtual)
        {

            pos = i;
            break;
        }
    }

    novo->esq = MontarArvore(pre, in, inicio, pos - 1, idxPre);
    novo->dir = MontarArvore(pre, in, pos + 1, fim, idxPre);

    return novo;
}

void EscreverArvoreEDR(arvore r)
{
    if (r != NULL)
    {
        EscreverArvoreEDR(r->esq);
        EscreverArvoreEDR(r->dir);
        printf("%c", r->conteudo);
    }
}


int main()
{

    char in[100], pre[100];

    while (scanf(" %s %s", pre, in) != EOF)
    {
        int idxPre = 0;
        int n = strlen(in);
        arvore raiz = MontarArvore(pre, in, 0, n - 1, &idxPre);
        EscreverArvoreEDR(raiz);
        printf("\n");
    }

    return 0;
}
