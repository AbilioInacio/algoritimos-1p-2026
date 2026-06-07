#include <stdio.h>

int main(){
    int i, qtCasos, resultado;
    char vetor[4];

    scanf("%d", &qtCasos);
    for(i = 0; i < qtCasos; i++){
        scanf("%s", vetor);
        if(vetor[0] == vetor[2]){
            resultado = (vetor[2] - '0') * (vetor[0] - '0');
        } else if(vetor[1] >= 'A' && vetor[1] <= 'Z'){
            resultado = (vetor[2] - '0') - (vetor[0] - '0');
        }else{
            resultado = (vetor[2] - '0') + (vetor[0] - '0');
        }
        printf("%d\n", resultado);
    }
    return 0;
}