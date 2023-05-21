#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //usado para definir o INT_MAX

#include "./lib/dinamica.h"
#include "./lib/dinamica.c"

//lê os dados de arquivo e armazena na struct
void lerGrid(FILE *entrada, Grid_2 *move) {

        fscanf(entrada, "%d %d", &move->linha, &move->coluna);
    move->grid = malloc(move->linha * sizeof(int *));

        for (int i = 0; i < move->linha; i++) {
            move->grid[i] = malloc(move->coluna * sizeof(int));
        for (int j = 0; j < move->coluna; j++) {
            fscanf(entrada, "%d", &move->grid[i][j]);
        }
    }
}

int darEntrada(const char* nomeEntrada) {

    //Lê o arquivo de entrada fornecido pelo usuário
    FILE* entrada = fopen(nomeEntrada, "r");
    if (entrada == NULL) {
        printf("Erro ao abrir entrada.\n");
        return 1;
    }
    //Retorna um arquivo chamado saida
    FILE* saida = fopen("saida.txt", "w");

    //Quantidade de testes necessários
        int T;
        fscanf(entrada, "%d", &T);
    //Enquanto existir casos para serem testados, as funções serão chamadas
        while (T--) {
        Grid_2 move;
            lerGrid(entrada, &move); //Lê e armazena o Grid em move (que percorre o código)
            fprintf(saida, "%d\n", minimaEnergiaNecesseria(&move)); //calcula e retorna o minimo de energia necessário
            liberaGrid(&move); //Libera espaço alocado
    }
    //fecha os arquivos abertos
    fclose(entrada);
    fclose(saida);

    return 0; //programa executado com sucesso
}