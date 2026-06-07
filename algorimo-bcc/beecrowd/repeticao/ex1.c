#include <stdio.h>

int main(){
    int valor, i;
    scanf("%d", &valor);
    for(i = 2; i <= valor; i+=2){
        printf("%d^2 = %d\n", i, i*i);
    }
    return 0;
}
