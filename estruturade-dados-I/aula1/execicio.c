#include <stdio.h>

int eh_maior_que_60(float a){
    if(a > 60){
        return 1;
    }
    return 0;
}

float menor(float x, float y){
    if(x > y){
        return x;
    }
    return y;
}

int main(){
    float a;
    printf("Digite um valor: ");
    scanf("%f", &a);
    printf("---> %i\n", eh_maior_que_60(a));

    printf("--> %.2f\n", menor(a, 50));
}