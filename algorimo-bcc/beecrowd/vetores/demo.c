#include <stdio.h>

int main(){
    int notas[] = {200, 100, 50, 20, 10, 5, 2, 1};
    int valor, i, j, tam;

    scanf("%d", &valor);
    
    tam = (sizeof(notas)/sizeof(notas[0]));

    for(i = 0; i < tam; i++){
        for(j = 0; valor >= notas[i]; j++){
            valor -= notas[i];
        }
        printf("%d notas de R$ %d,00\n", j, notas[i]);
    }

    return 0;
}