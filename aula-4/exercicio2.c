#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int potencia;
    char marca[50];
} Carro;

int partition(Carro carros[], int low, int high, int (*compara)(Carro, Carro)) {
    Carro pivot = carros[high]; // Pivô escolhido
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compara(carros[j], pivot) < 0) {
            i++;
            Carro temp = carros[i];
            carros[i] = carros[j];
            carros[j] = temp;
        }
    }

    Carro temp = carros[i + 1];
    carros[i + 1] = carros[high];
    carros[high] = temp;

    return i + 1;
}

void quickSort(Carro carros[], int low, int high, int (*compara)(Carro, Carro)) {
    if (low < high) {
        int pi = partition(carros, low, high, compara);
        quickSort(carros, low, pi - 1, compara);
        quickSort(carros, pi + 1, high, compara);
    }
}

int compararPorPotencia(Carro a, Carro b) {
    return a.potencia - b.potencia;
}

int compararPorNome(Carro a, Carro b) {
    return strcmp(a.nome, b.nome);
}

int compararPorMarca(Carro a, Carro b) {
    return strcmp(a.marca, b.marca);
}

int main() {
    Carro carros[5] = {
        {"Fusion", 175, "Ford"},
        {"Civic", 158, "Honda"},
        {"Corolla", 168, "Toyota"},
        {"Mustang", 450, "Ford"},
        {"Onix", 116, "Chevrolet"}
    };

    int escolha;
    printf("Bem-vindo ao sistema de ordenação de carros!\n");
    printf("Escolha o critério para ordenar:\n");
    printf("1 - Potência\n2 - Nome\n3 - Marca\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            quickSort(carros, 0, 4, compararPorPotencia);
            break;
        case 2:
            quickSort(carros, 0, 4, compararPorNome);
            break;
        case 3:
            quickSort(carros, 0, 4, compararPorMarca);
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            return 1;
    }

    printf("\nAqui está a lista de carros ordenada:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nome: %s, Potência: %d, Marca: %s\n",
               carros[i].nome, carros[i].potencia, carros[i].marca);
    }

    printf("Obrigado por usar nosso programa. Até a próxima!\n");

    return 0;
}
