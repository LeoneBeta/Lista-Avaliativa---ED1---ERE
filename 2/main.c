/*Programa requerido para treinamento de alocação dinâmica - Exercicio 6*/
/*Construa um programa (main) que aloque em tempo de execução (dinamicamente) uma matriz de
ordem m x n (linha por coluna), usando 1+m chamadas a função malloc. Agora, aproveite este
programa para construir uma função que recebendo os parâmetros m e n aloque uma matriz de
ordem m x n e retorne um ponteiro para esta matriz alocada. Crie ainda uma função para liberar a
área de memória alocada pela matriz. Finalmente, crie um novo programa (main) que teste/use as
duas funções criadas acima.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Pequeno problema com ponteiro pra ponteiro, funções comentadas para concerto, programa funcional sem
//a utilização das mesmas
/*
void allocMatriz(int row, int col, int *mat){
    int i;
    mat = (int*)malloc(row*sizeof(int));

    for(i=0;i<row;i++)
        mat[i] = (int*)malloc(col*sizeof(int));
}

void clearMatriz(int row,int *mat){
    int i;
    for(i=0;i<row;i++)
        free(mat[i]);
    free(mat);
}
*/
int matriz(){
    int row, col, **mat, i,j;
    printf("\nQuantidade de Linhas na Matriz: ");
    scanf("%d",&row);
    printf("\nQuantidade de Colunas na Matriz: ");
    scanf("%d",&col);
    
    //Alocando a Matriz dinâmica
    //allocMatriz(row,col,*mat);
    *mat = (int*)malloc(row*sizeof(int));
    for(i=0;i<row;i++)
        mat[i] = (int*)malloc(col*sizeof(int));

    //Preenchendo a Matriz
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            mat[i][j] = j;

    //Printar os elementos da matriz
    for(i=0;i<row;i++){
        for(j=0;j<col;j++)
            printf("%d",mat[i][j]);
        printf("\n");
    }

    //Limpando a matriz
    //clearMatriz(row,*mat);
    for(i=0;i<row;i++)
        free(mat[i]);
    free(mat);

    return 0;
}

int main(){   
    setlocale(LC_ALL,"portuguese"); 
    return matriz();
}