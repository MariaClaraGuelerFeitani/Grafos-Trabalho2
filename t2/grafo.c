#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"

void GrafoMatriz(int num, int mat[num][num]){
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            mat[i][j]=0;
        }
    }
}

void adicionarLigacao(int num, int mat[num][num], int v1, int v2, int custo){
    mat[v1-1][v2-1] = custo;
    mat[v2-1][v1-1] = custo;
}

void removerLigacao(int num, int mat[num][num], int proibido){
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i == proibido-1 || j == proibido-1){
                mat[i][j]=0;
            }
        }
    }
}

void imprimirGrafo(int num, int mat[num][num]){
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
