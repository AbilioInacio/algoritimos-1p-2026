#include<stdio.h>

int main(){
    char *a;
    char nome[6] = "Teste";
    a = nome;

    while(*a != '\0'){
        printf("[%c]\n", *a);
        a++;
    }

    return 0;
}