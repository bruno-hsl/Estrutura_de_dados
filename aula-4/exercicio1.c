#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void merge(Produto arr[], int left, int mid, int right, int (*cmp)(Produto, Produto)) {
    Produto temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (cmp(arr[i], arr[j]) <= 0) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(Produto arr[], int left, int right, int (*cmp)(Produto, Produto)) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, cmp);
        mergeSort(arr, mid + 1, right, cmp);
        merge(arr, left, mid, right, cmp);
    }
}

int compararPorPreco(Produto a, Produto b) {
    return (a.preco > b.preco) - (a.preco < b.preco);
}

int compararPorQuantidade(Produto a, Produto b) {
    return a.quantidade - b.quantidade;
}

int compararPorNome(Produto a, Produto b) {
    return strcmp(a.nome, b.nome);
}

int main() {
    Produto produtos[5] = {
        {"Arroz", 10, 15.0},
        {"Feijao", 5, 10.0},
        {"Macarrao", 8, 7.5},
        {"Acucar", 3, 3.0},
        {"Cafe", 2, 20.0}
    };

    int escolha;
    printf("Escolha o critério de ordenação:\n1. Preço\n2. Quantidade\n3. Nome\n");
    scanf("%d", &escolha);

    if (escolha == 1) {
        mergeSort(produtos, 0, 4, compararPorPreco);
    } else if (escolha == 2) {
        mergeSort(produtos, 0, 4, compararPorQuantidade);
    } else if (escolha == 3) {
        mergeSort(produtos, 0, 4, compararPorNome);
    } else {
        printf("Opção inválida!\n");
        return 1;
    }

    printf("\nProdutos ordenados:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nome: %s, Quantidade: %d, Preço: R$%.2f\n",
               produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }

    return 0;
}
