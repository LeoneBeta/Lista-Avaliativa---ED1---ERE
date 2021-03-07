/*Programa requerido para treinamento do uso de Recursão - Exercicio 13*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int sumElements(int **mat, int sum, int i, int j){

    sum = mat[i][j];

    if(i<4){
            return sumElements(*mat,sum,i+1,j+1);
    }else
        if(j<5)
            return sumElements(*mat,sum,i+1,j+1);
        else
            return 0;
    return 0;
}

int start(){
    int matriz[4][5], **mat;
    int i,j, result, sum;

    mat = &matriz;

    //Preenchendo a matriz
    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
            matriz[i][j] = j;

    sum = 0;
    i = 0;
    j = 0;
    result = sumElements(*mat,sum,i,j);

    printf("\nResultado: %d",result);

    return 0;
}

int main(){
    setlocale(LC_ALL,"portuguese");
    return start();
}