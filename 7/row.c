#include <stdio.h>
#include <stdlib.h>
#include "row.h"

row createRow(){
    row  r = (row)malloc(sizeof(TRow));
    if(r){
        r->first = NULL;
        r->last = NULL;
        r->size = 0;
    }
    return r;
}

void endRow(row r){
    TNodo *n;
    while(r->first){
        n = r->first;
        r->first = r->first->next;
        free(n);
    }
    free(r);
}

int insertRow(row r,TElement e){
    TNodo *n = (TNodo*)malloc(sizeof(TNodo));
    if(!n)
        return 0;
    n->next = NULL;
    n->info = e;
    if(r->first == NULL)
        r->first = n;
    else
        r->last->next = n;
    r->last = n;
    r->size++;
    return 1;
}

int removeRow(row r,TElement *e){
    TNodo *n;
    if(r->first == NULL)
        return 0;
    n = r->first;
    r->first = r->first->next;
    r->size--;
    *e = n->info;
    free(n);
    return 1;

}

int fullRow(row r){
    TNodo *n = (TNodo*)malloc(sizeof(TNodo));
    if(!n)
        return 1;
    free(n);
    return 0;
}

int emptyRow(row r){
    return r->size == 0;
}

int sizeRow(row r){
    return r->size;
}