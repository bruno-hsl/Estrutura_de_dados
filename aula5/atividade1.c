#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int idade;
    int serie;
    int matricula;
} Aluno;

void inserirOrdenado(Aluno aluno, int *tamanho, Aluno lista[]) {
    if (*tamanho >= 100) {
        printf("A lista está cheia, não é possível adicionar mais alunos.\n");
        return;
    }

    int i = *tamanho - 1;
    while (i >= 0 && lista[i].matricula > aluno.matricula) {
        lista[i + 1] = lista[i];
        i--;
    }

    lista[i + 1] = aluno;
    (*tamanho)++;
}

void removerAlunoPorMatricula(int matricula, int *tamanho, Aluno lista[]) {
    int i, encontrado = 0;

    for (i = 0; i < *tamanho; i++) {
        if (lista[i].matricula == matricula) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (; i < *tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        (*tamanho)--;
        printf("Aluno com matrícula %d removido com sucesso.\n", matricula);
    } else {
        printf("Aluno com matrícula %d não encontrado.\n", matricula);
    }
}

void imprimirLista(int tamanho, Aluno lista[]) {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Matrícula: %d | Nome: %s | Idade: %d | Série: %d\n",
               lista[i].matricula, lista[i].nome, lista[i].idade, lista[i].serie);
    }
}

int main() {
    Aluno lista[100];
    int tamanho = 0;

    int opcao;
    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir Aluno\n");
        printf("2. Remover Aluno\n");
        printf("3. Exibir Lista\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Aluno novoAluno;
            printf("\nInsira os dados do aluno:\n");
            printf("Nome: ");
            getchar(); 
            fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);
            novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';
            printf("Idade: ");
            scanf("%d", &novoAluno.idade);
            printf("Série: ");
            scanf("%d", &novoAluno.serie);
            printf("Matrícula: ");
            scanf("%d", &novoAluno.matricula);

            inserirOrdenado(novoAluno, &tamanho, lista);

        } else if (opcao == 2) {
            int matricula;
            printf("Digite a matrícula do aluno a ser removido: ");
            scanf("%d", &matricula);
            removerAlunoPorMatricula(matricula, &tamanho, lista);

        } else if (opcao == 3) {
            imprimirLista(tamanho, lista);

        } else if (opcao != 4) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    printf("Programa encerrado. Até mais!\n");
    return 0;
}
