#include <stdio.h>
#include <string.h>

struct produto {
    char nome[50];
    int quantidade;
    float preco;
};

// Funções de comparação
int compareByPrice(struct produto a, struct produto b) {
    return (a.preco > b.preco) - (a.preco < b.preco);
}

int compareByQuantity(struct produto a, struct produto b) {
    return (a.quantidade > b.quantidade) - (a.quantidade < b.quantidade);
}

int compareByName(struct produto a, struct produto b) {
    return strcmp(a.nome, b.nome);
}

// Função de Merge Sort
void merge(struct produto arr[], int l, int m, int r, int (*compare)(struct produto, struct produto)) {
    int n1 = m - l + 1;
    int n2 = r - m;

    struct produto L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct produto arr[], int l, int r, int (*compare)(struct produto, struct produto)) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, compare);
        mergeSort(arr, m + 1, r, compare);

        merge(arr, l, m, r, compare);
    }
}

void printProdutos(struct produto produtos[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Nome: %s, Quantidade: %d, Preço: %.2f\n", produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }
}

int main() {
    struct produto produtos[] = {
        {"caderno", 20, 13.99},
        {"caneta", 23, 1.99},
        {"garrafa", 40, 43.99},
        {"cadeira", 13, 683.99},
        {"mochila", 17, 130.99},
        {"papel", 34, 3.99},
        {"cartolina", 58, 3.99},
        {"marcador", 12, 2.99},
        {"grampeador", 27, 13.99},
    };
    int size = sizeof(produtos) / sizeof(produtos[0]);

    int choice;
    printf("Escolha o tipo de ordenação:\n1. Preço\n2. Quantidade\n3. Nome\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            mergeSort(produtos, 0, size - 1, compareByPrice);
            break;
        case 2:
            mergeSort(produtos, 0, size - 1, compareByQuantity);
            break;
        case 3:
            mergeSort(produtos, 0, size - 1, compareByName);
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    printf("Produtos ordenados:\n");
    printProdutos(produtos, size);

    return 0;
}