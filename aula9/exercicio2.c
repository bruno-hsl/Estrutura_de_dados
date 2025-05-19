#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados de um corredor
typedef struct {
    char nome[50];
    float tempo;
} Corredor;

// Nó da árvore binária
struct Node {
    Corredor corredor;
    struct Node *left;
    struct Node *right;
};

// Cria um novo nó com os dados do corredor
struct Node* createNode(Corredor c) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->corredor = c;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insere um corredor na árvore com base no tempo de corte
// Classificados (tempo < corte) vão para a direita
// Não classificados (tempo >= corte) vão para a esquerda
struct Node* insert(struct Node* root, Corredor c, float tempo_corte) {
    if (root == NULL) {
        return createNode(c);
    }

    if (c.tempo < tempo_corte) {
        root->right = insert(root->right, c, tempo_corte); // classificados
    } else {
        root->left = insert(root->left, c, tempo_corte); // não classificados
    }

    return root;
}

// Percorre e imprime os corredores classificados (lado direito da árvore)
void mostrarClassificados(struct Node* root, float tempo_corte) {
    if (root == NULL) return;

    mostrarClassificados(root->right, tempo_corte);

    if (root->corredor.tempo < tempo_corte) {
        printf("Classificado: %s - %.2f segundos\n", root->corredor.nome, root->corredor.tempo);
    }

    mostrarClassificados(root->left, tempo_corte);
}

// Libera toda a memória usada pela árvore
void liberarArvore(struct Node* root) {
    if (root == NULL) return;
    liberarArvore(root->left);
    liberarArvore(root->right);
    free(root);
}

// Função principal
int main() {
    struct Node* root = NULL;
    int n;
    float tempo_corte = 10.0;

    printf("Quantos corredores? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Corredor c;
        printf("\nNome do corredor %d: ", i + 1);
        scanf(" %[^\n]", c.nome); // lê nome com espaços

        printf("Tempo do corredor %d (em segundos): ", i + 1);
        scanf("%f", &c.tempo);

        root = insert(root, c, tempo_corte);
    }

    printf("\n=== Corredores Classificados (tempo menor que %.2f) ===\n", tempo_corte);
    mostrarClassificados(root, tempo_corte);

    liberarArvore(root);
    return 0;
}
