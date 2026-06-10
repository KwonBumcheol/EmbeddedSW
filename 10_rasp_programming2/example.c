// gcc -O3 example.c -o example -fopenmp
// 스레드 개수 정하고 싶을 때 -> OMP_NUM_THREADS=4 ./example
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000

int main() {
    double *a = malloc(sizeof(double) * N);
    double sum = 0.0;

    for (int i = 0; i < N; i++)
        a[i] = 1.0;

    double start = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum) // for문 여러 스레드가 나눠서 실행 -> sum을 마지막에 합쳐줌
    for (int i = 0; i < N; i++)
        sum += a[i];

    double end = omp_get_wtime();

    printf("sum = %f\n", sum);
    printf("time = %f sec\n", end - start);

    free(a);
}