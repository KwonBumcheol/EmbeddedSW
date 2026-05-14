#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000

int main() {
    double *a = malloc(sizeof(double) * N);
    double sum = 0.0;

    for (int i = 0; i < N; i++)
        a[i] = 1.0;
    
    double start = omp_get_wtime(); // 실행속도 측정

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += a[i];
    }

    double end = omp_get_wtime();

    printf("sum = %f\n", sum);
    printf("time = %f sec\n", end - start);

    free(a);
}