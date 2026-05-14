#include <stdio.h>
#include <math.h>
#include <omp.h>

double integrate(double a, double b, int n) {
    double sum = 0, dx = (b - a) / n;
    
    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < n; i++) {
        double x = (a + i) * dx;
        sum += sin(x);
    }

    return sum * dx;
}

int main() {
    double start = omp_get_wtime();

    double result = integrate(0.0, 3.141592, 10000000);

    double end = omp_get_wtime();

    printf("result = %f\n", result);
    printf("time = %f sec\n", end - start);

    return 0;
}