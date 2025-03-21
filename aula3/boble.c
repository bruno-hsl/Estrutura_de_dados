#include <stdio.h>
#include <string.h>

struct pessoa {
    char nome[50];
    int idade;
};

void bubbleSort(struct pessoa pessoas[], int n) {
    int i, j;
    struct pessoa temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pessoas[j].idade < pessoas[j + 1].idade) {
                temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct pessoa pessoas[] = {
        {"Ana", 19},
        {"Pedro", 23},
        {"Guilherme", 15},
        {"Daniel", 11},
        {"Lucas", 18}
    };

    int n = sizeof(pessoas) / sizeof(pessoas[0]);

    bubbleSort(pessoas, n);

    printf("Lista ordenada do mais velho para o mais novo:\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }

    return 0;
}
