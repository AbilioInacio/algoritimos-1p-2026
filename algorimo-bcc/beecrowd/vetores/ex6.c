#include <stdio.h>

int main(){
    double vetor[100];
    int i;

    scanf("%lf", &vetor[0]);

    printf("N[0] = %.4lf\n", vetor[0]);
    for(i = 1; i < 100; i++){
        vetor[i] = vetor[i-1]/2;
        printf("N[%d] = %.4lf\n", i, vetor[i]);
    }

    return 0;
}