#include <stdio.h>
#include "list.h"

list creatList(){
    list l = (list)malloc(sizeof(TList));
    if(l){
        l->size = 0;
        l->first = NULL;
        l->last = NULL;
    }
    return l;
}   

int insertStart(list l, TElement e){
    TNodo *p;
    p = (TNodo*)malloc(sizeof(TNodo));
    if(p){
        p->info = e;
        p->next = l->first;
        l->first = p;
        if(l->size == 0)
            l->last = p;
        l->size++;
        return 1;
    }else  
        return 0;
}

int insertEnd(list l, TElement e){
    TNodo *p;
    p = (TNodo*)malloc(sizeof(TNodo));
    if(p){
        p->info = e;
        p->next = NULL;
        if(l->first == NULL)
            l->first = p;
        else
            l->last->next = p;
        l->last = p;
        l->size++;
        return 1;
    }else
        return 0;
}

int insertPosition(list l, TElement e, int position){
    TNodo *p, *pAux, *ant;
    int i;

    if(position == 1)
        return insertStart(l,e);
    else
        if(position == l->size+1)
            return insertEnd(l,e);
        else
            if(position < 1 || position > l->size+1)
                return 0;
            else{
                p = (TNodo*)malloc(sizeof(TNodo));
                if(!p)
                    return 0;
                p->info = e;
                pAux = l->first;
                for(i=1;i<position;i++){
                    ant = pAux;
                    pAux = pAux->next;
                }
                p->next = pAux;
                ant->next = p;
                l->size++;
            }
}

int invertList(list l){
    TNodo *anterio, *atual, *prox;
    int i;

    anterior = l->first;
    atual = anterior->next;
    prox = atual->next;
    for(i=0;i<(l->size-1);i++){
        atual->next = anterior;
        anterior = atual;
        atual = prox;
        prox = prox->next;
    }
    l->first->next = NULL;
    l->last = l->first;
    l->first = anterior;
   return 0;
}

int removeElement(list l, TElement e){
    TNodo *p, *ant;
    
    p = l->first;
    while(p){
        if(p->info == e){
            if(l->first == p)
                l->first = l->first->next;
            else
                if(l->last == p){
                    l->last = ant;
                    l->last->next = NULL;
                }else
                    ant->next = p->next;
                free(p);
                l->size--;
                return 1;
        }else{
            ant = p;
            p = ant->next;
        }
        
    }
}

void deleteList(list l){
    TNodo *p;
    while(l->first){
        p = l->first;
        l->first = l->first->next;
        free(p);
    }
    free(l);
}

int getElement(list l, int position, TElement *e){
    int i;
    TNodo *p;
    if(position < 1 || position > l->size)
        return 0;
    p = l->first;
    for(i=0;i<position;i++)
        p = p->next;
    *e = p->info;
    return 1;
}

int getSize(list l){
    return l->size;
}
