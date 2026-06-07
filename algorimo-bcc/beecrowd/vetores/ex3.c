#include <stdio.h>

int main(){
    float vetor[101];
    int i;

    for(i = 0; i < 100; i++){
        scanf("%f", &vetor[i]);
        if (vetor[i] <= 10){
            printf("A[%d] = %.1f\n", i, vetor[i]);
        }
    }

    return 0;
}