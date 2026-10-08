#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *next;
    struct no *prev;
}No;

int main(){
    No *head = NULL;
    No descript;
    int vlr;
    
    scanf("%i", &vlr);
    head = (No *)malloc(sizeof(No));
    head->dado = vlr;
    head->next = NULL;
    head->prev = NULL;

    descript.prev = head;
    descript.next = head;
    descript.dado = 1;
    
    scanf("%i", &vlr);
    No *newElement = (No *)malloc(sizeof(No));
    newElement->dado = vlr;
    newElement->prev = head;
    newElement->next = NULL;
    head->next = newElement;
    //free(newElement);

    descript.prev = head;
    descript.dado++;

    printf("1 Dado inserido: %i\n", newElement->prev->dado);
    printf("2 Dado inserido: %i\n", head->next->dado);
    printf("Quantidade de dados: %i\n", descript.dado);
}