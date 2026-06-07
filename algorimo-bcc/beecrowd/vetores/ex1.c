#include <stdio.h>

int main(){
    // armazena o numero de leds acesos
    //.          0  1  2  3. 4. 5. 6. 7. 8. 9
    int led[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int nCasos, i, cont, qtdLedsAcesos, digito;
    char valor[101];

    scanf("%d", &nCasos); //le quantidade de casos
    //faz looping de leitura para ler a quantidade de casos
    for(cont = 0; cont < nCasos; cont++){
        scanf("%s", valor);
        qtdLedsAcesos = 0;
        //divide o inteiro em partes para separar os elementos
        for(i = 0; valor[i] != '\0'; i++){ // repete enquanto o vetor tiver algum valor diferente de nulo
            digito = valor[i] - '0';       // converte a posicao do vetor para inteiro
            qtdLedsAcesos += (led[digito]);
        }
        printf("%d leds\n", qtdLedsAcesos);
    }

    return 0;
}
