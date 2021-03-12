/*Programa requrido para treinamento do uso de TAD = Exercicio 3*/
/*Implemente um TAD Hora para representar uma hora específica do dia, armazenando horas,
minutos e segundos como inteiros. As seguintes operações devem ser implementadas:
a. atribui: Para atribuir valores para os campos (garanta que o horário seja válido, atribuindo valor 0
para dados inválidos);
b. avancar: Para avançar no tempo (deste que no intervalo de um dia). Deve ser passado a
quantidade de segundos a ser acrescentado à data.
c. comparar: Retorna true se dois horários são iguais e false caso contrário;
d. imprimir: Para imprimir a hora no formato h:m:s.
Faça um programa para tstar o TAD.*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "TADHora.h"

int main(){
    setlocale(LC_ALL,"portuguese");
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