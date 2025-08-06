#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dijkstra.h"

void Dijkstra(int num, int mat[num][num], int origem, int distancia[], int predecessores[]){
    bool vet[num];

    for(int i=0;i<num;i++){
        distancia[i] = 100000;
        predecessores[i] = -1;
        vet[i] = true;
    }

    distancia[origem-1]=0;

    for(int i=0;i<num-1;i++){
        int min = 100000;
        int u = -1;

        for(int j=0; j<num; j++){
            if(vet[j] && distancia[j] < min){
                min = distancia[j];
                u = j;
            }
        }

        if(u == -1){
            break;
        }

        vet[u] = false;

        for(int x=0; x<num; x++){
            if(mat[u][x] > 0 && vet[x]){
                if(distancia[x] > distancia[u] + mat[u][x]){
                    distancia[x] = distancia[u] + mat[u][x];
                    predecessores[x] = u;
                }
            }
        }
    }
}
