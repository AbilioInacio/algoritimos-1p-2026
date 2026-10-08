#include <stdio.h>

int eh_divisivel_5(int numero){
    if(!(numero%5))
        return 1;
    return 0;
}

int main(){
    int numero;
    scanf("%d", &numero);
    printf("%d\n", eh_divisivel_5(numero));
}