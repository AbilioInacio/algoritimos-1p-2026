#include <stdio.h>

int main(){
    int i, j, aux, qtCasos, stop1, stop2;
    char frase1[51], frase2[51], resultado[103];

    scanf("%d", &qtCasos);
    for(i = 0; i < qtCasos; i++){
        scanf("%s", frase1);
        scanf("%s", frase2);
        aux = 0;
        stop1 = 1;
        stop2 = 1;
        for(j = 0; stop1 || stop2; j++){
            if(frase1[j] != '\0' && stop1){
                resultado[aux] = frase1[j];
                aux++;
            }else{
                stop1 = 0;
            }
            if(frase2[j] != '\0' && stop2){
                resultado[aux] = frase2[j];
                aux++;
            }else{
                stop2 = 0;
            }
        }
        resultado[aux] = '\0';
        printf("%s", resultado);
        printf("\n");
    }
    return 0;
}