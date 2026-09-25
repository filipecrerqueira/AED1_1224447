/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Filipe Siqueira e Cerqueira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 24/09/2026
Objetivo    : Busca em vetores
Dificuldade : dificil
Uso de IA   : usei para interpretar o problema. e para organizar os lacos for na leitura que me confundiu mais que aplicar o algoritmo de busca
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int Busca_binaria(int x, int n, int v[]){

    int e, d, m; // variaveis de manipulação de casas no vetor

    e = -1;   //inicializa as nossas "bordas"
    d = n;

    while ( e < d-1){    //enquanto tiver pelo menos uma casa entre a esquerda "e" e a direita "d"

        m = (d + e)/2; // definimos o meio

        if(v[m] < x){ // se o valor tiver menor que x a nossa esquerda vai pro meio "m"

            e = m;

        }else{ // se o valor tiver maior que x ou igual a direita que vai pro meio "m"

            d = m;

        }
    }
    return d;  // retorna a posicao de x
}

int main(){

int casas, encomendas;
int endereco;
long long int tempo_total = 0;

scanf( "%d %d", &casas, &encomendas);

int v[casas];


for (int i = 0; i < casas; i++)
{
    scanf("%d", &endereco);

    v[i] = endereco;
}

int posicao_inicial = 0;
int tempo_gasto = 0;

for (size_t i = 0; i < encomendas; i++)
{
   scanf("%d", &endereco);      // le o endereco de onde vai a carta i 

   int destino = Busca_binaria(endereco, casas , v );

   tempo_gasto = abs(posicao_inicial - destino); // calcula o tempo gasto para ir do inicio ao destino

   tempo_total += tempo_gasto; // acumula o tempo total     

   posicao_inicial = destino; // atualiza a posição inicial para o proximo deslocamento

}

printf ( "%lld\n", tempo_total);

return 0;

}
