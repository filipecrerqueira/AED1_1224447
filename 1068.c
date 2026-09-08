/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Filipe Siqueira e Cerqueira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 08/09/2026
Objetivo    : Criar uma fila com listas encadeadas e salvar o que foi descartado
Dificuldade : Medio
Uso de IA   : usei apenas para entender a formatacao do beecrowd e os conceitos de prioridade entre os parenteses de fechar e de abrir. 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main()
{

    char equacao[1000];
    char pilha[1000];
    

    while (fgets(equacao, sizeof equacao, stdin) != NULL) //para ler os diferentes casos ate uma linha vazia
    {
       int valido = 1;
       int topo = 0;

        for (size_t i = 0; equacao[i] != '\n' && equacao[i] != '\0'; i++)
        {
            

            if (equacao[i] == '(') // empilhando se encontrar o parenteses que abre e ai guarda essa chamada 
            {
                pilha[topo] = '(';
                topo++;
            }

            if (equacao[i] == ')') // desenpilha se encontrar o que fecha, resolvendo a chamada pendente 
            {
                if (topo > 0)
                {
                    topo--;
                }
                else
                {
                   valido = 0; // se encontrou um que fecha sem ter algum que abre ja lido vai dar errado
                    break;
                }
            }

           
        }

        if (valido == 1 && topo == 0)
        {
            printf("correct\n"); // se tudo ocooreu bem e ou nao tem parenteses recebe o correct
        }
        else
        {
            printf ("incorrect\n"); // se tentou fechar sem abrir ou se terminou sobrando 
        }
        
    }
    return 0;
}
