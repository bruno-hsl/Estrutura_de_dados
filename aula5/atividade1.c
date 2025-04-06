#include <stdio.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int idade;
    int serie;
    int matricula;
} Aluno;

void inserirOrdenado(Aluno aluno, int *tamanho, Aluno lista[]) {
    if (*tamanho >= 100) {
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

void removerAluno(int matricula, int *tamanho, Aluno lista[]) {
    for (int i = 0; i < *tamanho; i++) {
        if (lista[i].matricula == matricula) {
    
            for (; i < *tamanho - 1; i++) {
                lista[i] = lista[i + 1];
            }
            (*tamanho)--;
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}


void imprimirLista(int tamanho, Aluno lista[]) {
    printf("\nLista de Alunos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Matricula: %d | Nome: %s | Idade: %d | Serie: %d\n",
               lista[i].matricula, lista[i].nome, lista[i].idade, lista[i].serie);
    }
}

int main() {
    Aluno lista[100]; 
    int tamanho = 0; 

    int opcao, matricula;
    Aluno novoAluno;

    do {
        printf("\n1. Inserir Aluno\n2. Remover Aluno\n3. Exibir Lista\n4. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome: ");
                getchar(); 
                fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);
                novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';
                printf("Idade: ");
                scanf("%d", &novoAluno.idade);
                printf("Serie: ");
                scanf("%d", &novoAluno.serie);
                printf("Matricula: ");
                scanf("%d", &novoAluno.matricula);

                inserirOrdenado(novoAluno, &tamanho, lista);
                break;

            case 2:
                printf("Digite a matricula: ");
                scanf("%d", &matricula);
                removerAluno(matricula, &tamanho, lista);
                break;

            case 3:
                imprimirLista(tamanho, lista);
                break;
            default:
                printf("Opção invalida\n");
        }
    } while (opcao != 4);

    return 0;
}
