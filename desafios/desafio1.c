#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    // Inicia o conjunto com as chaves unicas
    for(int i=0; i<N; i++) {
        conjunto[i] = i;
    }

    // "esconde" o numero aleatoriamente
    srand(time(NULL));
    int esconde = rand() % N;
    int numero = conjunto[0];
    conjunto[0] = conjunto[esconde];
    conjunto[esconde] = numero;

#pragma omp parallel
{
    int id = omp_get_thread_num();
    int slot = N / omp_get_num_threads();
    int inicio = id * slot;
    int fim = inicio + slot;
    for(int i=inicio; i<fim; i++) {
        if(conjunto[i] == numero) {
            printf("Encontrei com a thread %d na posicao %d\n,", id, i);
        }
    }
}
    free(conjunto);
    return 0;
}
