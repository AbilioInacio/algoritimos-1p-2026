#include <stdio.h>

int main(){
    int e, d, resultado;
    scanf("%d", &e);
    scanf("%d", &d);
    if(e > d){
        resultado = e + d;
    } else {
        resultado = 2 * (d - e);
    }
    printf("%d\n", resultado);

    return 0;
}