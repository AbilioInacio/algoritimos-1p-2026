#include <stdio.h>
 
int main() {
    int codigo, quantidade;
    float valor, vlrTotal;
    scanf("%d %d", &codigo, &quantidade);
    if (codigo == 1){
        valor = 4.0;
    } else if (codigo == 2){
        valor = 4.5;
    } else if (codigo == 3){
        valor = 5;
    } else if (codigo == 4){
        valor = 2;
    } else if (codigo == 5){
        valor = 1.5;
    }
    vlrTotal = valor * quantidade;
    printf("Total: R$ %.2f\n", vlrTotal);

    return 0;
}