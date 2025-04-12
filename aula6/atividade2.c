#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carrinho {
    int pessoas;
    char cor[20];
    struct Carrinho *proximo;
    struct Carrinho *anterior;
} Carrinho;

void inserirCarrinho(Carrinho **inicio, char cor[]) {
    Carrinho *novo = (Carrinho *)malloc(sizeof(Carrinho));
    novo->pessoas = 0;
    strcpy(novo->cor, cor);

    if (*inicio == NULL) {
        novo->proximo = novo;
        novo->anterior = novo;
        *inicio = novo;
    } else {
        Carrinho *ultimo = (*inicio)->anterior;
        novo->proximo = *inicio;
        novo->anterior = ultimo;
        ultimo->proximo = novo;
        (*inicio)->anterior = novo;
    }
}

void mostrarRoda(Carrinho *inicio, Carrinho *atual) {
    printf("\n🎡 Estado da Roda Gigante:\n");
    Carrinho *temp = inicio;
    if (temp == NULL) return;

    do {
        printf("[%s | %d pessoa(s)%s] -> ", temp->cor, temp->pessoas, (temp == atual ? " <- atual" : ""));
        temp = temp->proximo;
    } while (temp != inicio);
    printf("(volta ao inicio)\n");
}


int main() {
    Carrinho *inicio = NULL;
    Carrinho *atual = NULL;

    char *cores[10] = {"Vermelho", "Azul", "Verde", "Amarelo", "Rosa", "Laranja", "Roxo", "Branco", "Preto", "Cinza"};

    for (int i = 0; i < 10; i++) {
        inserirCarrinho(&inicio, cores[i]);
    }

    atual = inicio;

    int opcao;

    do {
        printf("\n=== Menu Roda Gigante ===\n");
        printf("1 - Girar para a direita (horario)\n");
        printf("2 - Girar para a esquerda (anti-horario)\n");
        printf("3 - Embarcar pessoa\n");
        printf("4 - Desembarcar pessoa\n");
        printf("5 - Mostrar roda\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                atual = atual->proximo;
                printf("➡️ Girou para a direita. Carrinho atual: %s\n", atual->cor);
                break;
            case 2:
                atual = atual->anterior;
                printf("⬅️ Girou para a esquerda. Carrinho atual: %s\n", atual->cor);
                break;
            case 3:
                if (atual->pessoas < 4) {
                    atual->pessoas++;
                    printf("👥 Embarcou uma pessoa no carrinho %s. Total: %d\n", atual->cor, atual->pessoas);
                } else {
                    printf("🚫 Carrinho cheio! Capacidade maxima de 4 pessoas.\n");
                }
                break;
            case 4:
                if (atual->pessoas > 0) {
                    atual->pessoas--;
                    printf("👤 Uma pessoa desembarcou do carrinho %s. Total: %d\n", atual->cor, atual->pessoas);
                } else {
                    printf("🚫 Carrinho ja está vazio.\n");
                }
                break;
            case 5:
                mostrarRoda(inicio, atual);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção invalida.\n");
        }
    } while (opcao != 0);

    if (inicio != NULL) {
        Carrinho *temp = inicio->proximo;
        while (temp != inicio) {
            Carrinho *prox = temp->proximo;
            free(temp);
            temp = prox;
        }
        free(inicio);
    }

    return 0;
}
