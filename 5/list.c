#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list creatList(){
    list l = (TList*)malloc(sizeof(TList));
    if(l){
        l->size = 0;
        l->first = NULL;
        l->last = NULL;
    }
    return l;
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

int invertList(list l){
    TNodo *previous, *current, *next;
    int i;

    previous = l->first;
    current = previous->next;
    next = current->next;
    l->first->next = NULL;
    for(i=0;i<(l->size-1);i++){
        current->next = previous;
        previous = current;
        current = next;
        if(next == NULL)
            break;
        next = next->next;
    }
    l->first->next = NULL;
    l->last = l->first;
    l->first = previous;
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
