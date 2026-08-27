/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Filipe Siqueira e Cerqueira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 26/08/2026
Objetivo    : Verificar um tabuleiro de sudoku
Dificuldade : Nao apresentou problemas pois foi feito em lp semestre passado
Uso de IA   : usei ia para resolver como executar a verificacao e a divisao dos blocos 3x3
-------------------------------------------------------------------------- */



#include <stdio.h>
#include <stdlib.h>

int verificacao_linhas(int sudoku[9][9], int linha);
int verificacao_colunas(int sudoku[9][9], int coluna);
int verificacao_bloco(int sudoku[9][9], int linha_inicio, int coluna_inicio);

int verificacao_linhas(int sudoku[9][9], int linha)
{

    int verif[9];

    for (size_t i = 0; i < 9; i++)
    {
        verif[i] = 0;
    }

    for (size_t i = 0; i < 9; i++)
    {

        if (verif[sudoku[linha][i] - 1] == 0) // primeira leitura que verfica se ta ok, se tiver ok soma mais um e confirma a 'leitura'
        {

            verif[sudoku[linha][i] - 1] += 1;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}


int verificacao_colunas(int sudoku[9][9], int coluna)
{

    int verif[9];

    for (size_t i = 0; i < 9; i++)
    {
        verif[i] = 0;
    }

    for (size_t i = 0; i < 9; i++)
    {

        if (verif[sudoku[i][coluna] - 1] == 0)
        {

            verif[sudoku[i][coluna] - 1] += 1;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}


int verificacao_bloco(int sudoku[9][9], int linha_inicio, int coluna_inicio) // precisa verificar o bloco com isso tem 9 blocos e precisa separar cada inicio deles
{
    int verif[9];

    for (size_t i = 0; i < 9; i++)
    {
        verif[i] = 0;
    }

    for (int i = linha_inicio; i < linha_inicio + 3; i++)
    {
        for (int j = coluna_inicio; j < coluna_inicio + 3; j++)
        {

            int numero = sudoku[i][j]; // aqui ro armazenando o valor das casas para o verif ler

                if (verif[numero - 1] == 0) // começa a verificacao, ja tem um loop para garantir que vai verif tudo
            {

                verif[numero - 1] += 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int sudoku[9][9];
    int casos;
    int linha_inicio , coluna_inicio ;

    scanf("%d", &casos);

    for (int c = 0; c < casos; c++)
    {
        for (int i = 0; i < 9; i++)
        {   for (int j = 0; j < 9; j++)
        {
                scanf("%d", &sudoku[i][j]);

        }
        }
        
        int valido = 1;

        for (size_t z = 0; z < 9; z++) // laco para comecar as verif, com um parametro fixo e outro variavel como ja passado para a função
        {
           if( verificacao_colunas(sudoku, z) == 0){

                valido = 0;

           }
            
           if( verificacao_linhas(sudoku, z) == 0){

                valido = 0;
           }

        }
        
        




        for ( linha_inicio = 0; linha_inicio < 9; linha_inicio += 3)
        {
            for (coluna_inicio = 0; coluna_inicio < 9; coluna_inicio += 3)
            {

               if( verificacao_bloco( sudoku, linha_inicio, coluna_inicio) == 0){

                valido = 0;

               }

            }
        }
    

    if (valido == 0 )
    {
        printf("Instancia %d\nNAO\n\n", c + 1);
    } else{

        printf("Instancia %d\nSIM\n\n", c + 1);
    }
    
}

return 0;
}
