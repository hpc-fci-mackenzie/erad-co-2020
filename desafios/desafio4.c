#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSOS (1<<30)

int main()
{
    double x, pi, soma = 0.0, passo;
    passo = 1.0 / (double)PASSOS;
    double *somas;
    somas = (double*)malloc(sizeof(double)*omp_get_max_threads());
    if(somas == NULL) {
        printf("Erro alocando memoria\n");
        return 1;
    }
#pragma omp parallel
{
    int id = omp_get_thread_num();
    int slot = PASSOS / omp_get_num_threads();
    int inicio = id * slot;
    int fim = inicio + slot;
    if(id == omp_get_num_threads()-1) {
        fim = PASSOS;
    }
    double soma_local = 0.0;
    for (int i = inicio; i < fim; i++) {
        x = (i + 0.5) * passo;
        soma_local += 4.0 / (1.0 + x * x);
    }
    somas[id] = soma_local;
}
    for(int i=0; i<omp_get_max_threads(); i++) {
        soma += somas[i];
    }
    pi = passo * soma;
    printf("PI:%.15lf\n", pi);
    free(somas);
}
