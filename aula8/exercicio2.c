#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int num1;
    int num2;
    char operador;
} Operacao;

typedef struct Node {
    Operacao data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initializeStack(Stack *s) {
    s->top = NULL;
}

bool isEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, Operacao op) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro na alocação!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = op;
    newNode->next = s->top;
    s->top = newNode;
    printf("Operação armazenada: %d %c %d\n", op.num1, op.operador, op.num2);
}

Operacao pop(Stack *s) {
    Operacao vazia = {0, 0, '?'};
    if (isEmpty(s)) {
        printf("Erro: pilha vazia!\n");
        return vazia;
    }
    Node *temp = s->top;
    Operacao op = temp->data;
    s->top = s->top->next;
    free(temp);
    return op;
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Pilha está vazia.\n");
        return;
    }
    printf("Pilha (topo -> base):\n");
    Node *current = s->top;
    while (current != NULL) {
        printf("- %d %c %d\n", current->data.num1, current->data.operador, current->data.num2);
        current = current->next;
    }
}

void freeStack(Stack *s) {
    Node *current = s->top;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    s->top = NULL;
}

int executarOperacao(Operacao op) {
    switch (op.operador) {
        case '+': return op.num1 + op.num2;
        case '-': return op.num1 - op.num2;
        case '*': return op.num1 * op.num2;
        case '/': 
            if (op.num2 == 0) {
                printf("Erro: divisão por zero!\n");
                return 0;
            }
            return op.num1 / op.num2;
        default:
            printf("Operador inválido!\n");
            return 0;
    }
}

int main() {
    Stack historico;
    initializeStack(&historico);

    int opcao;
    int resultadoFinal = 0;

    do {
        printf("\nCalculadora:\n");
        printf("1. Nova operação\n");
        printf("2. Desfazer última operação\n");
        printf("3. Mostrar histórico\n");
        printf("4. Mostrar resultado final\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Operacao op;
            printf("Digite o primeiro número: ");
            scanf("%d", &op.num1);
            printf("Digite o operador (+, -, *, /): ");
            scanf(" %c", &op.operador);
            printf("Digite o segundo número: ");
            scanf("%d", &op.num2);

            int resultado = executarOperacao(op);
            resultadoFinal = resultado;
            push(&historico, op);
            printf("Resultado: %d\n", resultado);

        } else if (opcao == 2) {
            if (!isEmpty(&historico)) {
                Operacao removida = pop(&historico);
                printf("Última operação removida: %d %c %d\n", removida.num1, removida.operador, removida.num2);

                // Recalcular o resultado final
                Node *temp = historico.top;
                resultadoFinal = 0;
                while (temp != NULL) {
                    resultadoFinal = executarOperacao(temp->data);
                    temp = temp->next;
                }
            } else {
                printf("Nada para desfazer.\n");
            }

        } else if (opcao == 3) {
            printStack(&historico);

        } else if (opcao == 4) {
            printf("Resultado final atual: %d\n", resultadoFinal);

        } else if (opcao != 5) {
            printf("Opção inválida.\n");
        }

    } while (opcao != 5);

    freeStack(&historico);
    printf("Encerrando calculadora.\n");
    return 0;
}
