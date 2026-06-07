#include <stdio.h>

int main(){
    int qtValor, valor, i;
    scanf("%d", &qtValor);
    for(i = 0; i < qtValor; i++){
        scanf("%d", &valor);
        if (valor % 2 == 0){
            //aqui o valor é par ou zero
            if (valor == 0){
                printf("NULL\n");
            } else if (valor > 0){
                printf("EVEN POSITIVE\n");
            } else {
                printf("EVEN NEGATIVE\n");
            }
        } else {
            //aqui o valor é impar
            if (valor > 0){
                printf("ODD POSITIVE\n");
            } else {
                printf("ODD NEGATIVE\n");
            }
        }
    }
    return 0;
}
