#include <stdio.h>

    int main(){
        int cont, quant;
        float peso, boiGordo = 0, boiMagro = 400;
        scanf("%d", &quant);
        for(cont = 0; cont < quant; cont++){
            scanf("%f", &peso);
            if(peso > boiGordo){
                boiGordo = peso;
            }
            if(peso < boiMagro){
                boiMagro = peso;
            }
        }
        printf("Gordo: %.1f\nMagro: %.1f\n", boiGordo, boiMagro);

        return 0;
    }