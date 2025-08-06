#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

void GrafoMatriz(int num, int mat[num][num]);
void adicionarLigacao(int num, int mat[num][num], int v1, int v2, int custo);
void removerLigacao(int num, int mat[num][num], int proibido);
void imprimirGrafo(int num, int mat[num][num]);

#endif // GRAFO_H_INCLUDED
