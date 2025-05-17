#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nome[100];
    char cpf[20];
    int gravidade;
} Paciente;

typedef struct Node {
    Paciente data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, Paciente p) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Paciente enfileirado: %s (Gravidade: %d)\n", p.nome, p.gravidade);
}

Paciente dequeue(Queue *q) {
    Paciente vazio = {"", "", -1};

    if (isEmpty(q)) {
        printf("Erro: a fila está vazia!\n");
        return vazio;
    }

    Node *temp = q->front;
    Paciente value = temp->data;
    q->front = q->front->next;

    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }

    return value;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia.\n");
        return;
    }

    Node *current = q->front;
    while (current != NULL) {
        printf("- %s (CPF: %s, Gravidade: %d)\n", current->data.nome, current->data.cpf, current->data.gravidade);
        current = current->next;
    }
}

void freeQueue(Queue *q) {
    Node *current = q->front;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    q->front = NULL;
    q->rear = NULL;
}

int main() {
    Queue emergencia, uti, triagem;
    initializeQueue(&emergencia);
    initializeQueue(&uti);
    initializeQueue(&triagem);

    int n;
    printf("Quantos pacientes deseja cadastrar? ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        Paciente p;
        printf("\nPaciente %d:\n", i + 1);
        printf("Nome: ");
        fgets(p.nome, sizeof(p.nome), stdin);
        p.nome[strcspn(p.nome, "\n")] = '\0';
        printf("CPF: ");
        fgets(p.cpf, sizeof(p.cpf), stdin);
        p.cpf[strcspn(p.cpf, "\n")] = '\0';
        printf("Gravidade (0-10): ");
        scanf("%d", &p.gravidade);
        getchar(); 

        enqueue(&emergencia, p);
    }


    printf("\nProcessando fila de emergência...\n");
    while (!isEmpty(&emergencia)) {
        Paciente p = dequeue(&emergencia);
        if (p.gravidade >= 8) {
            enqueue(&uti, p);
        } else {
            enqueue(&triagem, p);
        }
    }

    printf("\n🛌 Fila UTI:\n");
    printQueue(&uti);

    printf("\n🩺 Fila Triagem:\n");
    printQueue(&triagem);

    freeQueue(&emergencia);
    freeQueue(&uti);
    freeQueue(&triagem);

    return 0;
}
