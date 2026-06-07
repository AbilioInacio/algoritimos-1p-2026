#include <stdio.h>

int main(){
    int linha, coluna, aux = 0;
    double matriz[12][12], resultado = 0;
    char operacao;

    scanf("%c", &operacao);
    for(linha = 0; linha < 12; linha++){
        for(coluna = 0; coluna < 12; coluna++){
            scanf("%lf", &matriz[linha][coluna]);
            if((linha > 11-coluna) && (linha < coluna)){
                resultado += matriz[linha][coluna];
                aux++;
            }
        }
    }
    if(operacao == 'S'){
        printf("%.1lf\n", resultado);
    } else {
        printf("%.1lf\n", resultado/aux);
    }
    return 0;
}
