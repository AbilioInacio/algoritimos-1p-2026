#include <stdio.h>

float peso_ideal(char sexo, float altura){
    if (sexo == 'M' || sexo == 'm')
        return (72.7 * altura) - 58;
    return (62.1 * altura) - 44.7;
}

int main(){
    float altura;
    char sexo;
    scanf("%f %c", &altura, &sexo);
    printf("o peso ideal eh: %.2f\n", peso_ideal(sexo, altura));
}