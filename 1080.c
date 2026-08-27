/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Filipe Siqueira e Cerqueira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 26/08/2026
Objetivo    : Ler uma sequencia de inteiros comparar e salvar o maior e a posicao
Dificuldade : Nao apresentou problemas 
Uso de IA   : Nao foi usado ia 
-------------------------------------------------------------------------- */

#include <stdio.h>

int main (){

int posicao = 0;
int numero[100];
int maior = 0;

//leitura dos dados e comparacao
for (int i = 0; i < 100; i++)
{
    scanf("%d", &numero[i]); 

    if (numero[i] > maior ) // condicao para atualizar maior
    {
        maior = numero[i];

        posicao = i+1 ; // incremento na posicao
    }
    
}

printf("%d\n", maior);
printf("%d\n", posicao);

return 0;
}
