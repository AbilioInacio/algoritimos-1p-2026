#include <stdio.h>

int main(){
    int qtCasos, qtCobaias, coelhos = 0, ratos = 0, sapos = 0, i;
    float total;
    char tipoCobaia;
    scanf("%d", &qtCasos);
    for(i = 0;i < qtCasos; i++){
        scanf("%d %c", &qtCobaias, &tipoCobaia);
        if(tipoCobaia == 'C'){
            coelhos += qtCobaias;
        } else if (tipoCobaia == 'R'){
            ratos += qtCobaias;
        } else if (tipoCobaia == 'S'){
            sapos += qtCobaias;
        }
    }
    total = coelhos + ratos + sapos;
    printf("Total: %.0f cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n", (coelhos/total)*100);
    printf("Percentual de ratos: %.2f %%\n", (ratos/total)*100);
    printf("Percentual de sapos: %.2f %%\n", (sapos/total)*100);

    return 0;
}