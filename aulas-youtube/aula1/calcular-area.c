#include <stdio.h>

void main(){
    const float Pi = 3.14;
    float area, raio;
    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);
    area =  Pi * raio * raio;
    printf("O valor da area eh: %.2f\n", area);
}