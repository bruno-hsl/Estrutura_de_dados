#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    char nome[30];
    int CPF;
    char gravidade[10];
} Paciente;

typedef struct Node {
    Paciente dado;
    struct Node* proximo;
} Node;

typedef struct Queue {
    Node* frente;
    Node* tras;
} Queue;

Queue* criarFila() {
    Queue* fila = (Queue*)malloc(sizeof(Queue));
    fila->frente = fila->tras = NULL;
    return fila;
}

void enqueue(Queue* fila, Paciente paciente) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->dado = paciente;
    novoNode->proximo = NULL;

    if (fila->tras == NULL) {
        fila->frente = fila->tras = novoNode;
    } else {
        fila->tras->proximo = novoNode;
        fila->tras = novoNode;
    }
}

Paciente dequeue(Queue* fila) {
    if (fila->frente == NULL) {
        printf("A fila está vazia!\n");
        Paciente vazio = {"", 0, ""};
        return vazio;
    }

    Node* temp = fila->frente;
    Paciente paciente = temp->dado;
    fila->frente = fila->frente->proximo;

    if (fila->frente == NULL) {
        fila->tras = NULL;
    }

    free(temp);
    return paciente;
}

int isEmpty(Queue* fila) {
    return fila->frente == NULL;
}

void imprimirFila(Queue* fila, char* nomeFila) {
    printf("\nPacientes na fila %s:\n", nomeFila);

    if (isEmpty(fila)) {
        printf("A fila está vazia!\n");
        return;
    }

    Node* atual = fila->frente;
    while (atual != NULL) {
        Paciente paciente = atual->dado;
        printf("Nome: %s | CPF: %d | Gravidade: %s\n",
               paciente.nome, paciente.CPF, paciente.gravidade);
        atual = atual->proximo;
    }
}

void liberarFila(Queue* fila) {
    while (!isEmpty(fila)) {
        dequeue(fila);
    }
    free(fila);
}

int main() {
    Queue* filaVerde = criarFila();
    Queue* filaAmarela = criarFila();
    Queue* filaVermelha = criarFila();

    int opcao;

    for (int i = 0; i < 3; i++) {
        Paciente paciente;

        printf("Nome: ");
        scanf(" %[^\n]", paciente.nome);

        printf("CPF: ");
        scanf("%d", &paciente.CPF);

        do {
            printf("gravidade do paciente:\n1 - Verde\n2 - Amarelo\n3 - Vermelho\nOpção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    strcpy(paciente.gravidade, "Verde");
                    enqueue(filaVerde, paciente);
                    break;
                case 2:
                    strcpy(paciente.gravidade, "Amarelo");
                    enqueue(filaAmarela, paciente);
                    break;
                case 3:
                    strcpy(paciente.gravidade, "Vermelho");
                    enqueue(filaVermelha, paciente);
                    break;
                default:
                    printf("Opção invalida!n");
            }
        } while (opcao < 1 || opcao > 3);
    }

    imprimirFila(filaVerde, "Verde");
    imprimirFila(filaAmarela, "Amarela");
    imprimirFila(filaVermelha, "Vermelha");

    liberarFila(filaVerde);
    liberarFila(filaAmarela);
    liberarFila(filaVermelha);

    return 0;
}
