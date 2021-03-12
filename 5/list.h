#ifndef LIST_H_INCLUDED 
#define LIST_H_INCLUDED

typedef int TElement;
typedef struct Nodo{
    TElement info;
    struct Nodo *next;
}TNodo;
typedef struct{
    TNodo *first, *last;
    int size;
}TList;
typedef TList *list;

list creatList();
int insertStart(list,TElement);
int insertEnd(list,TElement);
int insertPosition(list,TElement,int);
int invertList(list);
int removeElement(list,TElement);
void deleteList(list);
int getElement(list,int,TElement*);
int getSize(list);

    

    
#endif