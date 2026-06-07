#include <stdio.h>

int main(){
    int pos, i, valor, qtCasos;
    
    scanf("%d", &qtCasos);
    int vetor[qtCasos];

    for(i = 0; i < qtCasos; i++){
        scanf("%d", &valor);
        vetor[i] = valor;
        if(i){
            if(valor < vetor[pos]){
                pos = i;
            }
        }else{
            pos = i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", vetor[pos], pos);

    return 0;
}