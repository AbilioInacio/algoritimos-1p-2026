#include <stdio.h>
#include <string.h>
#define T 100

void copia(char *s2, char *s1){
    int i;
    for(i=0; s1[i] != '\0';i++){
        s2[i] = s1[i];
    }
    s2[i] = '\0';
}

int main(){
    char str1[T], str2[T], str3[T];
    scanf("\n%[^\n]", str1);
    strcpy(str2, str1); //copia a str1 na str2
    printf("Str1: %s\n", str1);
    printf("Str2: %s\n", str2);
    copia(str3, str1);
    printf("Str3: %s\n", str3);
    return 0;
}