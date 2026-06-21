#include <stdio.h>

int main(){
    int qtAlunos, qtAprovados, corte, i, y, x, maior, aux;
    scanf("%d", &qtAlunos);
    scanf("%d", &qtAprovados);
    int notas[qtAlunos];

    for(i = 0; i < qtAlunos; i++){
        scanf("%d", &notas[i]);
    }
    for(y = 0; y < qtAlunos-1; y++){
        maior = y;
        for(x = y+1; x < qtAlunos; x++){
            if(notas[maior] < notas[x]){
                maior = x;
            }
        }
        aux = notas[y];
        notas[y] = notas[maior];
        notas[maior] = aux;
        
    }
    for(i = 0; i < qtAlunos; i++){
        printf("%d ", notas[i]);
    }
    printf("\n");
    corte = notas[qtAprovados-1];
    printf("%d\n", corte);

    return 0;
}