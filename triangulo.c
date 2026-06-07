#include <stdio.h>

int main(){
    int qtPontos;

    scanf("%d", &qtPontos);
    int pontos[qtPontos][2];

    for(int i=0; i < qtPontos; i++){
        scanf("%d %d", &pontos[i][0], &pontos[i][1]);
    }

    return 0;
}