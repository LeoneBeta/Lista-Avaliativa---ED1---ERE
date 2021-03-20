#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list creatList(){
    list l = (list)malloc(sizeof(TList));
    if(l){
        l->size = 0;
        l->first = NULL;
        l->last = NULL;
        l->current = NULL;
    }
}
/*
listDrum creatListDrum(){
    listDrum l = (listDrum)malloc(sizeof(listDrum));
    if(l){
        l->size = 0;
        l->first = NULL;
        l->last = NULL;
        l->current = NULL;
    }
}
*/
int insertStart(list l, TElement e){
    TNodo *n;
    n = (TNodo*)malloc(sizeof(TNodo));
    if(n){
        n->info = e;
        n->next = l->first;
        n->prior = l->last;
        if(l->first)
            l->first->prior = n;
        else
            l->last = n;
        l->first = n;
        l->size++;
        return 1;
    }else
        return 0;
}
/*
int insertStartDrum(listDrum l, TElementDrum e){
    TNodoDrum *n;
    n = (TNodoDrum*)malloc(sizeof(TNodoDrum));
    if(n){
        n->info = e;
        n->next = l->first;
        n->prior = l->last;
        if(l->first)
            l->first->prior = n;
        else
            l->last = n;
        l->first = n;
        l->size++;
        return 1;
    }else
        return 0;
}
*/
int insertEnd(list l,TElement e){
    TNodo *n;
    if(l->first == NULL)
        return insertStart(l,e);

    n = (TNodo*)malloc(sizeof(TNodo));
    if(n){
        n->info = e;
        n->next = l->first;
        n->prior = l->last;
        l->last->next = n;
        l->last = n;
        l->size++;
        return 1;
    }else
        return 0;
}
/*
int insertEndDrum(listDrum l,TElementDrum e){
    TNodoDrum *n;
    if(l->first == NULL)
        return insertStartDrum(l,e);

    n = (TNodoDrum*)malloc(sizeof(TNodoDrum));
    if(n){
        n->info = e;
        n->next = l->first;
        n->prior = l->last;
        l->last->next = n;
        l->last = n;
        l->size++;
        return 1;
    }else
        return 0;
}
*/
int removeElement(list l, TKey key){
    TNodo *n;
    n = l->first;

    while(n){
        if(n->info.key == key){
            if(l->size == 1){
                l->first = NULL;
                l->last = NULL;
            }else
                if(n == l->first){ 
                    l->first = l->first->next;
                    l->first->prior = NULL;
                }else
                    if(n == l->last){
                        l->last = l->last->prior;
                        l->last->next = NULL;
                    }else{
                        n->prior->next = n->next;
                        n->next->prior = n->prior;
                    }
                    free(n);
                    return 1;
        }else{
            n = n->next;
        }
    }
}

void deleteList(list l){
    TNodo *n;
    while(l->first){
        n = l->first;
        l->first = l->first->next;
        free(n);
    }
    free(l);
}
/*
void deleteListDrum(listDrum l){
    TNodoDrum *n;
    while(l->first){
        n = l->first;
        l->first = l->first->next;
        free(n);
    }
    free(l);
}
*/
int setCurrent(list l, int position){
    int i;
    if(position < 1 || position > l->size)
        return 0;

    l->current = l->first;
    for(i=1;i<position;i++)
        l->current = l->current->next;
    return 1;
}
/*
int setCurrentDrum(listDrum l, int position){
    int i;
    if(position < 1 || position > l->size)
        return 0;

    l->current = l->first;
    for(i=1;i<position;i++)
        l->current = l->current->next;
    return 1;
}
*/