#include <stdio.h>

typedef int (*calcFuncPtr)(int, int);

int calc_add(int a, int b) {
    return a + b;
}

int calc_sub(int a, int b) {
    return a - b;
}

int calc_mul(int a, int b) {
    return a * b;
}

int calc_div(int a, int b) {
    return a / b;
}

int calculator(int first, int second, calcFuncPtr fp) {
    return fp(first, second);
}

int main() {
    calcFuncPtr calc = NULL;
    int num1, num2;
    char op = 0;
    int result = 0;

    scanf("%d %c %d", &num1, &op, &num2);

    switch(op) {
        case '+': calc = calc_add; break;
        case '-': calc = calc_sub; break;
        case '*': calc = calc_mul; break;
        case '/': calc = calc_div; break;
        default: break;
    }

    result = calculator(num1, num2, calc);

    printf("result = %d\n", result);

    return 0;
}