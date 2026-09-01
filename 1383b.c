/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Filipe Siqueira e Cerqueira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 28/08/2026
Objetivo    : Verificar um tabuleiro de sudoku usando alocacao dinamica na matriz
Dificuldade : Medio
Uso de IA   : Auxilio no entendimento da alocacao de ponteiros duplos (**int)
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int verificacao_linhas(int **sudoku, int linha);
int verificacao_colunas(int **sudoku, int coluna);
int verificacao_bloco(int **sudoku, int linha_inicio, int coluna_inicio);

int verificacao_linhas(int **sudoku, int linha)
{
    int verif[9] = {0}; // Inicializa todas as posicoes com 0

    for (size_t i = 0; i < 9; i++)
    {
        int pos = sudoku[linha][i] - 1;
        if (verif[pos] == 0)
        {
            verif[pos] = 1;
        }
        else
        {
            return 0; // Numero repetido na linha
        }
    }
    return 1;
}

int verificacao_colunas(int **sudoku, int coluna)
{
    int verif[9] = {0}; // Inicializa todas as posicoes com 0

    for (size_t i = 0; i < 9; i++)
    {
        int pos = sudoku[i][coluna] - 1;
        if (verif[pos] == 0)
        {
            verif[pos] = 1;
        }
        else
        {
            return 0; // Numero repetido na coluna
        }
    }
    return 1;
}

int verificacao_bloco(int **sudoku, int linha_inicio, int coluna_inicio)
{
    int verif[9] = {0}; // Inicializa todas as posicoes com 0

    for (int i = linha_inicio; i < linha_inicio + 3; i++)
    {
        for (int j = coluna_inicio; j < coluna_inicio + 3; j++)
        {
            int pos = sudoku[i][j] - 1;

            if (verif[pos] == 0)
            {
                verif[pos] = 1;
            }
            else
            {
                return 0; // Numero repetido no bloco 3x3
            }
        }
    }
    return 1;
}

int main()
{
    int **sudoku;
    int casos;
    int linha_inicio, coluna_inicio;

    scanf("%d", &casos);

    // 1. ALOCAÇÃO DINÂMICA DA MATRIZ PRINCIPAL
    // Aloca o vetor de ponteiros (as 9 linhas)
    sudoku = (int **)malloc(9 * sizeof(int *));
    if (sudoku == NULL)
    {
        printf("Problema na alocacao de memoria!\n");
        return 1;
    }

    // Aloca os inteiros de cada uma das 9 linhas
    for (size_t i = 0; i < 9; i++)
    {
        sudoku[i] = (int *)malloc(9 * sizeof(int));
        if (sudoku[i] == NULL)
        {
            printf("Problema na alocacao de memoria!\n");
            return 1;
        }
    }

    // 2. PROCESSAMENTO DAS INSTÂNCIAS DE SUDOKU
    for (int c = 0; c < casos; c++)
    {
        // Leitura do tabuleiro
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                scanf("%d", &sudoku[i][j]);
            }
        }

        int valido = 1;

        // Verifica linhas e colunas
        for (size_t z = 0; z < 9; z++)
        {
            if (verificacao_colunas(sudoku, z) == 0)
            {
                valido = 0;
            }
            if (verificacao_linhas(sudoku, z) == 0)
            {
                valido = 0;
            }
        }

        // Verifica blocos 3x3
        for (linha_inicio = 0; linha_inicio < 9; linha_inicio += 3)
        {
            for (coluna_inicio = 0; coluna_inicio < 9; coluna_inicio += 3)
            {
                if (verificacao_bloco(sudoku, linha_inicio, coluna_inicio) == 0)
                {
                    valido = 0;
                }
            }
        }

        // Saida formatada para o Beecrowd
        if (valido == 0)
        {
            printf("Instancia %d\nNAO\n\n", c + 1);
        }
        else
        {
            printf("Instancia %d\nSIM\n\n", c + 1);
        }
    }

    // 3. DESALOCAÇÃO DA MEMÓRIA
    // Libera a memoria de cada linha primeiro
    for (size_t i = 0; i < 9; i++)
    {
        free(sudoku[i]);
    }
    // Libera o vetor principal de ponteiros
    free(sudoku);

    return 0;
}
