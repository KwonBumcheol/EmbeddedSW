// 1번 C 코드

#include <stdio.h>
#include <math.h>

double integrate(double a, double b, int n) {
    double sum = 0, dx = (b - a) / n;
    
    for(int i = 0; i < n; i++) {
        sum += sin((a + i) * dx);
    }

    return sum * dx;
}

int main() {
    printf("%f\n", integrate(0, 3.141592, 100000));
    return 0;
}