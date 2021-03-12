#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "deposit.h"

void chega_deposito(TBox box, stack s1, stack s2, stack s3){
    TBox *boxMove;
    //Se o topo da pilha 1 For NULL, inserir a caixa na pilha 1
    if(s1->top == NULL){
        push(s1,box);
    }else{
        //Se a Caixa for menor ou igual ao tamanho da caixa no topo da lista 1
        if(box.weight <= s1->top->info.weight){
            push(s1,box);
        }else{
            //Percorre a lista 1 retirando as caixas até que chegue numa caixa de tamanho igual a caixa a ser
            //inserida, ou se chegar ao final da pilha, as caixas retiradas da pilha 1 são inseridas na sua
            //determinada pilha
            while(box.weight != s1->top->info.weight || s1->size != 0){
                pop(s1,boxMove);
                if(boxMove->weight == 5)
                    push(s2,*boxMove);
                else
                    if(boxMove->weight == 7)
                        push(s3,*boxMove);
            }
            push(s1,box);
            //Recoloca as caixas das pilhas auxiliares na pilha principal
            while(s2->size != 0){
                pop(s2,boxMove);
                push(s1,*boxMove);
            }
            while(s3->size != 0){
                pop(s3,boxMove);
                push(s1,*boxMove);
            }
        }
    }

}