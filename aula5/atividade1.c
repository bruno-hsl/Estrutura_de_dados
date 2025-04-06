#include <stdio.h>
#include <string.h> // Para trabalhar com strings

#define MAX_ALUNOS 100 // Tamanho máximo da lista de alunos

// Estrutura para representar um aluno
typedef struct {
    char nome[50];
    int idade;
    int serie;
    int matricula;
} Aluno;

// Função para inserir um aluno na lista de forma ordenada por matrícula
void inserirOrdenado(Aluno aluno, int *tamanho, Aluno lista[]) {
    if (*tamanho >= MAX_ALUNOS) {
        printf("A lista de alunos está cheia!\n");
        return;
    }

    int i = *tamanho - 1;

    // Desloca os alunos para abrir espaço para o novo aluno
    while (i >= 0 && lista[i].matricula > aluno.matricula) {
        lista[i + 1] = lista[i];
        i--;
    }

    lista[i + 1] = aluno; // Insere o novo aluno na posição correta
    (*tamanho)++;
}

// Função para remover um aluno pela matrícula
void removerPorMatricula(int matricula, int *tamanho, Aluno lista[]) {
    int i, encontrado = 0;

    // Procura o aluno na lista
    for (i = 0; i < *tamanho; i++) {
        if (lista[i].matricula == matricula) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        // Desloca os alunos para preencher o espaço deixado pelo aluno removido
        for (; i < *tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        (*tamanho)--;
        printf("Aluno com matrícula %d foi removido.\n", matricula);
    } else {
        printf("Matrícula %d não encontrada.\n", matricula);
    }
}

// Função para imprimir a lista de alunos
void imprimirLista(int tamanho, Aluno lista[]) {
    printf("Lista de alunos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Matrícula: %d, Nome: %s, Idade: %d, Série: %d\n",
               lista[i].matricula, lista[i].nome, lista[i].idade, lista[i].serie);
    }
}

// Função principal
int main() {
    Aluno lista[MAX_ALUNOS]; // Array para armazenar os alunos
    int tamanho = 0; // Tamanho atual da lista

    // Criando alguns alunos para teste
    Aluno a1 = {"Alice", 14, 9, 1002};
    Aluno a2 = {"Bruno", 15, 10, 1001};
    Aluno a3 = {"Clara", 13, 8, 1003};

    // Inserindo os alunos na lista
    inserirOrdenado(a1, &tamanho, lista);
    inserirOrdenado(a2, &tamanho, lista);
    inserirOrdenado(a3, &tamanho, lista);

    // Imprimindo a lista de alunos
    imprimirLista(tamanho, lista);

    // Removendo um aluno pela matrícula
    removerPorMatricula(1002, &tamanho, lista);

    // Imprimindo a lista de alunos após a remoção
    imprimirLista(tamanho, lista);

    return 0;
}
