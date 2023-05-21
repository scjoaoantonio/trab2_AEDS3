#include <stdio.h>
#include <stdlib.h>

#include <sys/resource.h> // verificar uso do sistema
#include <sys/time.h> //funções de tempo e duração

//#include "./trash/estrategia1_antigo.c" // include estratégia 1 = Busca em Profundidade
#include "estrategia1.c" // include estratégia 1 = Busca em Profundidade
#include "estrategia2.c" // include estratégia 2 = Programação Dinâmica


int main(int argc, char **argv) {
    if (argc < 3) {
        printf("%s <estrategia> <input.txt>\n", argv[0]);
        return 1;
    }
    int estrategia = atoi(argv[1]);
    char *input_file = argv[2];
    if (estrategia == 1) {
        // enviar entrada pra função do algoritmo 1 (Busca em Profundidade)
        buscaemprofundidade(input_file);
    } else if (estrategia == 2) {
        // enviar entrada pra função do algoritmo 2 (Programação Dinâmica)
        darEntrada(input_file);
    } else {
        printf("Erro: Digite 1 para executar busca em profundidade ou 2 para executar programação dinâmica.\n");
    }

    //Retorna um arquivo chamado saida
    FILE* saida = fopen("saida.txt", "a");

    // Tempo decorrido (Tempo: segundos.microsegundos)
    struct timeval tempo;
    gettimeofday(&tempo, NULL);
    fprintf(saida, "\nTempo até hoje: %ld.%lds\n", tempo.tv_sec, tempo.tv_usec);
    
    // calcula o tempo de uso da CPU
    struct rusage usage;
    getrusage (RUSAGE_SELF, &usage);
    fprintf (saida, "\nTempo de uso do usuário: %ld.%05lds\n", usage.ru_utime.tv_sec,
        usage.ru_utime.tv_usec);
    fprintf (saida, "\nTempo de uso do sistema: %ld.%05lds\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    
    return 0;
}