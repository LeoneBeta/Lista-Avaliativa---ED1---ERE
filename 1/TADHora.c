#include <stdio.h>
#include <stdlib.h>
#include "TADHora.h"


int addTime(int hour, int minute, int second, THour *ptrTime){
    //Faz a validação dos dados fornecidos, caso inválico, atribui valor 0 a posição
    if(hour >= 0 && hour <= 12){
        if(minute >=0 && minute <=59){
            if(second >= 0 && second <= 59){
                ptrTime->hour = hour;
                ptrTime->minute = minute;
                ptrTime->second = second;
                return 1;
            }else{
                ptrTime->second = 0;
                return 1;
            }
        }else{
            ptrTime->minute = 0;
            return 1;
        }
    }else{
        ptrTime->hour = 0;
        return 1;
    }
}
int advanceTime(int seconds, THour *ptrTime){
    int advanceHours, advanceMinutes, advanceSeconds, day = 0;
    int x;

    //Faz a separação dos segundos fornecidos nas variaveis respectivas
    advanceHours = seconds / 3600;
    seconds %= 3600;
    advanceMinutes = seconds / 60;
    seconds %= 60;
    advanceSeconds = seconds;

    //Verificando se a soma dos segundos atuais e dos segundos adicionados ultrapassa 60 segundos
    //se sim, ele incrementa nos minutos a quantidade, e armazena nos segundos o resto, fazendo isso 
    //consecutivamente nos minutos e horas, armazenando cada 24 horas a mais na variavel dia;
    x = ptrTime->second + advanceSeconds;
    if(x >= 60){
        advanceMinutes += (x / 60);
        ptrTime->second = (x % 60);
    }else
        ptrTime->second += advanceSeconds;

    x = ptrTime->minute + advanceMinutes;

    if(x >= 60){
        advanceHours += (x / 60);
        ptrTime->minute = (x % 60);
    }else
        ptrTime->minute += advanceMinutes;

    if(advanceHours >= 24){
        day = advanceHours / 24;
        advanceHours %= 24;
        ptrTime->hour += advanceHours; 
    }else
        ptrTime->hour += advanceHours;

    return day;
}
void printTime(THour *ptrTime){
    printf("Horario: %d:%d:%d\n",ptrTime->hour,ptrTime->minute,ptrTime->second);
}