#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Aluno {
    char nome[50];
    char dataNascimento[11]; // Format: DD/MM/YYYY
    float nota;
    struct Aluno* next; // Pointer for collision handling (linked list)
} Aluno;

// Hash table array (external chaining)
Aluno* hashTable[TABLE_SIZE];

// Hash function (simple sum of ASCII values mod TABLE_SIZE)
int hashFunction(char* nome) {
    int hash = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        hash += nome[i];
    }
    return hash % TABLE_SIZE;
}

// Function to insert a student into the hash table
void inserirAluno(char* nome, char* dataNascimento, float nota) {
    int index = hashFunction(nome);

    // Create a new Aluno node
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novoAluno->nome, nome);
    strcpy(novoAluno->dataNascimento, dataNascimento);
    novoAluno->nota = nota;
    novoAluno->next = NULL;

    // Insert into the hash table (handle collisions with external chaining)
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

// Function to search for a student in the hash table
Aluno* buscarAluno(char* nome) {
    int index = hashFunction(nome);
    Aluno* temp = hashTable[index];

    while (temp != NULL) {
        if (strcmp(temp->nome, nome) == 0) {
            return temp; // Found
        }
        temp = temp->next;
    }
    return NULL; // Not found
}

// Function to display all students in the hash table
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
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert 20 students
    inserirAluno("Alice", "01/01/2000", 9.5);
    inserirAluno("Bob", "02/02/2001", 8.0);
    inserirAluno("Charlie", "03/03/2002", 7.5);
    inserirAluno("David", "04/04/2003", 6.0);
    inserirAluno("Eve", "05/05/2004", 10.0);
    inserirAluno("Frank", "06/06/2005", 5.5);
    inserirAluno("Grace", "07/07/2006", 9.0);
    inserirAluno("Hannah", "08/08/2007", 8.5);
    inserirAluno("Ivy", "09/09/2008", 7.0);
    inserirAluno("Jack", "10/10/2009", 6.5);
    inserirAluno("Kate", "11/11/2010", 8.8);
    inserirAluno("Leo", "12/12/2011", 9.1);
    inserirAluno("Mia", "13/01/2012", 7.7);
    inserirAluno("Nina", "14/02/2013", 6.6);
    inserirAluno("Oscar", "15/03/2014", 5.9);
    inserirAluno("Paul", "16/04/2015", 8.3);
    inserirAluno("Quinn", "17/05/2016", 9.4);
    inserirAluno("Ruby", "18/06/2017", 7.8);
    inserirAluno("Sam", "19/07/2018", 6.2);
    inserirAluno("Tina", "20/08/2019", 8.9);

    // Display the hash table
    exibirTabela();

    // Search for a student
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