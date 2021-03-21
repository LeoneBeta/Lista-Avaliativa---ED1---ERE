/*Programa requerido para treinamento do uso de Pilha - Exercicio 9*/
/*9) Uma empilhadeira carrega caixas de 7, 5 e 3 toneladas. Há trêspilhas p1, p2 e p3.
Apilha p1 é onde se encontram todas as caixas que chegam ao depósito. Com um detalhe:caixas maiores não podem
ser empilhadas sobre caixas menores. Implemente a função void chega_deposito(Caixa caixa, pilha p1, pilha p2,
pilha p3)que efetue o controle das caixas, de forma que caso uma caixa de maior peso do que uma que já está em
p1 deva ser empilhada então todas as caixas que estão em p1 são movidas para as pilhas auxiliares p2(contendo
somente caixas de 5 toneladas) e p3 (contendo somente caixas de 3 toneladas) até que se possa empilhar a nova
caixa. Depois, todas as caixas são movidas de volta para a pilhap1.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "stack.h"
#include "deposit.h"

int start(){
    setlocale(LC_ALL,"portuguese");
    TBox newBox, *box;
    TStack *s1, *s2, *s3, *aux;
    int option;

    s1 = createStack();
    s2 = createStack();
    s3 = createStack();

    if(!s1)
        printf("\nErro ao criar a Pilha 1");
    if(!s2)
        printf("\nErro ao criar a Pilha 2");
    if(!s3)
        printf("\nErro ao criar a Pilha 3");


    do{
        printf("\nDigite 0 para sair");
        printf("\nPeso da nova caixa: 3, 5 ou 7\n");
        scanf("%d",&option);

        if(option == 0)
            break;
        newBox.weight = option;

        chega_deposito(newBox,s1,s2,s3);

    }while (option != 0);

    do{
        pop(s1,box);
        printf("\n%d",box->weight);
    }while(s1->size != 0);
    return 0;
}

int main(){
    return start();
}