#include <stdio.h>

void iniciaSistema(){
    printf("------------------------------------------\n");
    printf("Bem Vindo a Mercearia do 1p BCC\n");
    printf("------------------------------------------\n");
}

int menuSistema(){
    int menu;
    printf("MENU DO SISTEMA\n\n00 para iniciar uma venda\n10 para Encerrar\n");
    printf("Escolha uma acao: ");
    scanf("%d", &menu);
    while(!(!menu || menu == 10)){
        printf("%d Nao faz parte do Menu\nDigite uma acao valida: ", menu);
        scanf("%d", &menu);
    }
    return menu;
}

int encerraSistema(int qtVendas, int faturamentoDia){
    printf("------------------------------------------\n");
    printf("Foram Realizadas %d Vendas Hoje!!\nFaturamos R$ %d,00\n", qtVendas, faturamentoDia);
    if(qtVendas > 0){
        printf("Otimo dia!!\n");
    }else{
        printf("Triste dia!!\n");
    }
    printf("Sistema Encerrado\n");
    printf("------------------------------------------\n");
}

int leProdutos(){
    int produtos[7], prod = 0, custo = 0;
    
    printf("\nVenda iniciada\n");
    printf("------------------------------------------\n\n");
    while(prod < 7){
        printf("digite o valor do %d item: ", prod + 1);
        scanf("%d", &produtos[prod]);
        custo = custo + produtos[prod];
        prod++;
    }
    printf("O valor total da venda eh: R$ %d,00\n", custo);
    return custo;
}

int leValorPago(int custo){
    int valor;

    printf("Digite o valor pago p/ calcular o troco: ");
    scanf("%d", &valor);
    while(valor < custo){
        printf("O Valor eh inferior a compra\nDigite um novo valor: ");
        scanf("%d", &valor);
    }
    return valor;
}

int calculaTroco(int valor, int custo){
    int troco, qtNotas, i;
    int tamVetor, vlrNotas[] = {200, 100, 50, 20, 10, 5, 2, 1};
    tamVetor = sizeof(vlrNotas) / sizeof(vlrNotas[0]);

    troco = valor - custo;
    if(troco <= 0){
        printf("\nValor nao precisa de troco.\n\n");
    }else{
        printf("\nO troco sera de R$ %d,00\n\n", troco);
        for(i = 0; i < tamVetor; i++){
            for(qtNotas = 0; troco >= vlrNotas[i]; troco -= vlrNotas[i]){
                qtNotas++;
            }
            if(qtNotas > 0){
                printf("%d nota(s) de R$ %d,00\n", qtNotas, vlrNotas[i]);
            }
        }
    }
    return troco;
}

int main() {
    int valor, custo, troco, menu = 0, qtVendas = 0, faturamento = 0;
    
    iniciaSistema();

    //proceimento de Venda
    menu = menuSistema();
    while(menu != 10){
        custo = leProdutos();
        valor = leValorPago(custo);
        troco = calculaTroco(valor, custo);
        printf("------------------------------------------\n\n");
        faturamento += custo;
        qtVendas++;
        menu = menuSistema();
    }
    encerraSistema(qtVendas, faturamento);
}