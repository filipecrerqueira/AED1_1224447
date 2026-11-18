/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Filipe Siqueira e Cerqueira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 18/11/2026
Objetivo    : ordenar estados
Dificuldade : Muito alta 
Uso de IA   : usei bastante ia para construir o codigo e explicar o que esta acontecendo 
-------------------------------------------------------------------------- */



#include <stdio.h>

#define MAXN 10010
#define MAXM 100010

int head[MAXN];
int to[MAXM];
int nxt[MAXM];
int state[MAXN]; // 0: não visitado, 1: visitando (na pilha), 2: concluído
int edge_cnt;

void add_edge(int u, int v) {
    to[edge_cnt] = v;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}

int dfs(int u) {
    state[u] = 1; // Marca como em processamento

    for (int e = head[u]; e != -1; e = nxt[e]) {
        int v = to[e];
        if (state[v] == 1) {
            return 1; // Encontrou um vértice ainda ativo na recursão (ciclo)
        }
        if (state[v] == 0 && dfs(v)) {
            return 1;
        }
    }

    state[u] = 2; // Finalizou todos os caminhos a partir de u
    return 0;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            head[i] = -1;
            state[i] = 0;
        }
        edge_cnt = 0;

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            add_edge(a, b);
        }

        int has_cycle = 0;
        for (int i = 1; i <= n; i++) {
            if (state[i] == 0) {
                if (dfs(i)) {
                    has_cycle = 1;
                    break;
                }
            }
        }

        if (has_cycle) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
