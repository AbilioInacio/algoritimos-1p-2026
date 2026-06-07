#include <stdio.h>

int main(){
    int i, j, nCasos, fib, valor;
    unsigned long long vetor[61]; // long = inteiro grando, long log = inteiro maior ainda, unsingned = apenas positivos deixando maior ainda.
    
    scanf("%d", &nCasos);
    vetor[0] = 0;
    vetor[1] = 1;

    for(i = 0; i < nCasos; i++){
        scanf("%d", &valor);
        for(j = 2; j <= valor; j++){
            vetor[j] = vetor[j-1] + vetor[j-2];
        }
            printf("Fib(%d) = %lld\n", valor, vetor[valor]);
    }

    return 0;
}