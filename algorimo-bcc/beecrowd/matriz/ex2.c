#include <stdio.h>

int main(){
    int linha, coluna, colunaSelecionada;
    float matriz[12][12], resultado = 0;
    char operacao;

    scanf("%d %c", &colunaSelecionada, &operacao); // por algum motivo e=da erro se usar dois scanf sendo um int e outro char
    for(linha = 0; linha < 12; linha++){
        for(coluna = 0; coluna < 12; coluna++){
            scanf("%f", &matriz[linha][coluna]);
            if(coluna == colunaSelecionada){
                resultado += matriz[linha][coluna];
            }
        }
    }
    if(operacao == 'S'){
        printf("%.1f\n", resultado);
    } else {
        printf("%.1f\n", resultado/12);
    }
    return 0;
}