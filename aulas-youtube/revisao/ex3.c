#include <stdio.h>

int main(){
    int qtAlunos, qtAprovados, nota, maior=0, segundo=0, terceiro=0;
    scanf("%d", &qtAlunos);
    scanf("%d", &qtAprovados);
    while(){
        scanf("%d", &nota);
        if(maior < nota){
            terceiro = segundo;
            segundo = maior;
            maior = nota;
        }else if (segundo < nota){
            terceiro = segundo;
            segundo = nota;
        } else if(terceiro<nota){
            terceiro = nota;
        }
    }
    if (qtAprovados == 1){
        printf("%d\n", maior);
    }
    if (qtAprovados == 2){
        printf("%d\n", segundo);
    }
    if (qtAprovados == 3){
        printf("%d\n", terceiro);
    }
    
    return 0;
}