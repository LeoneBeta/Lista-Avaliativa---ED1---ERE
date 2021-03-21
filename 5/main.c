/*Programa requerido para treinamento do uso de Lista Encadeada - Exercicio 1.a*/
/*1.a Implemente uma função para inverter a ordem dos elementos de uma lista linear
realizando apenas a movimentação dos apontadores. */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "list.h"

int start(){
    setlocale(LC_ALL,"portugese");

    list l;
    l = creatList();
    TNodo *aux;

    TElement value;
    int qtde, i;

    printf("\nQuantidade de Elementos na Lista: ");
    scanf("%d",&qtde);

    printf("\nInsira os valores\n");
    for(i=0;i<qtde;i++){
        scanf("%d",&value);
        insertEnd(l,value);
    }

    aux = l->first;
    printf("\nValores Inseridos");
    for(i=1;i<=qtde;i++){
        printf("\n%d",aux->info);
        aux = aux->next;
    }

    invertList(l);

    aux = l->first;
    printf("\nValores Invertidos");
    for(i=0;i<qtde;i++){
        printf("\n%d",aux->info);
        aux = aux->next;
    }
    printf("\n");

    return 0;
}

int main(){
    return start();
}