#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define TAM 2000

double A1[TAM][TAM] = {0};
double A2[TAM][TAM] = {0};

double B[TAM][TAM];
double C[TAM][TAM];

int main()
{
    struct timeval tempo_i, tempo_f;

    gettimeofday(&tempo_i, NULL);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            B[i][j] = C[i][j] = i * TAM + j + 1;
        }
    }
    gettimeofday(&tempo_f, NULL);
    printf("Tempo de iniciacao : %lf segundos\n",
           (double)(tempo_f.tv_usec - tempo_i.tv_usec) / 1000000 +
               (double)(tempo_f.tv_sec - tempo_i.tv_sec));

    gettimeofday(&tempo_i, NULL);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            for (int k = 0; k < TAM; k++) {
                A1[i][j] += B[i][k] * C[k][j];
            }
        }
    }
    gettimeofday(&tempo_f, NULL);
    printf("Tempo de multiplicacao for_ijk : %lf segundos\n",
           (double)(tempo_f.tv_usec - tempo_i.tv_usec) / 1000000 +
               (double)(tempo_f.tv_sec - tempo_i.tv_sec));

    gettimeofday(&tempo_i, NULL);
    for (int i = 0; i < TAM; i++) {
        for (int k = 0; k < TAM; k++) {
            for (int j = 0; j < TAM; j++) {
                A2[i][j] += B[i][k] * C[k][j];
            }
        }
    }
    gettimeofday(&tempo_f, NULL);
    printf("Tempo de multiplicacao for_ikj : %lf segundos\n",
           (double)(tempo_f.tv_usec - tempo_i.tv_usec) / 1000000 +
               (double)(tempo_f.tv_sec - tempo_i.tv_sec));

    printf("A1_ijk[0][0] - A2_ikj[0][0] -> %.5lf = %.5lf -> %.5lf\n", A1[0][0], A2[0][0], fabs(A1[0][0] - A2[0][0]));

    return 0;
}
