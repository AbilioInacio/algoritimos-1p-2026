#include <stdio.h>

int main() {
    int valor;
    scanf("%d", &valor);
    if (valor >= 0){
        printf("Acesso Liberado\n");
    } else if (valor > -5){
        printf("Acesso Liberado\nBem vindo a Conta Premium!\n");
    }
    printf("Fim programa\n");

    return 0;
}