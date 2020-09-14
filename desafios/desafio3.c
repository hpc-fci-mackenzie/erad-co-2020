#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N (1<<30)

int main()
{
    struct timeval tempo_i, tempo_f;

    gettimeofday(&tempo_i, NULL);
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
    gettimeofday(&tempo_f, NULL);
    printf("Tempo de computacao : %f segundos\n",
        (double) (tempo_f.tv_usec - tempo_i.tv_usec) / 1000000 +
        (double) (tempo_f.tv_sec - tempo_i.tv_sec));

    gettimeofday(&tempo_i, NULL);
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
    gettimeofday(&tempo_f, NULL);

    printf("A soma dos elementos eh: %d\n", somas[0]);
    printf("Tempo de computacao : %f segundos\n",
        (double) (tempo_f.tv_usec - tempo_i.tv_usec) / 1000000 +
        (double) (tempo_f.tv_sec - tempo_i.tv_sec));

    free(somas);
    free(conjunto);
    return 0;
}
