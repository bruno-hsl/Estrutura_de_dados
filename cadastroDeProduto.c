#include <stdio.h>

struct produto {
char nome[50];
int quantidade;
float preco;
char marca[50];
};

int main() {
    int mostrar = 0;

    struct produto pro;

    printf("Nome do produto: ");
    scanf(" %49s", pro.nome);

    printf("Quantidade: ");
    scanf(" %d", &pro.quantidade);

    printf("preco: ");
    scanf(" %f", &pro.preco);

    printf("marca: ");
    scanf(" %49s", pro.marca);
    
    printf("Deseja ver os produtos cadastrados:\n Se sim digite: 1 \n ");
    scanf("%d", &mostrar);
    switch (mostrar){
    case 1:
        printf("Nome do produto: %s\n", pro.nome);
        printf("Quantidade: %d\n", pro.quantidade);
        printf("Preco do produto: %f\n", pro.preco);
        printf("Marca do produto: %s", pro.marca);
        break;
    
    }
    
    return 0;
    }
    