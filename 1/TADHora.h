#ifndef TADHORA_H_INCLUDED
#define TADHORA_H_INCLUDED

typedef struct{
    int hour;
    int minute;
    int second;
}THour;

int addTime(int, int, int, THour *);
int advanceTime(int, THour *);
void printTime(THour *);

#endif