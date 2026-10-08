#include <stdio.h>

int eh_primo(int numero){
    for(int i = 2; i < numero -1; i++){
        if(!(numero%i))
            return 0;
    }
    return 1;
}

int main(){
    int numero;
    scanf("%d", &numero);
    printf("%d\n", eh_primo(numero));
}