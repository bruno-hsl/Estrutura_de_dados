#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct musica {
    char nome[50];
    char artiste[50];
    struct musica *anterior;
    struct musica *proximo;
};

typedef struct musica Musica;

void inserirInicio(Musica **cabeca, char nome[], char artista[]) {
    Musica *nova = (Musica *)malloc(sizeof(Musica));
    strcpy(nova->nome, nome);
    strcpy(nova->artiste, artista);
    nova->anterior = NULL;
    nova->proximo = *cabeca;

    if (*cabeca != NULL)
        (*cabeca)->anterior = nova;

    *cabeca = nova;
}

void inserirFinal(Musica **cabeca, char nome[], char artista[]) {
    Musica *nova = (Musica *)malloc(sizeof(Musica));
    strcpy(nova->nome, nome);
    strcpy(nova->artiste, artista);
    nova->proximo = NULL;

    if (*cabeca == NULL) {
        nova->anterior = NULL;
        *cabeca = nova;
        return;
    }

    Musica *temp = *cabeca;
    while (temp->proximo != NULL)
        temp = temp->proximo;

    temp->proximo = nova;
    nova->anterior = temp;
}

void mostrarPlaylist(Musica *cabeca) {
    printf("\n🎵 Playlist:\n");
    while (cabeca != NULL) {
        printf("- %s (%s)\n", cabeca->nome, cabeca->artiste);
        cabeca = cabeca->proximo;
    }
}

void tocarAtual(Musica *atual) {
    if (atual)
        printf("▶️ Tocando agora: %s - %s\n", atual->nome, atual->artiste);
    else
        printf("🚫 Nenhuma música está tocando.\n");
}

Musica* avancar(Musica *atual) {
    if (atual && atual->proximo)
        return atual->proximo;
    printf("🚫 Não há próxima música.\n");
    return atual;
}

Musica* voltar(Musica *atual) {
    if (atual && atual->anterior)
        return atual->anterior;
    printf("🚫 Não há música anterior.\n");
    return atual;
}

int main() {
    Musica *cabeca = NULL;
    Musica *tocando = NULL;

    int opcao;
    char nome[50], artista[50];

    do {
        printf("\nMENU\n");
        printf("1 - Acessar playlist\n");
        printf("2 - Adicionar musica (no final)\n");
        printf("3 - Inserir no início\n");
        printf("4 - Avançar\n");
        printf("5 - Voltar\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
        case 1:
            mostrarPlaylist(cabeca);
            tocarAtual(tocando);
            break;
        case 2:
            printf("Nome da musica: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("Nome do artista: ");
            fgets(artista, 50, stdin);
            artista[strcspn(artista, "\n")] = '\0';

            inserirFinal(&cabeca, nome, artista);
            if (tocando == NULL) tocando = cabeca;
            break;
        case 3:
            printf("Nome da musica: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("Nome do artista: ");
            fgets(artista, 50, stdin);
            artista[strcspn(artista, "\n")] = '\0';

            inserirInicio(&cabeca, nome, artista);
            if (tocando == NULL) tocando = cabeca;
            break;
        case 4:
            tocando = avancar(tocando);
            tocarAtual(tocando);
            break;
        case 5:
            tocando = voltar(tocando);
            tocarAtual(tocando);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    while (cabeca != NULL) {
        Musica *temp = cabeca;
        cabeca = cabeca->proximo;
        free(temp);
    }

    return 0;
}
