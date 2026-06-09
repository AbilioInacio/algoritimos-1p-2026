#include <stdio.h>

int main(){
    int linha, coluna, aux = 0;
    float matriz[12][12], resultado = 0;
    char operacao;

    scanf("%c", &operacao);
    for(linha = 0; linha < 12; linha++){
        for(coluna = 0; coluna < 12; coluna++){
            scanf("%f", &matriz[linha][coluna]);
            if(linha > coluna){
                resultado += matriz[linha][coluna];
                aux++;
            }
        }
    }
    if(operacao == 'S'){
        printf("%.1f\n", resultado);
    } else {
        printf("%.1f\n", resultado/aux);
    }
    return 0;
}
