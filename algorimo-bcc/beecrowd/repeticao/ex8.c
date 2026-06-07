#include <stdio.h>

int main(){
    int inicio, fim, i, soma=0, aux;
    scanf("%d %d", &inicio, &fim);
    if(inicio > fim){
        aux = inicio;
        inicio = fim;
        fim = aux;
    }
    for(i = inicio; i <= fim; i++){
        if(i%13 != 0){
            soma += i;
        }
    }
    printf("%d\n", soma);

    return 0;
}
