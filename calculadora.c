#include <stdio.h>

void soma(int num1, int num2, float *result){
    *result = num1 + num2;
}

void subtracao(int num1, int num2, float *result){
    *result = num1 - num2;
}

void multiplicacao(int num1, int num2, float *result){
    *result = num1 * num2;
}

void divisao(int num1, int num2, float *result){
    *result = num1 / num2;
}


int main(){
    int num1, num2, operador;
    float result = 0;

    printf("Digite um numero: ");
    scanf("%d", &num1);

    printf("Digite outro numero: ");
    scanf("%d", &num2);

    printf("Qual operação voce quer fazer ");
    printf("Digite 1 para (soma), 2 para (subtracao),\n 3 para multiplicação e 4 para divisao: ");
    scanf("%d", &operador);

    switch(operador){
        case 1:
        soma(num1, num2, &result);
        break;
        case 2:
        subtracao(num1,num2, &result);
        break;
        case 3:
        multiplicacao(num1, num2, &result);
        break;
        case 4:
        divisao(num1, num2, &result);
        break;
        default:
        printf("Erro numero invalido");
    }
    printf("%.2f", result);
    return 0;
}