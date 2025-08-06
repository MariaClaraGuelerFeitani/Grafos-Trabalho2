#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"
#include "dijkstra.h"

int main()
{
    int quantcidades=0;
    int quantestradas=0;

    FILE *arq = fopen("Teste1.txt", "r");

    fscanf(arq, "%d %d", &quantcidades, &quantestradas);

    int cidade1[quantestradas];
    int cidade2[quantestradas];
    int gasto[quantestradas];
    int i=0, j=0;

    for(i=0;i<quantestradas;i++){
        fscanf(arq, "%d", &cidade1[i]);
        fscanf(arq, "%d", &cidade2[i]);
        fscanf(arq, "%d", &gasto[i]);
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

    printf("Cidade atual: ");
    scanf("%d", &cidadeAtual);

    printf("Cidade destino: ");
    scanf("%d", &cidadeDestino);

    printf("Quantidade de cidades proibidas: ");
    scanf("%d", &quantCidadesProi);

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
