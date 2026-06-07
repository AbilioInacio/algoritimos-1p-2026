#include <stdio.h>

const int qtLinhas = 9, qtcolunas = 9;

void le_matriz(int matriz[][qtcolunas]){
    int linha, coluna;

    for(linha = 0; linha < qtLinhas; linha++){
        for(coluna = 0; coluna < qtcolunas; coluna++){
            scanf("%d", &matriz[linha][coluna]);
        }
    }
}

int verifica_colunas(int matriz[][qtcolunas]){
    int linha, coluna, num, ok;
    
    for(linha = 0; linha < qtLinhas; linha++){
        num = 1;
        ok = 0;
        for(coluna = 0; coluna < qtcolunas; coluna++){
            if(num == matriz[linha][coluna]){
                num++;
                coluna = -1; //como o loop vai incrementar a variavel ao final, coloquei -1 para iniciar novamente em 0
                if(num > 9){
                    ok = 1;
                    break;
                }
            }
        }
        if(!ok){
            return ok;
        }
    }
    return ok;
}

int verifica_linhas(int matriz[][qtcolunas]){
    int linha, coluna, num, ok;
    
    for(coluna = 0; coluna < qtcolunas; coluna++){
        num = 1;
        ok = 0;
        for(linha = 0; linha < qtLinhas; linha++){
            if(num == matriz[linha][coluna]){
                num++;
                linha = -1;
                if(num > 9){
                    ok = 1;
                    break;
                }
            }
        }
        if(!ok){
            return ok;
        }
    }
    return ok;
}

int verifica_quadrante(int matriz[][qtcolunas], int quadrante){
    int linha, coluna, num, ok, linhaInicial = 0, colunaInicial = 0;

    while(quadrante > 2){
        linhaInicial += 3;
        quadrante -= 3;
    }
    while(quadrante > 0){
        colunaInicial += 3;
        quadrante --;
    }
    
    num = 1;
    ok = 0;
    for(linha = linhaInicial; linha < linhaInicial + 3; linha++){
        for(coluna = colunaInicial; coluna < colunaInicial + 3; coluna++){
            if(num == matriz[linha][coluna]){
                num++;
                coluna = colunaInicial - 1;
                linha = linhaInicial - 1;
                if(num > 9){
                    ok = 1;
                    break;
                }
            }
        }
    }
    return ok;
}

int main(){
    int linha, coluna, qtCasos, i, j, ok;
    int matriz[qtLinhas][qtcolunas];
    
    scanf("%d", &qtCasos);
    for(i = 0; i < qtCasos; i++){
        le_matriz(matriz);
        
        ok = 1;
        ok = verifica_colunas(matriz);
        
        if(ok){
            ok = verifica_linhas(matriz);
        }
        
        for(j = 0; j < 9 && ok; j++){
            ok = verifica_quadrante(matriz, j);
        }
        printf("Instancia %d\n", i+1);
        if(ok){
            printf("SIM\n\n"); 
        } else {
            printf("NAO\n\n"); 
        }
    }
    
    return 0;
}
