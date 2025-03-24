#include <stdio.h>

struct produto{
    char nome[50];
    int quantidade;
    float preco;
};

int main() {
    struct produto produtos[] = {
        {"caderno", 20, 13.99},
        {"caneta", 23, 1.99},
        {"garrafa", 40, 43.99},
        {"cadeira", 13, 683.99},
        {"mochila", 17, 130.99},
        {"papel", 34, 3.99},
        {"cartolina", 58, 3.99},
        {"marcador", 12, 2.99},
        {"grampeador", 27, 13.99},
        
    };

  
    return 0;
}