#include <stdio.h>

int decopoe(int *vlr, int vlrNota){
    int qtNotas;
    for(qtNotas = 0; *vlr >= vlrNota; qtNotas++){
        *vlr = *vlr - vlrNota; 
    }
    printf("%d nota(s) de R$ %d,00\n", qtNotas, vlrNota);
    return *vlr;
}

int main() {
    int valor, i, vlrNota[] = {200, 100, 50, 20, 10, 5, 2, 1};
    scanf("%d", &valor);
    printf("%d\n", valor);
    for(i = 0; i < sizeof(vlrNota)/sizeof(vlrNota[0]); i++){
        decopoe(&valor, vlrNota[i]);
    }
    printf("%d\n", valor);
    return 0;
}