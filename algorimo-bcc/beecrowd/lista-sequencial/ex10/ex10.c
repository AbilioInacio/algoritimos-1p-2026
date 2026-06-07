#include <stdio.h>
 
int main() {
    int horas, min, seg;
    scanf("%d", &seg);
    horas = seg / (60 * 60);
    seg = seg - (horas * (60 * 60));
    min = seg / 60;
    seg = seg - (min * 60);
    printf("%d:%d:%d\n", horas, min, seg);

    return 0;
}