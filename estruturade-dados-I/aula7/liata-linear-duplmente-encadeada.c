#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
}No;

int inserir_no_inicio(No **c, int vlr){
      No *novo;
      novo = (No *)malloc(sizeof(No));
      if (novo == NULL){
            return 0;
      }
      novo->dado = vlr;
      novo->prox = NULL;
      
      if (*c == NULL){
            *c = novo;
      }else{
            novo->prox = *c;
            *c = novo;
      }
      return 1;
}

int inserir_no_fim(No **c, int vlr){
      No *novo;
      novo = (No *)malloc(sizeof(No));
      if (novo == NULL){
            return 0;
      }
      novo->dado = vlr;
      novo->prox = NULL;
      
      if (*c == NULL){
            *c = novo;
      }else{
            No *p;
            for(p=*c; p->prox!=NULL; p=p->prox);
            p->prox = novo;
      }
      return 1;
}

int remover_no_inicio(No **c){
      if (*c == NULL){
            return 0;
      }
      No *p;
      p = *c;
      *c = p->prox; // *c = (*c)->prox - sao comandos esquivalentes.
      // precisamos do parentese por ser um ponteiro duplo e o ponteiro ser resolvido primiero

      free(p);

      return 1;
}

void mostrar_lista(No **c){
      if (*c == NULL){ // Lista vazia.
            printf("Lista vazia.\n");
      }
      for (No *p=*c; p!=NULL; p=p->prox){
            printf("%i\n", p->dado);
      }
}

int menu(){
      int opc;
      system("clear");
      printf("[0] - Sair.\n");
      printf("[1] - Inserir no início.\n");
      printf("[2] - Mostrar lista.\n");
      printf("[3] - Inserir no fim.\n");
      printf("[4] - Remover no inicio.\n");
      
      printf("Escolha uma opção: ");
      scanf("%i", &opc);
      return opc;
}

int main(){
      No *cabeca=NULL;
      int opc, vlr;
      
      while(opc = menu()){
            switch(opc){
                  case 1:
                        printf("valor: ");
                        scanf("%i", &vlr);
                        if (inserir_no_inicio(&cabeca, vlr)){
                              printf("Elemento %i inserido.\n", vlr);
                        }else{
                              printf("Falha ao inserir o elemento %i.\n", vlr);
                        }
                  break;
                  case 2:
                        mostrar_lista(&cabeca);
                  break;
                  case 3:
                        printf("valor: ");
                        scanf("%i", &vlr);
                        if (inserir_no_fim(&cabeca, vlr)){
                              printf("Elemento %i inserido no fim.\n", vlr);
                        }else{
                              printf("Falha ao inserir o elemento %i.\n", vlr);
                        }
                  break;
                  case 4:
                        if (remover_no_inicio(&cabeca)){
                              printf("Elemento removido do inicio.\n");
                        }else{
                              printf("Falha ao remover.\n");
                        }
                  break;
                  default:
                        printf("Opção inválida.\n");
            }
            getchar();  //captura o enter do buffer
            getchar();  //aguarda o proximo enter para seguir
      }
}