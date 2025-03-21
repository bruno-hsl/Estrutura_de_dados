#include <stdio.h>

struct Senha {
    int prioridade; 
    int numero;     
};

void insertionSort(struct Senha senhas[], int n) {
    int i, j;
    struct Senha chave;

    for (i = 1; i < n; i++) {
        chave = senhas[i];
        j = i - 1;

        while (j >= 0 && 
              (senhas[j].prioridade < chave.prioridade || 
              (senhas[j].prioridade == chave.prioridade && senhas[j].numero > chave.numero))) {
            senhas[j + 1] = senhas[j];
            j--;
        }
        senhas[j + 1] = chave;
    }
}

int main() {
    struct Senha senhas[] = {
        {0, 5},
        {1, 3},
        {0, 4},
        {1, 2},
        {1, 1},
        {0, 7},
        {1, 6}
    };

    int n = sizeof(senhas) / sizeof(senhas[0]);

    insertionSort(senhas, n);

    printf("Senhas ordenadas:\n");
    for (int i = 0; i < n; i++) {
        printf("Prioridade: %d, Numero: %d\n", senhas[i].prioridade, senhas[i].numero);
    }

    return 0;
}
