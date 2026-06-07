#include <stdio.h>

int main(){
    int linha, elemento, linhaSelecionada;
    float matriz[12][12], resultado = 0;
    char operacao;

    scanf("%d %c", &linhaSelecionada, &operacao); // por algum motivo e=da erro se usar dois scanf sendo um int e outro char
    for(linha = 0; linha < 12; linha++){
        for(elemento = 0; elemento < 12; elemento++){
            scanf("%f", &matriz[linha][elemento]);
            if(linha == linhaSelecionada){
                resultado += matriz[linha][elemento];
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