#include "dfs.h"

// Função pra adicionar aresta no grafo
void adicionarAresta(int origem, int destino, int peso) {
    Aresta aresta;
    aresta.destino = destino;
    aresta.peso = peso;
    Vertice *vertice = &grafo[origem];
    vertice->adjacencias = realloc(vertice->adjacencias, (vertice->numAdjacencias + 1) * sizeof(Aresta)); // Realoca o vetor de adjacências para adicionar a nova aresta
    vertice->adjacencias[vertice->numAdjacencias] = aresta; // Adiciona a nova aresta no vetor de adjacencias
    vertice->numAdjacencias++;
}

// Função de busca em profundidade (DFS)
int dfs(int vertice, int energia) {
    if (energia <= 0) {
        return 0; // energia <= 0, retorna 0
    }
    if (visitado[vertice / C][vertice % C]) {
        return 0; // vértice visitado, retorna 0
    }
    visitado[vertice / C][vertice % C] = 1; // marca como vértice visitado
    if (vertice == R * C - 1) {
        return 1; // se for o destino final, retorna 1
    }
    for (int i = 0; i < grafo[vertice].numAdjacencias; i++) {
        Aresta aresta = grafo[vertice].adjacencias[i]; // passa pra próxima aresta
        if (dfs(aresta.destino, energia + aresta.peso)) {
            return 1; // se a chamada recursiva retornar 1 é porque achou o caminho, então retorna 1
        }
    }
    return 0; // se nenhum caminho válido for encontrado, retorna 0
}