/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Filipe Siqueira e Cerqueira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 25/11/2026
Objetivo    : Construir uma arvore e dominar a noção de niveis e contagem dos mesmos
Dificuldade : Medio
Uso de IA   : Auxilio no entendimento e para a organização das ideias
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel
{
    int conteudo;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel *arvore;
typedef struct cel no;

no *criarNO(int valores)
{
    no *novo;                  // criando um novo ponteiro para o no
    novo = malloc(sizeof(no)); // casting de memoria, reserva espaço para estrutura da forma no

    if (novo != NULL) // testando se o alocamento foi feito corretamente
    {
        novo->conteudo = valores; // cria uma folha com o conteudo passado pela main e os ponteiros sem apontar pra nada
        novo->esq = novo->dir = NULL;
        return novo;
    }
    else
    {
        printf("Alocação falhou!\n");
        return NULL;
    }
}

arvore InsereR(arvore r, no *novo)
{
    if (r == NULL)
        return novo;

    if (r->conteudo > novo->conteudo)
        r->esq = InsereR(r->esq, novo);
    else
        r->dir = InsereR(r->dir, novo);

    return r;
}

void ImprimeLargura(arvore r)
{ // usando a ideia de FIFO

    if (r == NULL)
    {
        return;
    }

    int inicio = 0;
    int fim = 0;
    no *fila[510]; // Para armazenar os nos precisamos de uma estrutura de nos, e como estamos manipulando coisas de outras funções precisamos do ponteiro

    fila[fim++] = r; // coloca a raiz no fim da fila

    while (inicio < fim)
    {
        no *atual = fila[inicio++];

        if (atual == r) // condição para saber se escreve com ou sem espaço antes, caso seja a raiz, esse imprime com o espaço antes

        {
            printf("%d", atual->conteudo);
        }
        else
        {
            printf(" %d", atual->conteudo);
        }

        if (atual->esq != NULL) // armazenando ponteiros na fila
        {
            fila[fim++] = atual->esq;
        }
        if (atual->dir != NULL)
        {
            fila[fim++] = atual->dir;
        }
    }
    printf("\n");
}

int main()
{
    int casos;
    int NumerodeNos;
    int valores;

    scanf("%d", &casos);

    for (int c = 1; c <= casos; c++)
    {
        arvore r = NULL; // zerando a árvore para o novo caso

        scanf("%d", &NumerodeNos);
        printf("Case %d:\n", c);

        for (int i = 0; i < NumerodeNos; i++)
        {
            scanf("%d", &valores);
            r = InsereR(r, criarNO(valores));
        }

        ImprimeLargura(r);
        printf("\n");
    }

    return 0;
}
