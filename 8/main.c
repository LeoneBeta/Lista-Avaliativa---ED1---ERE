/*Programa requerido para treinamento do uso de Ordenação Interna - Exercicio 6*/
/*Implemente o QuickSort, usando outro algoritmo de ordenação(por exemplo, o InsertSort), para pequenas partições
do vetor, de tamanho menor ou igual a m.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define M 100
#define T 1000

void insertSort(int *v, int n){
    int i,k,aux;
    for(i=1;i<n;i++){
        aux = v[i];
        k = i-1;
        while(k>=0 && v[k]>aux){
            v[k+1] = v[k];
            k--;
        }
        v[k+1] = aux;
    }
}

void partitions(int *v, int left, int right){
    int pivo, i, k , aux;

    pivo = v[(left+right)/2];
    i = left;
    k = right;
    do{
        while(v[i]<pivo)i++;
        while(v[k]>pivo)k++;
        if(i<=k){
            aux = v[i];
            v[i] = v[k];
            v[k] = aux;
            i++;
            k++;
        }
    }while(i<=k);
    if(i<=M)
        insertSort(v,M);
    if(k<=M)
        insertSort(v,M);
    if(left<k)
        partitions(v,left,k);
    if(i<right)
        partitions(v,i,right);
}

void quickSort(int*v, int n){
    partitions(v,0,n-1);
}

int start(){
    setlocale(LC_ALL,"portuguese");
    int *v, i;
    time_t inicio,fim;
    v = (int*)malloc(sizeof(int)*T);
    if(v){
        srand(time(NULL));
        for(i=0;i<T;i++)
            v[i] = rand();
        inicio = time(NULL);
        quickSort(v,T);
        fim = time(NULL);
        printf("\nTempo gasto: ",difftime(fim,inicio));
        free(v);
    }else
        printf("\nErro na alocação do Vetor");

    return 0;
}

int main(){
    return start();
}