#include <stdio.h>

int main(){
    int t, aux, i, j, vetor[1000];

    scanf("%d", &t);
    aux = (t - 1);
    for(i = 0; i < 1000; i++){
        if(aux != (t -1)){
            aux++;
        }else{
            aux = 0;
        }
        vetor[i] = aux;
        printf("N[%d] = %d\n", i, vetor[i]);
    }
}