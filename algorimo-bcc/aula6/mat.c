#include <stdio.h>

int n, m;

void ler_matriz(int matriz[][m]){
    int x, y;
    for(x = 0; x < n; x++){
        for(y = 0; y < m; y++){
            scanf("%d", &matriz[x][y]);
        }
    }
}

void escrever_matriz(int matriz[][m]){
    int x, y;
    for(x = 0; x < n; x++){
        for(y = 0; y < m; y++){
            printf("%2d ", matriz[x][y]);
        }
        printf("\n");
    }
}

int operacao_matriz(int matriz[][m]){
    int x, y, soma = 0;
    for(x = 0; x < n; x++){
        for(y = 0; y < m; y++){
            if((x > y) && (x > m-y-1)){ //quadrante inferiro ao corte das duas diagonais
                soma += matriz[x][y];
                printf("%2d ", matriz[x][y]);
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }
    return soma;
}

int diagonal_principal(int matriz[][m]){
    int x, soma = 0;
    for(x = 0; x < n; x++){
        soma += matriz[x][x];
        printf("%2d ", matriz[x][x]);
    }
    printf("\n");
    return soma;
}

int diagnal_secundaria(int matriz[][m]){
    int x, soma = 0;
    for(x = 0; x < n; x++){
        soma += matriz[m-x-1][x];
        printf("%2d ", matriz[m-x-1][x]);
    }
    printf("\n");
    return soma;
}

int main(){
    scanf("%d %d", &n, &m);
    int matriz[n][m];

    ler_matriz(matriz);
    escrever_matriz(matriz);
    printf("Soma da Operacao matriz: %d\n", operacao_matriz(matriz));
    printf("\n");
    printf("Soma Diagonal principal: %d\n", diagonal_principal(matriz));
    printf("\n");
    printf("Soma Diagonal secundaria: %d\n", diagnal_secundaria(matriz));

    return 0;
}