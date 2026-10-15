
#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        int saida[1000];
        int pilha[1000];

        while (1) {
            int primeiro;
            scanf("%d", &primeiro);

            if (primeiro == 0) {
                printf("\n");
                break;
            }

            saida[0] = primeiro;

            for (int i = 1; i < n; i++) {
                scanf("%d", &saida[i]);
            }

            int topo = -1;
            int proximo = 1;
            int possivel = 1;

            for (int i = 0; i < n; i++) {
                while (proximo <= n &&
                       (topo == -1 || pilha[topo] != saida[i])) {
                    if (proximo == saida[i]) {
                        break;
                    }

                    pilha[++topo] = proximo;
                    proximo++;
                }

                if (proximo <= n && proximo == saida[i]) {
                    proximo++;
                } else if (topo >= 0 && pilha[topo] == saida[i]) {
                    topo--;
                } else {
                    possivel = 0;
                    break;
                }
            }

            printf("%s\n", possivel ? "Yes" : "No");
        }
    }

    return 0;
}
