#include <stdio.h>
#include <stdlib.h>
#include "./lib/dfs.c"


int buscaemprofundidade(const char* nomeEntrada) {
    FILE* entrada = fopen(nomeEntrada, "r");
    if (entrada == NULL) {
        printf("Erro ao abrir entrada.\n");
        return 1;
    }
    FILE* saida = fopen("saida.txt", "w");

    int T;
    fscanf(entrada, "%d", &T);
    //Enquanto existir casos pra testar
    while (T--) {
        fscanf(entrada, "%d %d", &R, &C);

        // Aloca memória para o grid, o grafo e a variável visitado.
        S = (int **) malloc(R * sizeof(int *));
        grafo = (Vertice *) malloc(R * C * sizeof(Vertice));
        visitado = (int **) malloc(R * sizeof(int *));
        
        for (int i = 0; i < R; i++) {
            S[i] = (int *) malloc(C * sizeof(int));
            visitado[i] = (int *) calloc(C, sizeof(int));
        }
        // Lê o Grid
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                fscanf(entrada, "%d", &S[i][j]);
            }
        }
        // Cria as arestas do grafo
        for (int i = 0; i < R * C; i++) {
            grafo[i].adjacencias = NULL; //define adjacencias do grafo como nulo, ou seja, ainda não possui nenhum adjc
            grafo[i].numAdjacencias = 0; //define como zero pois não há adjacencias associadas ainda
        }
        // Percorrem as linhas e colunas do grafo
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int origem = i * C + j; //calcula o indice do vertice de origem
                if (i + 1 < R) { //verifica se ainda existem linhas 
                    int destino = (i + 1) * C + j;
                    int peso = S[i][j];
                    adicionarAresta(origem, destino, peso);
                }
                if (j + 1 < C) { //verifica se ainda existem colunas
                    int destino = i * C + (j + 1);
                    int peso = S[i][j];
                    adicionarAresta(origem, destino, peso); //adiciona uma aresta
                }
            }
        }
        // Roda a busca em profundidade
        int energia = 1; // energia inicial do harry
        while (!dfs(0, energia)) { // o loop aumenta a energia até que a função retornar true.
            energia++;
            // Reseta o array visitado.
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    visitado[i][j] = 0;
                }
            }
        }
        fprintf(saida, "%d\n", energia);
        // Libera memória
        for (int i = 0; i < R; i++) { //percorre todas as linhas
            free(S[i]);
            free(visitado[i]);
        }
        free(S);
        free(visitado);
        for (int i = 0; i < R * C; i++) { //percorre todos os vertices
            free(grafo[i].adjacencias);
        }
        free(grafo);
    }
        // Fecha o arquivo
        fclose(entrada);
        fclose(saida);

    return 0;
}