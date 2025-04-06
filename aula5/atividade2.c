#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    char nome[50];
    int quantidade;
    struct Produto *proximo;
} Produto;

void inserirInicio(Produto **ponta, char *nome, int quantidade) {
    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
    strcpy(novoProduto->nome, nome);
    novoProduto->quantidade = quantidade;
    novoProduto->proximo = *ponta;
    *ponta = novoProduto;
}

void inserirFim(Produto **ponta, char *nome, int quantidade) {
    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
    strcpy(novoProduto->nome, nome);
    novoProduto->quantidade = quantidade;
    novoProduto->proximo = NULL;

    if (*ponta == NULL) {
        *ponta = novoProduto;
    } else {
        Produto *temp = *ponta;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoProduto;
    }
}

void imprimirLista(Produto *ponta) {
    printf("Lista de Compras:\n");
    Produto *temp = ponta;
    while (temp != NULL) {
        printf("Produto: %s, Quantidade: %d\n", temp->nome, temp->quantidade);
        temp = temp->proximo;
    }
}

int main() {
    Produto *lista = NULL; 

    inserirInicio(&lista, "Arroz", 2);
    inserirInicio(&lista, "Feijão", 3);

    inserirFim(&lista, "Leite", 5);
    inserirFim(&lista, "Macarrão", 4);

    imprimirLista(lista);

    return 0;
}
