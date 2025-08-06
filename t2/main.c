#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"
#include "dijkstra.h"

int main()
{
    int quantcidades=0;
    int quantestradas=0;

    scanf("%d %d", &quantcidades, &quantestradas);

    int cidade1[quantestradas];
    int cidade2[quantestradas];
    int gasto[quantestradas];
    int i=0, j=0;

    for(i=0;i<quantestradas;i++){
        scanf("%d", &cidade1[i]);
        scanf("%d", &cidade2[i]);
        scanf("%d", &gasto[i]);
    }


    int matriz[quantcidades][quantcidades];

    GrafoMatriz(quantcidades, matriz);

    for(i=0;i<quantestradas;i++){
        adicionarLigacao(quantcidades, matriz, cidade1[i], cidade2[i], gasto[i]);
    }

    int cidadeAtual;
    int cidadeDestino;
    int quantCidadesProi;
    int distancia[quantcidades];
    int predecessores[quantcidades];

    scanf("%d %d %d", &cidadeAtual, &cidadeDestino, &quantCidadesProi);


    for(i=(quantcidades-quantCidadesProi);i<quantcidades;i++){
        if(cidadeAtual == i+1 || cidadeDestino == i+1){

        }
        else{
            removerLigacao(quantcidades, matriz, i+1);
        }
    }

    Dijkstra(quantcidades, matriz, cidadeAtual, distancia, predecessores);


    if(distancia[cidadeDestino-1]==100000){
        printf("Nao e possivel chegar a essa cidade!\n");
    }
    else{
        printf("Distancia: %d\n", distancia[cidadeDestino-1]);
    }


    return 0;
}
