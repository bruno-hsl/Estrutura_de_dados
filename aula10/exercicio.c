#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoArvore {
    char nome[50];
    int quantidade;
    float valor;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

NoArvore* criarNoArvore(char nome[], int quantidade, float valor) {
    NoArvore* novoNo = (NoArvore*)malloc(sizeof(NoArvore));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o nó!\n");
        exit(1);
    }
    strcpy(novoNo->nome, nome);
    novoNo->quantidade = quantidade;
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}


NoArvore* inserirNaArvore(NoArvore* raiz, char nome[], int quantidade, float valor) {
    if (raiz == NULL) {
        return criarNoArvore(nome, quantidade, valor);
    }

    int cmp = strcmp(nome, raiz->nome);
    if (cmp < 0) {
        raiz->esquerda = inserirNaArvore(raiz->esquerda, nome, quantidade, valor);
    } else if (cmp > 0) {
        raiz->direita = inserirNaArvore(raiz->direita, nome, quantidade, valor);
    } else {

        raiz->quantidade += quantidade;
        raiz->valor = valor;
        printf("Produto já existia, atualizada a quantidade e valor.\n");
    }

    return raiz;
}

NoArvore* buscarNaArvore(NoArvore* raiz, char nome[]) {
    if (raiz == NULL) {
        printf("Produto '%s' não encontrado no estoque.\n", nome);
        return NULL;
    }

    int cmp = strcmp(nome, raiz->nome);
    if (cmp == 0) {
        printf("Produto encontrado: %s | Quantidade: %d | Valor: R$ %.2f\n",
               raiz->nome, raiz->quantidade, raiz->valor);
        return raiz;
    } else if (cmp < 0) {
        return buscarNaArvore(raiz->esquerda, nome);
    } else {
        return buscarNaArvore(raiz->direita, nome);
    }
}


void imprimirEmOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("Produto: %-15s | Quantidade: %d | Valor: R$ %.2f\n",
               raiz->nome, raiz->quantidade, raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

void liberarArvore(NoArvore* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    NoArvore* raiz = NULL;
    int opcao;
    char nome[50];
    int quantidade;
    float valor;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir produto\n");
        printf("2. Buscar produto\n");
        printf("3. Listar produtos em ordem\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("Nome do produto: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; 
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                printf("Valor (R$): ");
                scanf("%f", &valor);
                getchar(); 
                raiz = inserirNaArvore(raiz, nome, quantidade, valor);
                break;

            case 2:
                printf("Nome do produto a buscar: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                buscarNaArvore(raiz, nome);
                break;

            case 3:
                printf("\n--- Produtos em ordem alfabética ---\n");
                imprimirEmOrdem(raiz);
                break;

            case 4:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    liberarArvore(raiz);
    return 0;
}
