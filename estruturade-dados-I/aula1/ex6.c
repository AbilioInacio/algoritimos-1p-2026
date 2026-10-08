#include <stdio.h>

int eh_maior(int num1, int num2, int num3){
    if (num1 > num2 && num1 > num3)
        return num1;
    if (num2 > num3)
        return num2;
    return num3;
}

int main(){
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("%d\n", eh_maior(num1, num2, num3));
}