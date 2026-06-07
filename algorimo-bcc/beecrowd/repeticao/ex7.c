#include <stdio.h>

int main(){
    int i;
    float nota, resultado = 0;
    for(i = 0;i < 2; i++){
        scanf("%f", &nota);
        if ((nota >= 0) && (nota <= 10)){
            resultado += nota;
        } else {
            printf("nota invalida\n");
            i--;
        }
    }
    resultado /= i;
    printf("media = %.2f\n", resultado);

    return 0;
}
