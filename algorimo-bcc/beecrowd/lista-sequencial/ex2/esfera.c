#include <stdio.h>

int main(){
    const double PI = 3.14159;
    double raio, volume;
    scanf("%lf", &raio);
    volume = (4.0/3) * PI * raio * raio * raio;
    printf("VOLUME = %.3lf\n", volume);
    return 0;
}