#ifndef DFS_H
#define DFS_H

typedef struct {
    int destino;
    int peso;
} Aresta; // aresta e suas propriedades

typedef struct {
    Aresta *adjacencias;
    int numAdjacencias;
} Vertice; // vértice e suas propriedades

int R, C;
Vertice *grafo;
int **S;
int **visitado;


void adicionarAresta(int origem, int destino, int peso);
int dfs(int vertice, int energia);

#endif