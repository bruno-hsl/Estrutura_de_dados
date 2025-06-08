#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Aluno {
    char nome[50];
    char dataNascimento[11]; 
    float nota;
    struct Aluno* next;
} Aluno;

Aluno* hashTable[TABLE_SIZE];

int hashFunction(char* nome) {
    int hash = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        hash += nome[i];
    }
    return hash % TABLE_SIZE;
}

void inserirAluno(char* nome, char* dataNascimento, float nota) {
    int index = hashFunction(nome);

    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novoAluno->nome, nome);
    strcpy(novoAluno->dataNascimento, dataNascimento);
    novoAluno->nota = nota;
    novoAluno->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = novoAluno;
    } else {
        Aluno* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoAluno;
    }
}

Aluno* buscarAluno(char* nome) {
    int index = hashFunction(nome);
    Aluno* temp = hashTable[index];

    while (temp != NULL) {
        if (strcmp(temp->nome, nome) == 0) {
            return temp; 
        }
        temp = temp->next;
    }
    return NULL; 
}


void exibirTabela() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d:\n", i);
        Aluno* temp = hashTable[i];
        while (temp != NULL) {
            printf("  Nome: %s, Data de Nascimento: %s, Nota: %.2f\n",
                   temp->nome, temp->dataNascimento, temp->nota);
            temp = temp->next;
        }
    }
}

int main() {

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }


    inserirAluno("Cleiton", "01/01/2000", 9.5);
    inserirAluno("Bruno", "02/02/2001", 8.0);
    inserirAluno("Camila", "03/03/2002", 7.5);
    inserirAluno("Duda", "04/04/2003", 6.0);
    inserirAluno("Romulo", "05/05/2004", 10.0);
    inserirAluno("Pedro", "06/06/2005", 5.5);
    inserirAluno("Luana", "07/07/2006", 9.0);
    inserirAluno("eduarda", "08/08/2007", 8.5);
    inserirAluno("Icaro", "09/09/2008", 7.0);
    inserirAluno("Mikael", "10/10/2009", 6.5);

    exibirTabela();

    char nomeBusca[50];
    printf("\nDigite o nome do aluno para buscar: ");
    scanf("%s", nomeBusca);
    Aluno* alunoEncontrado = buscarAluno(nomeBusca);
    if (alunoEncontrado != NULL) {
        printf("Aluno encontrado: Nome: %s, Data de Nascimento: %s, Nota: %.2f\n",
               alunoEncontrado->nome, alunoEncontrado->dataNascimento, alunoEncontrado->nota);
    } else {
        printf("Aluno não encontrado.\n");
    }

    return 0;
}