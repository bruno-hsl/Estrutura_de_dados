#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma Música
typedef struct Musica {
    char nome[50];
    char artista[50];
    struct Musica *proximo;
    struct Musica *anterior;
} Musica;

// Função para criar uma nova música
Musica* criarMusica(const char* nome, const char* artista) {
    Musica *novaMusica = (Musica *)malloc(sizeof(Musica));
    strcpy(novaMusica->nome, nome);
    strcpy(novaMusica->artista, artista);
    novaMusica->proximo = NULL;
    novaMusica->anterior = NULL;
    return novaMusica;
}

// Função para inserir uma música no início da playlist
void inserirInicio(Musica **cabeca, const char* nome, const char* artista) {
    Musica *novaMusica = criarMusica(nome, artista);
    novaMusica->proximo = *cabeca;
    if (*cabeca != NULL) {
        (*cabeca)->anterior = novaMusica;
    }
    *cabeca = novaMusica;
}

// Função para inserir uma música no final da playlist
void inserirFinal(Musica **cabeca, const char* nome, const char* artista) {
    Musica *novaMusica = criarMusica(nome, artista);
    if (*cabeca == NULL) {
        *cabeca = novaMusica;
        return;
    }
    Musica *atual = *cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novaMusica;
    novaMusica->anterior = atual;
}

// Função para avançar para a próxima música
Musica* avancar(Musica *atual) {
    if (atual != NULL && atual->proximo != NULL) {
        return atual->proximo;
    }
    return atual;  // Caso não exista próxima música
}

// Função para voltar para a música anterior
Musica* voltar(Musica *atual) {
    if (atual != NULL && atual->anterior != NULL) {
        return atual->anterior;
    }
    return atual;  // Caso não exista música anterior
}

// Função para imprimir a playlist
void imprimirPlaylist(Musica *cabeca) {
    Musica *atual = cabeca;
    printf("Playlist:\n");
    while (atual != NULL) {
        printf("Música: %s, Artista: %s\n", atual->nome, atual->artista);
        atual = atual->proximo;
    }
}

int main() {
    Musica *playlist = NULL;
    Musica *tocando = NULL;

    // Inserindo músicas na playlist
    inserirInicio(&playlist, "Song 1", "Artist A");
    inserirFinal(&playlist, "Song 2", "Artist B");
    inserirFinal(&playlist, "Song 3", "Artist C");

    // Definindo a música que está tocando
    tocando = playlist;

    // Exibindo a playlist
    imprimirPlaylist(playlist);

    // Avançando e voltando na playlist
    printf("\nTocando: %s\n", tocando->nome);
    tocando = avancar(tocando);
    printf("Avançando: %s\n", tocando->nome);
    tocando = voltar(tocando);
    printf("Voltando: %s\n", tocando->nome);

    return 0;
}
