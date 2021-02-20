/*Programa requrido para treinamento do uso de TAD*/

#include <stdio.h>
#include <stdlib.h>
#include "TADHora.h"

int main(){
    THour time;
    int hr, min, sec, advanceSec, day;
    
    system("clear");
    printf("\nPressione Enter após cada valor");
    printf("\nForneça o horário: hh:mm:ss");
    scanf("%d",&hr);
    scanf("%d",&min);
    scanf("%d",&sec);

    addTime(hr,min,sec,&time);

    system("clear");
    printf("\nHora Fornecida: ");
    printTime(&time);

    printf("\nAdiante no tempo");
    printf("\nQuantidade de segundos que deseja adiantar");
    scanf("%d",&advanceSec);

    system("clear");
    day = advanceTime(advanceSec,&time);
    printf("\nHorario após o avanço");
    printf("\nHorario: %d:%d:%d - %d Dias depois", time.hour, time.minute, time.second, day);
    printTime(&time);

    return 0;
}