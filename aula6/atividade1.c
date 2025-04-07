#include <stdio.h>

struct musica{
    char nome[50];
    char artiste[50];
    struct musica *anterior;
    struct musica *proximo;
};

void inserirInicio(Musica **cabeca){

};

void inserirFinal(){

};

int main(){
    struct musica Musica;
    int opcao;

    printf("1 - Acessar playlist\n");
    printf("2 - Adicionar musica e autor\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Musicas");
        break;
    case 2:
        printf("Nome da musica: ");
        scanf("%s", Musica.nome);

        printf("Nome do artista: ");
        scanf("%s", Musica.artiste);
        break;
    default:
    printf("Opcao invalida");
        break;
    }

    return 0;
}