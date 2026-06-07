#include <stdio.h>
 
int main() {
    int distancia;
    float consumo, media;
    scanf("%d %f", &distancia, &consumo);
    //scanf("%f", &consumo); // aqui tbm funciona
    media = distancia / consumo;
    printf("%.3f km/l\n", media);

    return 0;
}