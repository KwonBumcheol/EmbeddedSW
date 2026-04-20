#include <stdio.h>
#include <stdlib.h>

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

calcFuncPtr get_operator(char op) {
    switch(op) {
        case '+': return calc_add;
        case '-': return calc_sub;
        case '*': return calc_mul;
        case '/': return calc_div;
        default: return NULL;
    }
}

int calculator(int first, int second, calcFuncPtr fp) {
    return fp(first, second);
}

int main() {
    int num;
    int result = 0;   // +, -까지 끝난 누적 결과
    int term;         // 현재 곱셈/나눗셈 묶음
    char op;          // 새로 읽은 연산자
    char prev_op;     // 이전 연산자
    calcFuncPtr calc = NULL;

    printf("수식을 입력하시오 (예: 3 + 5 * 2 = ) : ");

    scanf("%d", &term);       // 첫 숫자 입력
    prev_op = '+';            // 처음 term은 result에 더해질 값이라고 생각

    while (1) {
        scanf(" %c", &op);    // 연산자 입력

        if (op == '=') {
            // 마지막 term을 result에 반영
            if (prev_op == '+')
                result = calculator(result, term, calc_add);
            else if (prev_op == '-')
                result = calculator(result, term, calc_sub);
            break;
        }

        scanf("%d", &num);    // 다음 숫자 입력

        if ((op == '/' || prev_op == '/') && num == 0) {
            printf("0으로 나눌 수 없습니다.\n");
            return 1;
        }

        if (prev_op == '*') {
            calc = get_operator('*');
            term = calculator(term, num, calc);
        }
        else if (prev_op == '/') {
            calc = get_operator('/');
            term = calculator(term, num, calc);
        }
        else if (prev_op == '+') {
            result = calculator(result, term, calc_add);
            term = num;
        }
        else if (prev_op == '-') {
            result = calculator(result, term, calc_sub);
            term = num;
        }
        else {
            printf("잘못된 수식입니다.\n");
            return 1;
        }

        prev_op = op;
    }

    printf("result = %d\n", result);

    return 0;
}