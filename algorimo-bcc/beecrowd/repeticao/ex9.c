#include <stdio.h>

int main(){
    int cod, alcool = 0, gasolina = 0, diesel = 0;
    while(1){
        scanf("%d", &cod);
        if(cod == 4){
            break;
        }
        if(cod == 1){
            alcool++;
        }
        if(cod == 2){
            gasolina++;
        }
        if(cod == 3){
            diesel++;
        }
    }
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", alcool);
    printf("Gasolina: %d\n", gasolina);
    printf("Diesel: %d\n", diesel);

    return 0;
}