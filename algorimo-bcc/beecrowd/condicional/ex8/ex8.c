#include <stdio.h>
 
int main() {
    float a, b, c, result;
    scanf("%f %f %f", &a, &b, &c);
    if ((a+b > c) && (b+c > a) && (a+c > b)){
        result = a+b+c;
        printf("Perimetro = %.1f\n", result);
    }else{
        result = ((a + b) *c) / 2;
        printf("Area = %.1f\n", result);
    }
    return 0;
}