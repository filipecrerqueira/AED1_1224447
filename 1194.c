/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Filipe Siqueira e Cerqueira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 19/11/2026
Objetivo    : Pensar em prioridade
Dificuldade : alto
Uso de IA   : usei para entender o codigo postado e desenvolver as funções.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char valor;
    struct no *esq;
    struct no *dir;
} No;

// Cria um novo nó
No *criarNo(char valor) {

    No *novo = malloc(sizeof(No));

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

// Reconstrói a árvore usando prefixa e infixa
No *construir(char prefixa[], char infixa[],
              int inicio, int fim, int *pos) {

    if (inicio > fim)
        return NULL;

    // O próximo caractere da prefixa é a raiz
    char raiz = prefixa[(*pos)++];

    No *novo = criarNo(raiz);

    // Localiza a raiz na sequência infixa
    int i = inicio;

    while (infixa[i] != raiz)
        i++;

    // Constrói a subárvore esquerda
    novo->esq = construir(prefixa, infixa,
                          inicio, i - 1, pos);

    // Constrói a subárvore direita
    novo->dir = construir(prefixa, infixa,
                          i + 1, fim, pos);

    return novo;
}

// Percurso pós-fixo
void posfixa(No *raiz) {

    if (raiz == NULL)
        return;

    posfixa(raiz->esq);
    posfixa(raiz->dir);

    printf("%c", raiz->valor);
}

// Libera a memória da árvore
void liberar(No *raiz) {

    if (raiz == NULL)
        return;

    liberar(raiz->esq);
    liberar(raiz->dir);

    free(raiz);
}

int main() {

    int casos, n;
    char prefixa[55], infixa[55];

    scanf("%d", &casos);

    while (casos--) {

        scanf("%d %s %s", &n, prefixa, infixa);

        int pos = 0;

        // Reconstrói a árvore
        No *raiz = construir(prefixa, infixa,
                             0, n - 1, &pos);

        // Imprime o percurso pós-fixo
        posfixa(raiz);

        printf("\n");

        // Libera a memória utilizada
        liberar(raiz);
    }

    return 0;
}
