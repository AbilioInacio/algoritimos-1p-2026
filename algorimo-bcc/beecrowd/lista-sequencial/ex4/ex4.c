#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1, num2, num3, maior;
    scanf("%d %d %d", &num1, &num2, &num3);
    maior = (num1 + num2 + abs(num1 - num2)) / 2;
    maior = (maior + num3 + abs(maior - num3)) / 2;
    printf("%d eh o maior\n", maior);
    return 0;
}