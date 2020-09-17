#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSOS (1<<30)

int main()
{
    double x, pi, soma = 0.0, passo;
    passo = 1.0 / (double)PASSOS;
#pragma omp parallel default(none) shared(soma) firstprivate(passo) private(x)
{
#pragma omp for reduction(+:soma)
    for (int i = 0; i < PASSOS; i++) {
        x = (i + 0.5) * passo;
        soma += 4.0 / (1.0 + x * x);
    }
}
    pi = passo * soma;
    printf("PI:%.15lf\n", pi);
}
