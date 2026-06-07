#include <stdio.h>

int main() {
    int x, y;
    printf("Digite a Coordenada X: ");
    scanf("%d", &x);
    printf("Digite a Coordenada Y: ");
    scanf("%d", &y);
    if ((x > 0)){
        if (y > 0){
            printf("Ponto em Q1\n");
        } else if ( y < 0) {
            printf("Ponto em Q4\n");
        }
    } else if ((x < 0)){
        if (y > 0){
            printf("Ponto em Q2\n");
        } else if ( y < 0) {
            printf("Ponto em Q3\n");
        }
    }
    if ((x == 0) && (y != 0)) {
        printf("Estmos no eixo Y\n");
    } else if ((x != 0) && (y == 0)) {
        printf("Estmos no eixo X\n");
    } else {
        printf("Estamos na Origem\n");
    }

    return 0;
}
