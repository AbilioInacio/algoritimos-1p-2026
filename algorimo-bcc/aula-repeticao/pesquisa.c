#include <stdio.h>

    int main(){
        int cont = 0, voto;
        float media, soma = 0;
        do{
            scanf("%d", &voto);
            if(voto == 0){
                break;
            }
            soma += voto;
            cont++;
        }while(1);
        media = soma / cont;
        printf("Media: %0.1f\n", media);
        
        return 0;
    }