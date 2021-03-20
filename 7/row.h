#ifndef ROW_H_INCLUDED
#define ROW_H_INCLUDED

typedef int TPlate;
typedef struct{
    TPlate plate;
    int move;
}TElement;

typedef struct Nodo{
    TElement info;
    struct Nodo *next;
}TNodo;

typedef struct{
    TNodo *first, *last;
    int size;
}TRow;
typedef TRow *row;

row createRow();
void endRow(row);
int insertRow(row,TElement);
int removeRow(row,TElement*);
int fullRow(row);
int emptyRow(row);
int sizeRow(row);

#endif