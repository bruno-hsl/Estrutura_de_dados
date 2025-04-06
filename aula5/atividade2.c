#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um produto na lista de compras
typedef struct Produto {
    char nome[50];
    int quantidade;
    struct Produto *proximo;
} Produto;

// Função para inserir um produto no início da lista
void inserirInicio(Produto **ponta, char *nome, int quantidade) {
    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
    strcpy(novoProduto->nome, nome);
    novoProduto->quantidade = quantidade;
    novoProduto->proximo = *ponta;
    *ponta = novoProduto;
}

// Função para inserir um produto no final da lista
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

// Função para imprimir a lista de compras
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

    // Inserindo produtos no início da lista
    inserirInicio(&lista, "Arroz", 2);
    inserirInicio(&lista, "Feijão", 1);

    // Inserindo produtos no final da lista
    inserirFim(&lista, "Macarrão", 3);
    inserirFim(&lista, "Leite", 4);

    // Imprimindo a lista de compras
    imprimirLista(lista);

    return 0;
}
