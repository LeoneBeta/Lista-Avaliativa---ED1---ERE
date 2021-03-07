#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef int TKey;
typedef struct{
    TKey key;
    char name[20];
}TElement;

typedef struct Nodo{
    TElement info;
    struct Nodo *prior, *next;
}TNodo;

typedef struct{
    TNodo *first, *last, *current;
    int size;
}TList;

typedef TList *list;

typedef int TKeyDrum;
typedef struct{
    TKey key;
    int slot;
}TElementDrum;

typedef struct NodoDrum{
    TElementDrum info;
    struct NodoDrum *prior, *next;
}TNodoDrum;

typedef struct{
    TNodoDrum *first, *last, *current;
    int size;
}TListDrum;

typedef TListDrum *listDrum;

list creatList();
listDrum creatListDrum();
int insertStart(list,TElement);
int insertStartDrum(listDrum,TElementDrum);
int insertEnd(list,TElement);
int insertEndDrum(listDrum,TElementDrum);
int removeElement(list,TKey);
void deleteList(list);
void deleteListDrum(listDrum);
int setCurrent(list,int);
int setCurrentDrum(listDrum,int);


#endif