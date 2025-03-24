#include <stdio.h>

struct pessoa {
char nome[50];
int idade;
float altura;
};

void 
 crescer(struct  pessoa *pe, int anos, float crescimento){
    pe->idade = pe->idade = anos;
    pe->altura = pe->altura = crescimento;
 }
 
int main() {
    int mostrar = 0;

    struct pessoa pe;

    printf("Nome da pessoa: ");
    scanf(" %49s", pe.nome);

    printf("Idade: ");
    scanf(" %d", &pe.idade);

    printf("Altura: ");
    scanf(" %f", &pe.altura);

    
    printf("Deseja ver as pessoas cadastradas:\n Se sim digite: 1 \n ");
    scanf("%d", &mostrar);
    switch (mostrar){
    case 1:
        printf("Nome: %s\n", pe.nome);
        printf("Idade: %d\n", pe.idade);
        printf("Altura: %f\n", pe.altura);
        break;
    
    }
    
    return 0;
    }
    