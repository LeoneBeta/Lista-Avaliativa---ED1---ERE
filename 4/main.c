/*Programa requerido para treinamento do uso de Lista Encadeada - Exercicio 2*/
/*O Problema Josephus é um jogo de suicídio em massa que é realizado do seguinte
modo: n pessoas, numeradas de 1 a n, estão sentadas em uma mesa circular. Iniciando
da pessoa 1, um revolver contendo uma bala é passado entre elas. Após m passos, a
pessoa que está com a arma com a bala na agulha comete suicídio, o corpo é removido,
o ciclo de pessoas se fecha, e o jogo continua com a pessoa que está sentada após o
elemento que cometeu o suicídio. O último sobrevivente é aquele que permanecerá após
a morte dos demais.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "list.h"
#include "ProblemJosephus.h"

int start(){
    int players, i;
    char enter[3];

    list l;


    printf("\nNúmero de Jogadores: ");
    scanf("%d",&players);

    l = creatList();

    sitPlayers(l,players);
    printf("\nJogadores se sentam em volta da mesa");

    setbuf(stdin,NULL);
    printf("\nPressione Enter para começar");
    fgets(enter,3,stdin);
    removeEnter(enter);

    /*  FALHA DE SEGMENTAÇÃO NAS FUNÇÕES SETCURRENT*/

    game(l,players);

    return 0;
}

int main(){
    setlocale(LC_ALL,"portuguese");
    return start();
}