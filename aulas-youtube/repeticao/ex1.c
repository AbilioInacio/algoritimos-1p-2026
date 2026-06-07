#include <stdio.h>
 
int main() {
    int valor, qtNotas, i, vlrNotas[] = {200, 100, 50, 20, 10, 5, 2, 1};
    int produtos[7], prod = 0, custo = 0, troco;
    
    while(prod < 7){
        printf("digite o valor do %d item: ", prod + 1);
        scanf("%d", &produtos[prod]);
        custo = custo + produtos[prod];
        prod++;
    }
    printf("O valor total da compra eh: R$ %d,00\n", custo);
    
    //valor em dinheiro
    printf("Digite o valor pago p/ calcular o troco: ");
    scanf("%d", &valor);
    while(valor < custo){
        printf("O Valor eh inferior a compra\nDigite um novo valor: ");
        scanf("%d", &valor);
    }
    troco = valor - custo;
    if(troco <= 0){
        printf("\nValor nao precisa de troco.\n\n");
    }else{
        printf("\nO troco sera de R$ %d,00\n\n", troco);
        for(i = 0; i < 8; i++){
            for(qtNotas = 0; troco >= vlrNotas[i]; troco -= vlrNotas[i]){
                qtNotas++;
            }
            if(qtNotas > 0){
                printf("%d nota(s) de R$ %d,00\n", qtNotas, vlrNotas[i]);
            }
        }
    }
}