#include <stdio.h>

struct carta{
    char simbolo[30];
    int numero;
}

int main(){
    struct carta cartas[] ={
        {'espadas', 4},
        {'paus', 2},
        {'copas', 3},
        {'ouros', 1}
    };

    int valor = sizeof(cartas)/ sizeof(cartas[0]);
    return 0;
}