#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct lista{
    int vet[TAM];
    int qtd;
}Lista;

int inserir_no_inicio(Lista *A, int vlr){
    if(A->qtd==TAM){
        return 0;
    }
    deslocamento_para_direita(A);
    A->vet[0] = vlr;
    A->qtd++;
    return 1;
}

int main(){
    Lista A;

    A.qtd = 0; //inicializacao

    inserir_no_inicio(&A, 3);
    inserir_no_inicio(&A, 7);
    inserir_no_inicio(&A, 2);

    mostrar_lista(&A);
}