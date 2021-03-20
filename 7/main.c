/*Programa requerido para treinamento do uso de Fila - Exercicio 10*/
/*Considere um estacionamento com capacidade infinita . Os carros chegam pelo sul do estacionamento e saem pelo 
norte. Se um cliente quer retirar um carro que não está próximo do extremo norte, todos os carros impedindo sua
passagem são retirados, o cliente retira seu carro e os outros carros são recolocados na mesma ordem que estavam
originalmente. Sempre que um carro sai, todos os carros do sul são movidos para frente, de modo que as vagas fiquem
disponíveis sempre no extremo sul do estacionamento. Escreva um algoritmo que processa o fluxo de chegada/saída
deste estacionamento. Cada entrada para o algoritmo contém uma letra ’E’ para entrada ou ’S’ para saída, e o número
da placa do carro. O programa deve imprimir uma mensagem sempre que um carro chegar ou sair. Quando um carro sair
do estacionamento, a mensagem deverá incluir o número de vezes em que o carro foi manobrado para fora do estacionamento
para permitir que os outros carros saíssem.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "row.h"
#include "park.h"

void removeEnter(char string[]){
	int tamanho = strlen(string) - 1;
	if (string[tamanho] == '\n'){
		string[tamanho] = '\0';
	}else {
		while (getc(stdin) != '\n')
			continue;
	}
}

int start(){
    setlocale(LC_ALL,"portuguese");
    char close[2];


    do{
        setbuf(stdin,NULL);
        printf("~~~ Estacionamento ~~~");
        printf("~~~1 - Estacionar ~~~~");
        printf("~~~2 - Retirar ~~~~");
        printf("~~~~~~~~~~~~~~~~~ ~~~~");
        printf("~~~0 - Sair ~~~~");
        fgets(close,2,stdin);
        removeEnter(close);

        if(close[0] == 1) park();
        if(close[0] == 2) remove();

    }while(close[0] != 0);


    return 0;
}

int main(){
    return start();
}