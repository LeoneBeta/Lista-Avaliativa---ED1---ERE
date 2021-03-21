#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct{
    int weight;
}TBox;

typedef struct Nodo{
    TBox info;
    struct Nodo *next;
}TNodo;

typedef struct{
    TNodo *top;
    int size;
}TStack;
typedef TStack *stack;

stack createStack();
void endStack(stack);
int push(stack,TBox);
int pop(stack,TBox*);
int fullStack(stack);
int emptyStack(stack);
int sizeStack(stack);


#endif