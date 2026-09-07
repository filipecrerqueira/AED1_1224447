/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Filipe Siqueira e Cerqueira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 07/09/2026
Objetivo    : Criar uma fila com listas encadeadas e salvar o que foi descartado
Dificuldade : Alto
Uso de IA   : Usei ia bastante para ensinar como implementar uma fila encadeada,  e como montar as estruturas basicas e organizar as ideias em etapas.
              tambem utilizei para organizar o pensamento, ja que o salto do exercicio passado foi grande. alem disso, usei para entender a formatação do beecrowd.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura de celula
typedef struct cel
{
    int valor;
    struct cel *proximo;
} cel;

// ponteiros para inicios e fim

typedef struct
{
    cel *s;
    cel *t;
} fila;

// precisamos iniciar a fila ou seja colocar um inicio apontando pro inicio e o fim para o fim esse vai ser o meio de mover nossos ponteiros
void inicializar(fila *f)
{

    f->s = NULL;
    f->t = NULL;
}

void enfileirar(fila *f, int valor)
{ // funcao para que  possamos enfileirar os dados com o controle de inicio e fim

    cel *nova = (cel *)malloc(sizeof(cel)); // criamos o novo espaço a ser incerido
    nova->valor = valor;
    nova->proximo = NULL;

    if (f->s == NULL) // se a fila tiver vazia temos que a celula nova sera a unica celula e portanto ela vai ser o fim e o inicio
    {
        f->s = nova;
        f->t = nova;
    }
    else
    { // caso nao esteja vazia temos o ponteiro de proximo apontando pra nova e o de fim agora recebendo nova

        f->t->proximo = nova;
        f->t = nova;
    }
}

int desenfileirar(fila *f)
{ // função que vai retirar as cartas

    if (f->s == NULL) // testar se a fila tiver vazia, pq ai n vai criar espaço a mais na memoria e perder ele
    {
        return -1;
    }

    cel *temp = f->s; // armazena temporariamente o valor que tem em s

    int valor = temp->valor; // salva o valor em uma memoria estatica

    f->s = f->s->proximo; // avanca o  inicio para o proximo

    if (f->s == NULL)
    {
        f->t = NULL;
    }

    free(temp);

    return valor; // salvamos o valor que foi retirado
}

int main()
{

    int numero;

    while (scanf("%d", &numero) == 1 && numero != 0)
    {

        fila f;
        inicializar(&f); // inicializa a fila que foi criada f em seu endereço de memoria

        for (size_t i = 1; i <= numero; i++)
        {
            enfileirar(&f, i); // aqui passamos os elementos que vamos enfileirar e o endereço onde serao armazenados
        }

        printf("Discarded cards:");

        if (f.s != f.t) // esse primeiro print garante os demais com a mesma formatação por isso podemos fazer igual dentro do while
        {
            printf(" %d", desenfileirar(&f)); // escrevendo o que saiu

            int mover = desenfileirar(&f); // garantindo que uma coisa aconteça apos a outra

            enfileirar(&f, mover); // remontando
        }

        while (f.s != f.t)
        {
            printf(", %d", desenfileirar(&f));

            int mover = desenfileirar(&f); // garantindo que uma coisa aconteça apos a outra

            enfileirar(&f, mover); // remontando
        }

        int sobrou = desenfileirar(&f);
        printf("\nRemaining card: %d\n", sobrou);
    }

    return 0;
}
