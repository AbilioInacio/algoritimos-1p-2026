#include <stdio.h>
 
int main() {
    int tempo, velocidade, distancia;
    float consumo;
    scanf("%d %d", &tempo, &velocidade);
    distancia = velocidade * tempo;
    consumo = distancia / 12.0;
    printf("%.3f\n", consumo);
    return 0;
}