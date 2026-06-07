#include <stdio.h>

int tam;

void ler_vetor(int *v){
    int i;
    for(i = 0; i < tam; i++){
        scanf("%d", &v[i]);
    }
}

void escrever_vetor(int *vet){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int somar_vetor(int *a, int *b, int *c){
    int i, soma = 0;
    for(i = 0; i <tam; i++){
        c[i] = a[i] + b [i];
        soma += c[i];
    }
    return soma;
}

void inverter_vetor(int *v, int *j){
    int i;
    for(i = 0; i < tam; i++){
        j[i] = v[tam -1 -i];
    }
}

int main(){
    scanf("%d", &tam);
    int a[tam], b[tam], c[tam];
    ler_vetor(a);
    ler_vetor(b);
    escrever_vetor(a);
    escrever_vetor(b);
    float soma;
    float media;
    soma = somar_vetor(a, b, c);
    media = soma/(tam + 0.0);
    printf("Soma: %.2f Media: %.2f\n", soma, media);
    escrever_vetor(c);
    int i[tam];
    inverter_vetor(c, i);
    escrever_vetor(i);

    return 0;
}