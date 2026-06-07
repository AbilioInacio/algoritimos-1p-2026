#include <stdio.h>

int main(){
    int par[5], impar[5], i, valor, contImpar =-1, contPar=-1;

    for(i = 0; i < 15; i++){
        scanf("%d", &valor);
        if(valor%2){
            contImpar++;
            impar[contImpar] = valor;
        } else {
            contPar++;
            par[contPar] = valor;
        }
        if(contPar >= 4){
            for(contPar = 4; contPar > -1; contPar--){
                printf("par[%d] = %d\n", 4 - contPar, par[4 - contPar]);
            }
            contPar = -1;
        }
        if(contImpar >= 4){
            for(contImpar = 4; contImpar > -1; contImpar--){
                printf("impar[%d] = %d\n", 4 - contImpar, impar[4 - contImpar]);
            }
            contImpar = -1;
        }
    }
    if(contImpar > -1){
        for(i = 0; i <= contImpar; i++){
            printf("impar[%d] = %d\n", i, impar[i]);
        }
    }
    if(contPar > -1){
        for(i = 0; i <= contPar; i++){
            printf("par[%d] = %d\n", i, par[i]);
        }
    }

    return 0;
}