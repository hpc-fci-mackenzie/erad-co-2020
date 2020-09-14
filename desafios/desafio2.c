#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N (1<<16)

int main()
{
    // cria o conjunto de dados
    int *conjunto;
    conjunto = (int*) malloc(sizeof(int) * N);
    if(conjunto == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Inicia o conjunto com o numero 1
    for(int i=0; i<N; i++) {
        conjunto[i] = 1;
    }

    // cria o vetor de somas parciais
    int *somas;
    somas = (int*) malloc(sizeof(int) * omp_get_max_threads());
    if(somas == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

#pragma omp parallel
{
    int id = omp_get_thread_num();
    int slot = N / omp_get_num_threads();
    int inicio = id * slot;
    int fim = inicio + slot;
    somas[id] = 0;
    for(int i=inicio; i<fim; i++) {
        somas[id] += conjunto[i];
    }
}
    for(int i=1; i<omp_get_max_threads(); i++) {
        somas[0] += somas[i];
    }
    printf("A soma dos elementos eh: %d\n", somas[0]);

    free(somas);
    free(conjunto);
    return 0;
}
