#include<stdio.h>

int main(){
    int a =2, b =5, *p, *q;
    p = &a;
    q = &b;
    *p = *p + *q *2;
    p = q;
    *p = *p + *q;
    printf("%i %i %i %i\n", a, b, *p, *q);

    return 0;
}