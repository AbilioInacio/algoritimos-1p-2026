#include<stdio.h>

void teste( int *a, int b){
    int *p;
    p = a;
    *p = *a + b;
    a = &b;
    *a = *p +2;
}

int main(){
    int a = 2, b = 3;
    teste( &b, a);
    printf("%i %i\n", a, b);

    return 0;
}