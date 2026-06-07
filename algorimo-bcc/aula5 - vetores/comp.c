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
int comparar(char *s1, char *s2){
    int t1 = strlen(s1);
    int t2 = strlen(s2);
    if(t1 != t2)

}

int main(){
    char str1[T], str2[T], str3[T];
    scanf("\n%[^\n]", str1);
    scanf("\n%[^\n]", str2);
    strcpy(str3, str2); //copia a str1 na str2
    printf("Str1: %s\n", str1);
    printf("Str2: %s\n", str2);
    printf("Str3: %s\n", str3);
    int t1, t2, t3;
    t1 =  strcmp(str2, str3);
    t2 =  strcmp(str2, str1);
    t3 =  strcmp(str1, str3);
    printf("T1: %d T2: %d T3: %d\n", t1, t2, t3);

    return 0;
}
