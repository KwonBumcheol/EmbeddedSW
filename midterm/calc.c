#include <stdio.h>

typedef int (*calcFuncPtr)(int);

int calc_1(int n) {
    return n * n;
}

int calc_2(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int calc_3(int n) {
    int sum = 0;
    for (int i = 1; i * 3 <= n; i++){
        sum += 1; 
    }
    return sum;
}

int calculator(int first, calcFuncPtr fp) {
    return fp(first);
}

int main() {
    while(1) {    
        calcFuncPtr calc = NULL;
        int num1, num2;
        int result = 0;
        
        printf("Enter your choice: 1 (제곱 :n^2), 2 (계승 :n!), 3 (n보다 작은 3의 배수의 개수), 0 (exit): ");
        scanf("%d", &num1);

        if (num1 == 0) {
            return 0;
            break;
        }

        printf("Enter the number: ");
        scanf("%d", &num2);

        if (num1 == 1) {
            calc = calc_1;
        } else if (num1 == 2) {
            calc = calc_2;
        } else if (num1 = 3) {
            calc = calc_3; 
        }

        result = calculator(num2, calc);

        printf("%d\n", result);
    }
    return 0;
}