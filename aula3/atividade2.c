#include <stdio.h>
#include <string.h>

struct Carta {
    char simbolo[10];
    int valor;
};

void selectionSort(struct Carta cartas[], int n) {
    int i, j, min;
    struct Carta temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (cartas[j].valor < cartas[min].valor) {
                min = j;
            }
        }
        if (min != i) {
            temp = cartas[i];
            cartas[i] = cartas[min];
            cartas[min] = temp;
        }
    }
}

int main() {
    struct Carta cartas[] = {
        {"Copas", 9},
        {"Espadas", 1},
        {"Ouros", 8},
        {"Paus", 3},
        {"Copas", 7},
        {"Espadas", 2},
        {"Ouros", 14},
        {"Paus", 6},
        {"Copas", 5}
    };

    int n = sizeof(cartas) / sizeof(cartas[0]);

    selectionSort(cartas, n);

    printf("Cartas ordenadas pelo menor valor:\n");
    for (int i = 0; i < n; i++) {
        printf("Simbolo: %s, Valor: %d\n", cartas[i].simbolo, cartas[i].valor);
    }

    return 0;
}
