#include <stdio.h>
#include <string.h>
#define T 100

long tamanho(char *s1){
    int i;
    for(i=0; s1[i] != '\0';i++);
    return i;
}

int main(){
    char str1[T], str2[T], str3[T];
    scanf("\n%[^\n]", str1);
    printf("Str1: %s TAM: %ld\n", str1, strlen(str1));
    strcpy(str2, str1);
    printf("Str2: %s TAM: %ld\n", str2, tamanho(str2));

    return 0;
}