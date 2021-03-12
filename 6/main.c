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
    TBox newBox;
    stack *s1, *s2, *s3;

    s1 = creatStack();
    s2 = creatStack();
    s3 = creatStack();

    if(!s1)
        printf("\nErro ao criar a Pilha 1");
    if(!s2)
        printf("\nErro ao criar a Pilha 2");
    if(!s3)
        printf("\nErro ao criar a Pilha 3");

    printf("Peso da nova caixa: ");
    scanf("%d",&newBox.weight);

    chega_deposito(newBox,s1,s2,s3);
    return 0;
}

int main(){
    return start();
}