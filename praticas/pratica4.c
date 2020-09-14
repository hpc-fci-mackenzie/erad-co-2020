#include <omp.h>
#include <stdio.h>

int main()
{
#pragma omp parallel num_threads(4)
{
    int id = omp_get_thread_num();
    printf("Hello World: %d - Max: %d\n", id, omp_get_num_threads());
}

#pragma omp parallel num_threads(6)
{
    int id = omp_get_thread_num();
    printf("Hello World: %d - Max: %d\n", id, omp_get_num_threads());
}
    return 0;
}
