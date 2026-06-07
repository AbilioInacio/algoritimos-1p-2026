#include <stdio.h>
 
int main() {
    int a, b, c, maior, menor, medio;
    scanf("%d %d %d", &a, &b, &c);
    if(a >= b){
        maior = a;
        medio = b;
        menor = b;
    } else {
        maior = b;
        medio = a;
        menor = a;
    }
    if (c >= maior){
        maior = c;
        if (a > menor){
            medio = a;
        }else {
            medio = b;
        }
    }
    if(c <= menor ){
        menor = c;
    } else if (c !=  maior){
        medio = c;
    }
    printf("%d\n", menor);
    printf("%d\n", medio);
    printf("%d\n", maior);
    printf("\n");
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    return 0;
}