#include <stdio.h>

int main(){
    const double PI = 3.14159;
    double a, b, c, result;
    scanf("%lf %lf %lf", &a, &b, &c);
    //area do triangulo retangulo
    result = (a * c) / 2;
    printf("TRIANGULO: %.3lf\n", result);
    //area do CIRCULO PI * r *r
    result = PI * c * c;
    printf("CIRCULO: %.3lf\n", result);
    //area do trapezio ((B+b)*h)/2
    result = ((a + b) * c) / 2;
    printf("TRAPEZIO: %.3lf\n", result);
    //area do QUADRADO L*L
    result = b * b;
    printf("QUADRADO: %.3lf\n", result);
    //area do RETANGULO SENDO LADOS A E B
    result = a * b;
    printf("RETANGULO: %.3lf\n", result);
    return 0;
}