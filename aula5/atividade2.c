#include <stdio.h>
#include <stdlib.h>


typedef struct Produto {
    char nome[50];
    int quantidade;
    struct Produto *proximo;
} Produto;

void inserirInicio(Produto **lista, char *nome, int quantidade) {
    Produto *novo = malloc(sizeof(Produto));
    strcpy(novo->nome, nome);
    novo->quantidade = quantidade;
    novo->proximo = *lista;
    *lista = novo;
}

void inserirFim(Produto **lista, char *nome, int quantidade) {
    Produto *novo = malloc(sizeof(Produto));
    strcpy(novo->nome, nome);
    novo->quantidade = quantidade;
    novo->proximo = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        Produto *temp = *lista;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

void imprimirLista(Produto *lista) {
    printf("Lista de Compras:\n");
    while (lista != NULL) {
        printf("Produto: %s, Quantidade: %d\n", lista->nome, lista->quantidade);
        lista = lista->proximo;
    }
}

int main() {
    Produto *lista = NULL;

    inserirInicio(&lista, "Arroz", 2);
    inserirInicio(&lista, "Feijao", 3);
    inserirFim(&lista, "Leite", 5);
    inserirFim(&lista, "trigo", 4);

    imprimirLista(lista);

    return 0;
}
