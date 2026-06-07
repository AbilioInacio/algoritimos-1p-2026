#include <stdio.h>

int main(){
    int i, qtDivisoes, dividendo, divisor;
    scanf("%d", &qtDivisoes);
    for(i = 0; i < qtDivisoes; i++){
        scanf("%d %d", &dividendo, &divisor);
        if(divisor){
            printf("%.1f\n",dividendo / (divisor + 0.0));
        } else {
            printf("divisao impossivel\n");
        }
    }

    return 0;
}
