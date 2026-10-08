#include <stdio.h>

int eh_divisivel(int num1, int num2){
    if(!(num1%num2))
        return 1;
    return 0;
}

int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%d\n", eh_divisivel(num1, num2));
}