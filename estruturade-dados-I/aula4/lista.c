#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    p = (int*)malloc(sizeof(int)*10);

    for(int i=0; i<10; i++){
        printf("Vet[%i] = ", i);
        scanf("%i", &p[i]);
    }

    for(int i=0; i<10; i++){
        printf("Vet[%i] = %i\n", i, p[i]);
    }
}