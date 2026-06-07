#include <stdio.h>
//#define VALOR 10.5
int main(){
    float salario, horas;//declare salario,horas numerico 
    const float VALOR = 10.5;
    scanf("%f", &horas);//leia horas
    salario=horas*VALOR;//salario <-horas * valor
    printf("salario: %0.2f\n", salario);//escreva salario 
    return 0;
}