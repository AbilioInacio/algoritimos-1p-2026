#include <stdio.h>
 
int main() {
    int valor, qtNotas;
    scanf("%d", &valor);
    printf("%d\n", valor);
    qtNotas = valor / 100;
    printf("%d nota(s) de R$ 100,00\n", qtNotas);
    valor = valor - (qtNotas * 100);
    qtNotas = valor / 50;
    printf("%d nota(s) de R$ 50,00\n", qtNotas);
    valor = valor - (qtNotas * 50);
    qtNotas = valor / 20;
    printf("%d nota(s) de R$ 20,00\n", qtNotas);
    valor = valor - (qtNotas * 20);
    qtNotas = valor / 10;
    printf("%d nota(s) de R$ 10,00\n", qtNotas);
    valor = valor - (qtNotas * 10);
    qtNotas = valor / 5;
    printf("%d nota(s) de R$ 5,00\n", qtNotas);
    valor = valor - (qtNotas * 5);
    qtNotas = valor / 2;
    printf("%d nota(s) de R$ 2,00\n", qtNotas);
    valor = valor - (qtNotas * 2);
    qtNotas = valor / 1;
    printf("%d nota(s) de R$ 1,00\n", qtNotas);
    return 0;
}