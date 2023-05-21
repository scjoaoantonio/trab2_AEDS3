#include <limits.h>
#include "dinamica.h"

//libera a memória alocada para o grid
void liberaGrid(Grid_2 *move) {
    for (int i = 0; i < move->linha; i++) {
        free(move->grid[i]);
    }
    free(move->grid);
}

//função pra achar o menor número entre A e B
int min(int a, int b) {
    int menor;
    if (a < b) {
        menor = a;
    } else {
        menor = b;
    }
    return menor;
}


int minimaEnergiaNecesseria(Grid_2 *move) {
 //retorna o menor valor entre a e b
    //Aloca um vetor int e inicializa com valor INT_MAX para minimizar os valores
    int **matriz = malloc(move->linha * sizeof(int *));
    for (int i = 0; i < move->linha; i++) {
        matriz[i] = malloc(move->coluna * sizeof(int));
        for (int j = 0; j < move->coluna; j++) {
            matriz[i][j] = INT_MAX;
        }
    }
    /*Atribui-se valor da última celula de matriz verificando o valor da última célula de grid
    se grid for > 0, matriz = 1, pois é o valor mínimo de energia possível (resultado que buscamos), se for menor que 1
    ele pegará o valor absoluto e adicionará +1, tendo assim a solução mínima.*/
    matriz[move->linha - 1][move->coluna - 1] = move->grid[move->linha - 1][move->coluna - 1] > 0 ? 1 : 
    abs(move->grid[move->linha - 1][move->coluna - 1]) + 1;

    //Função que calcula a energia mínima necessária, percorrendo "matriz" e armazenando soluções de subproblemas
    for (int i = move->linha - 1; i >= 0; i--) {
        for (int j = move->coluna - 1; j >= 0; j--) {
            /*Verifica qual a energia necessária para alcançar a matriz abaixo ou a direita
            sabendo que a energia mínima para alcançar a célula que ele está é o valor atual dela + a energia para
            alcaçar a celula a direita ou abaixo, isso é armazenado em minEnergia*/
            if (i + 1 < move->linha) {
                int minEnergia = matriz[i + 1][j] - move->grid[i][j];
                if (minEnergia <= 0) {
                    matriz[i][j] = min(matriz[i][j], 1);
                } else {
                    matriz[i][j] = min(matriz[i][j], minEnergia);
                }
            }
            if (j + 1 < move->coluna) {
                int minEnergia = matriz[i][j + 1] - move->grid[i][j];
                if (minEnergia <= 0) {
                    matriz[i][j] = min(matriz[i][j], 1);
                } else {
                    matriz[i][j] = min(matriz[i][j], minEnergia);
                }
            }
        }
    }
    //Insere o valor mínimo de energia necessário para retornar ao fim
    int resultado = matriz[0][0];
    //Libera a memória alocada nas linhas
    for (int i = 0; i < move->linha; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return resultado;
}