#include <stdio.h>

    int main(){
        int cont = 0, qtNotas;
        float soma = 0, media, valor;
        scanf("%d", &qtNotas);
        while(cont < qtNotas){
            scanf("%f", &valor);
            soma += valor;
            cont++;
        }
        media = soma / qtNotas;
        
        printf("Media: %0.2f\n", media);
        
        return 0;
    }

    //para rodas o arquivo puxando o txt
    //./nomedoarquivo < entrada.txt
    