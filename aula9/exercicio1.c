#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root; 
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void printTreeUtil(struct Node* root, int space) {
    if (root == NULL) return;

    space += 10;

    printTreeUtil(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTreeUtil(root->left, space);
}

void printTree(struct Node* root) {
    printf("\nEstrutura da arvore Binaria:\n");
    printTreeUtil(root, 0);
}

int searchWithPath(struct Node* root, int target, char* path) {
    if (root == NULL) return 0;

    if (root->data == target) {
        printf("Caminho ate %d: %s -> %d\n", target, path, target);
        return 1;
    }

    char leftPath[100], rightPath[100];
    sprintf(leftPath, "%s -> E", path);
    sprintf(rightPath, "%s -> D", path);

    if (searchWithPath(root->left, target, leftPath)) return 1;
    if (searchWithPath(root->right, target, rightPath)) return 1;

    return 0;
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;

    int valores[] = {4, 2, 6, 1, 3, 5, 7, 6};
    int n = sizeof(valores) / sizeof(valores[0]);
    for (int i = 0; i < n; i++) {
        root = insertNode(root, valores[i]);
    }

    printf("Percorrendo a arvore: ");
    inorderTraversal(root);
    printf("\n");

    printTree(root);

    int buscar;
    printf("Digite um número que deseja buscar na arvore: ");
    scanf("%d", &buscar);

    char path[100] = "Raiz";
    int encontrado = searchWithPath(root, buscar, path);

    if (!encontrado) {
        printf("\nValor %d não encontrado!\n", buscar);
    } else {
        printf("\nValor %d encontrado!\n", buscar);
    }

    freeTree(root);

    return 0;
}
