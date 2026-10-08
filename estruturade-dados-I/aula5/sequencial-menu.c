#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct lista{
      int vet[TAM];
      int qtd;
}Lista;

void deslocamento_para_direita(Lista *A){
      if (A->qtd == TAM){ // Lista cheia
            return;
      }
      for (int i=A->qtd; i > 0; i-- ){
            A->vet[i] = A->vet[i-1];
      }
}

int inserir_no_inicio(Lista *A, int vlr){
      if (A->qtd == TAM){ // Lista cheia
            return 0;
      }
      deslocamento_para_direita(A);
      A->vet[0] = vlr;
      A->qtd++;
      return 1;
}

void mostrar_lista(Lista *A){
      if (A->qtd == 0){
            printf("Lista vazia.\n");
      }else{
            for (int i=0; i < A->qtd; i++){
                  printf("%i\n", A->vet[i]);
            }
      }    
}

int menu(){
      int opc;
      system("clear");
      printf("[0] - Sair.\n");
      printf("[1] - Inserir no início.\n");
      printf("[2] - Mostrar lista.\n");
      
      printf("Escolha uma opção: ");
      scanf("%i", &opc);
      return opc;
}

int main(){
      Lista A;
      int opc, valor;
      
      A.qtd = 0; // inicialização
      
      while(opc = menu()){
            switch(opc){
                  case 1:
                        printf("valor: ");
                        scanf("%i", &valor);
                        if (inserir_no_inicio(&A, valor)){
                              printf("elemento %i inserido.\n", valor);
                        }else{
                              printf("falha ao inserir o elemento %i.\n", valor);
                        }
                  break;
                  case 2:
                        mostrar_lista(&A);
                  break;
                  default:
                        printf("Opção inválida.\n");
            }
            getchar(); // captura o \n
            getchar(); // segura a tela
      }
      
}
