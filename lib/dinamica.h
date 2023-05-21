#ifndef ALGORITMO2_H
#define ALGORITMO2_H

#include <stdio.h> 

typedef struct {
    int linha;
    int coluna;
    int **grid; //matriz de inteiros
} Grid_2;

void liberaGrid(Grid_2 *move); //Libera memória alocada
int minimaEnergiaNecesseria(Grid_2 *move); //Calcula a energia inicial mínima necessária para resolver o problema com programação dinâmica
void lerGrid(FILE *entrada, Grid_2 *move); //Lê os dados e armazena na struct Grid
int darEntrada(const char* nomeEntrada); //Lê as entradas

#endif